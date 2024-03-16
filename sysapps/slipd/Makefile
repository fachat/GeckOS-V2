
CC=gcc
CFLAGS=-W -Wall -pedantic -ansi

XAINPUT=../../include
XA=XAINPUT=${XAINPUT} xa -k
FILE=file65
RELOC=reloc65

all: slipd slipmind slipfsd slipwwwd

slipd: $(wildcard *.a65) sltcp.def
	# full server, except for FSTCP
	${XA} -R -LOSA2KERNEL -LLIB6502 main.a65 -o slipd -l slipd.lab 

slipmind: $(wildcard *.a65) sltcp.def
	# can still ping, but only lib6502 sockets
	${XA} -R -LOSA2KERNEL -LLIB6502 -DNO_WWW -DNO_FSTCP -DNO_TEST -DNO_RSH main.a65 -o slipmind -l slipmind.lab 

slipfsd: $(wildcard *.a65) sltcp.def
	# can still ping, only TCP/IP fileserver
	${XA} -R -LOSA2KERNEL -LLIB6502 -DNO_WWW -DNO_TEST -DNO_RSH -DNO_LIBIP main.a65 -o slipfsd -l slipfsd.lab 

slipwwwd: $(wildcard *.a65) sltcp.def
	# can still ping, only web server
	${XA} -R -LOSA2KERNEL -LLIB6502 -DNO_FSTCP -DNO_TEST -DNO_RSH -DNO_LIBIP main.a65 -o slipwwwd -l slipwwwd.lab 

fstcp: fstcp.c fstcp.h
	${CC} ${CFLAGS} fstcp.c -o fstcp
clean:
	rm -f slip*d slip*d.lab fstcp


