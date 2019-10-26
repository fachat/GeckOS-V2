/****************************************************************************
   
    OS/A65 Version 1.3.13
    Multitasking Operating System for 6502 Computers

    Copyright (C) 1989-1997 Andre Fachat 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

****************************************************************************/

/*
 * This file is a server FSTCP filesystem implementation, to be
 * used with the FSTCP program on an OS/A65 computer. 
 *
 * usage: 
 *   fstcp [options] exported_directory
 *
 *   options:
 * 	-ro	export read-only
 */

#define	PORT	8090

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <sys/stat.h>
#include <dirent.h>

#include <netinet/in.h>
#include <netdb.h>

#include <time.h>

#include "oa1fs.h"
#include "fstcp.h"

#define	min(a,b)	(((a)<(b))?(a):(b))

typedef struct {
	int	state;
	FILE	*fp;
	DIR 	*dp;
} File;

File files[MAXFILES];

void usage(void) {
	printf("Usage: fstcp [options] exported_directory hostname_to_export_to\n"
		" options=\n"
		"   -ro		export read-only\n"
	);
	exit(1);
}

void do_cmd(char *buf, int fd) {
	int tfd, cmd, len;
	char retbuf[200];
	char *nm;
	FILE *fp;
	DIR *dp;
	int n;
	struct dirent *de;
	struct stat sbuf;
	struct tm *tp;

	cmd = buf[FSP_CMD];
	tfd = buf[FSP_FD];
	len = buf[FSP_LEN];
	fp = files[tfd].fp;
	dp = files[tfd].dp;

	printf("got cmd=%d, fd=%d, name=%s\n",cmd,tfd,
			cmd<FS_ASSIGN?buf+FSP_DATA:"null");

	retbuf[FSP_CMD] = FS_REPLY;
	retbuf[FSP_LEN] = 4;
	retbuf[FSP_FD] = tfd;
	retbuf[FSP_DATA] = -22;

	switch(cmd) {
	case FS_OPEN_WR:
		/* no directory separators - security rules! */
		nm = buf+FSP_DATA;
		if(*nm=='/') n++;
		if(strchr(nm, '/')) break;

		fp = fopen(nm, "wb");
printf("OPEN_WD(%s)=%p\n",buf+FSP_DATA,fp);
		if(fp) {
		  files[tfd].fp = fp;
		  files[tfd].dp = NULL;
		  retbuf[FSP_DATA] = 0;
		}
		break;
	case FS_OPEN_DR:
		dp = opendir("." /*buf+FSP_DATA*/);
printf("OPEN_DR(%s)=%p\n",buf+FSP_DATA,dp);
		if(dp) {
		  files[tfd].fp = NULL;
		  files[tfd].dp = dp;
		  retbuf[FSP_DATA] = 0;
		}
		break;
	case FS_OPEN_RD:
		/* no directory separators - security rules! */
		if(strchr(buf+FSP_DATA, '/')) break;

		fp = fopen(buf+FSP_DATA, "rb");
printf("OPEN_RD(%s)=%p\n",buf+FSP_DATA,fp);
		if(fp) {
		  files[tfd].fp = fp;
		  files[tfd].dp = NULL;
		  retbuf[FSP_DATA] = 0;
		}
		break;
	case FS_READ:
		if(dp) {
		  de = readdir(dp);
		  if(!de) {
		    closedir(dp);
		    files[tfd].dp = NULL;
		    retbuf[FSP_CMD] = FS_EOF;
		    retbuf[FSP_LEN] = 3;
		    break;
		  }
		  n = stat(de->d_name, &sbuf);
		  /* TODO: check return value */
 		  retbuf[FSP_DATA+FS_DIR_LEN] = sbuf.st_size & 255;
 		  retbuf[FSP_DATA+FS_DIR_LEN+1] = (sbuf.st_size >> 8) & 255;
 		  retbuf[FSP_DATA+FS_DIR_LEN+2] = (sbuf.st_size >> 16) & 255;
 		  retbuf[FSP_DATA+FS_DIR_LEN+3] = (sbuf.st_size >> 24) & 255;

		  tp = localtime(&sbuf.st_mtime);
 		  retbuf[FSP_DATA+FS_DIR_YEAR]  = tp->tm_year;
 		  retbuf[FSP_DATA+FS_DIR_MONTH] = tp->tm_mon;
 		  retbuf[FSP_DATA+FS_DIR_DAY]   = tp->tm_mday;
 		  retbuf[FSP_DATA+FS_DIR_HOUR]  = tp->tm_hour;
 		  retbuf[FSP_DATA+FS_DIR_MIN]   = tp->tm_min;
 		  retbuf[FSP_DATA+FS_DIR_SEC]   = tp->tm_sec;

 		  retbuf[FSP_DATA+FS_DIR_MODE]  = S_ISDIR(sbuf.st_mode) ? 
						FS_DIR_MOD_DIR : FS_DIR_MOD_FIL;
		  strncpy(retbuf+FSP_DATA+FS_DIR_NAME, de->d_name,
			min(strlen(de->d_name)+1, 199-FSP_DATA-FS_DIR_NAME));
		  retbuf[199]=0;
		  retbuf[FSP_LEN] = FSP_DATA+FS_DIR_NAME+
				strlen(retbuf+FSP_DATA+FS_DIR_NAME) + 1;
		  retbuf[FSP_CMD] = FS_WRITE;
		} else
		if(fp) {
		  n = fread(retbuf+FSP_DATA, 1, 64, fp);
		  retbuf[FSP_LEN] = n+FSP_DATA;
		  if(n<64) {
		    retbuf[FSP_CMD] = FS_EOF;
		    fclose(fp);
		    files[tfd].fp = NULL;
		  } else {
		    retbuf[FSP_CMD] = FS_WRITE;
		  }
		}
		break;
	case FS_WRITE:
	case FS_EOF:
		if(fp) {
		  n = fwrite(buf+FSP_DATA, 1, len-FSP_DATA, fp);
		  retbuf[FSP_DATA] = 0;
		  if(cmd == FS_EOF) {
		    fclose(fp);
		    files[tfd].fp = NULL;
		  }
		}
		break;
	case FS_CLOSE:
		if(fp) fclose(fp);
		if(dp) closedir(dp);
		files[tfd].fp = NULL;
		files[tfd].dp = NULL;
		retbuf[FSP_DATA] = 0;
		break;
	}


	write(fd, retbuf, retbuf[FSP_LEN]);
	printf("write %02x %02x %02x %02x\n", retbuf[0], retbuf[1],
			retbuf[2], retbuf[3]);
}

