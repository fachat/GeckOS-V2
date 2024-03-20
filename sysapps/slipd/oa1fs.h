/****************************************************************************
   
    OS/A65 Version 1.4.0
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


#define   DIRSIGN        "/"       /* directory separator 		*/

/* commands to the filesystem						*/

#define   FS_OPEN_RD     1         /* open file for read		*/
#define   FS_OPEN_WR     2         /* open file for write		*/
#define   FS_OPEN_RW     3         /* open file for read and write 	*/
#define   FS_OPEN_OW     4         /* open file for overwrite		*/
#define   FS_OPEN_AP     5         /* open file for append		*/
#define   FS_OPEN_DR     6         /* open directory for read		*/
#define   FS_RENAME      7         /* rename file			*/
#define   FS_DELETE      8         /* delete file			*/
#define   FS_FORMAT      9         /* format disk			*/
#define   FS_CHKDSK      10        /* check disk			*/
#define   FS_CLOSE       11        /* close file (only for read/write)	*/
#define   FS_RMDIR       12        /* remove subdirectory		*/
#define   FS_MKDIR       13        /* create subdirectory		*/
#define   FS_CHDIR       14        /* change directory			*/
#define   FS_ASSIGN      15        /* ----                              */

/* 
 * non-overlapping net server commands follow 
 * by not overlapping them with filesytem commands, one process can
 * register as fs _and_ net server
 */

#define	  FS_OPEN_TCP	 32	   /* ----				*/

/*
 * user-defined codes after that
 */
#define	  FS_LASTCODE	 64 

/************************************************************************/

/* struct to be sent with FS_OPEN_*					*/

#define   FS_OPEN_DRV    0         /* drive = FM_OPEN_DRV               */
#define   FS_OPEN_STR    1         /* data stream			*/
#define   FS_OPEN_PFAD   2         /* ----                              */
#define   FS_OPEN_NAME   3         /* filename, ended with null byte	*/

/* struct that is returned						*/

#define   FS_X_ERR       0         /* error number, also in AC		*/
#define   FS_X_ENV       1         /* task number of the filesystem	*/
#define   FS_X_FIL       2         /* file handle (read/write only)	*/
#define   FS_X_SLEN      3         /* length of struct			*/

/* struct of a dir entry in a directory file				*/

#define   FS_DIR_LEN     0    /* length in bytes, 4 bytes, lo first	*/
#define   FS_DIR_YEAR    4    /* year minus 1900			*/
#define   FS_DIR_MONTH   5    /* month					*/
#define   FS_DIR_DAY     6    /* day					*/
#define   FS_DIR_HOUR    7    /* hour					*/
#define   FS_DIR_MIN     8    /* minute					*/
#define   FS_DIR_SEC     9    /* second of last change			*/
#define   FS_DIR_MODE    10   /* kind of dir entry			*/
#define   FS_DIR_NAME    11   /* start of name, ended with null byte	*/

/* kind of directory entry						*/

#define   FS_DIR_MOD_FIL 0    /* file					*/
#define   FS_DIR_MOD_NAM 1    /* disk name				*/
#define   FS_DIR_MOD_FRE 2    /* disk free bytes in FS_DIR_LEN		*/
#define   FS_DIR_MOD_DIR 3    /* subdirectory				*/

/* struct to be sent except for FS_OPEN_*				*/
/* only FS_CMD_NAME (must be ==FS_OPEN_NAME for fstcp) used		*/

#define   FS_CMD_DRV     0
#define   FS_CMD_PFAD    1
#define   FS_CMD_FIL     2
#define   FS_CMD_NAME    3    /* after nullbyte of the first filename	*/
			      /* comes the second filename for RENAME	*/

