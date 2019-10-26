
CC=gcc
CFLAGS=-W -Wall -pedantic -ansi

XAINPUT=../../include
XA=XAINPUT=${XAINPUT} xa
FILE=file65
RELOC=reloc65

all: slipd

slipd: $(wildcard *.a65) sltcp.def
	# ${XA} -DKERNEL=61440 -R -bt 16384 -bz 128 -bb 8192 -bd 6144 \
	#	-G main.a65 -o slipd -l slipd.lab ;
	# ${XA} -R -DKERNEL=61440 -DSTDIOADDR=53248 main.a65 -o slipd -l slipd.lab ;
	${XA} -R -LOSA2KERNEL -LLIB6502 main.a65 -o slipd -l slipd.lab ;

fstcp: fstcp.c fstcp.h
	${CC} ${CFLAGS} fstcp.c -o fstcp
clean:
	rm -f slipd slipd.lab slip slip.o65 slip.lab fstcp