int main(int argc, char *argv[]) {
	int sock, err;
	struct sockaddr_in serv_addr, client_addr, host_addr;
	int client_addr_len;
	int port=PORT;
	int fd;
	int i, ro=0;
	char *dir, *hname;
	struct hostent *he;

	i=1;
	while(i<argc && argv[i][0]=='-') {
	  switch(argv[i][1]) {
	    case '?':
		usage();
		break;
	    case 'r':
		if(argv[i][2]=='o') {
		  ro=1;
		}
		break;
	  }
	  i++;
	}

	if(i!=argc-2) {
	  usage();
	}

	dir = argv[i++];
	printf("dir=%s\n",dir);

	if(chdir(dir)<0) { 
	  fprintf(stderr, "Couldn't change to directory %s, errno=%d (%s)\n",
			dir, errno, strerror(errno));
	  exit(1);
	}

	hname= argv[i++];
	printf("hostname=%s\n",hname);

	he = gethostbyname(hname);
	if(!he) {
	  fprintf(stderr, "Could not get hostinfo for %s, h_errno=%d\n",
			hname, h_errno);
	  exit(2);
	}
	printf("official name is %s\n",he->h_name);
	if(he->h_addrtype != AF_INET) {
	  fprintf(stderr, "Address type for %s not Internet!\n", hname);
	  exit(2);
	}

	memcpy((char*)&host_addr.sin_addr.s_addr, he->h_addr_list[0], 
							he->h_length);

/*	host_addr.sin_addr.s_addr = ntohl(*(long*)(he->h_addr_list[0]));*/

	printf("ok, want connection to %08x\n", host_addr.sin_addr.s_addr);

	for(i=0;i<MAXFILES;i++) {
	  files[i].state = F_FREE;
	}

	printf("port=%d\n",port);
	
	sock = socket(AF_INET, SOCK_STREAM, 0);

	printf("sock=%d\n",sock);

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(port);
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

	err = bind(sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr));
	if(err<0) {
	  fprintf(stderr, "Could not bind (errno=%d, %s)!\n", errno,
							strerror(errno));
	  return 2;
	}

	err = listen(sock, 1);
	if(err<0) {
	  fprintf(stderr, "Could not listen!\n");
	  return 2;
	}

	while(1) {
	  client_addr_len = sizeof(client_addr);
	  fd = accept(sock,(struct sockaddr*)&client_addr, &client_addr_len);
	  if(fd<0) {
	    fprintf(stderr, "Could not accept, errno=%d (%s)!\n",
						errno, strerror(errno));
	    return 2;
	  }
	  printf("accept request from %08x, port %d, clen=%d, inal=%d\n", 
			client_addr.sin_addr.s_addr, client_addr.sin_port,
			client_addr_len, sizeof(struct in_addr));

	  if(!memcmp(&client_addr.sin_addr.s_addr, 
			&host_addr.sin_addr.s_addr, sizeof(struct in_addr))) {
	    char buf[8192];
	    int wrp,rdp, plen;
	    int n;

	    close(sock);

	    printf("ok, got connection to %04x, port %d\n", 
			client_addr.sin_addr.s_addr, client_addr.sin_port);

	    wrp = rdp = 0;

	    while((n=read(fd, buf+wrp, 8192-wrp))!=0) {
printf("read %d bytes: ",n);
for(i=0;i<n;i++) printf("%02x ",buf[wrp+i]); printf("\n");

	      if(n<0) {
		fprintf(stderr,"fstcp: read error %d (%s)\n",errno,strerror(errno));
		break;
	      }
	      wrp+=n;
	      if(rdp && (wrp==8192 || rdp==wrp)) {
		if(rdp!=wrp) {
		  memmove(buf, buf+rdp, wrp-rdp);
		}
		wrp -= rdp;
		rdp = 0;
	      }
printf("wrp=%d, rdp=%d, FSP_LEN=%d\n",wrp,rdp,FSP_LEN);
	      while(wrp-rdp > FSP_LEN) {
		plen = buf[rdp+FSP_LEN];
printf("wrp-rdp=%d, plen=%d\n",wrp-rdp,plen);
		if(wrp-rdp >= plen) {
		  do_cmd(buf+rdp, fd);
		  rdp +=plen;
		} else {
		  break;
		}
	      }
	    }
	    exit(0);
	  } else {
	    printf("connect trial rejected!\n");
	    close(fd);
	  }
	}
	
	close(sock);
	return 0;	
}

