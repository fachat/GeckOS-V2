
all: lib.bin kern.bin rom.bin

TRG=boot/rom

XAINPUT=../../include,..,../..
XA=xa
FILE=file65
RELOC=reloc65

lib lib.bin: lib.a65
	# start binary at 910+2 = $0390
	${XA} -I../../include -I../.. -DOSA2KERNEL=61440 -R -bt 910 -bd 768 -bz 8 -bb 65535 $< -o lib.o65 -l lib.lab;
	${FILE} lib.o65
	${FILE} -V lib.o65 | grep LIB6502
	${RELOC} -xt -o lib.bin lib.o65; 

kern kern.bin: kern.a65
	${XA} -I../../include -I../.. -R -bt 61438 -bd 59648 -bz 32 -bb 58368 $< -o kern.o65 -l kern.lab;
	${FILE} kern.o65
	${FILE} -V kern.o65 | grep OSA2KERNEL
	${RELOC} -xt -o kern.bin kern.o65

rom rom.bin: rom.a65
	${XA} -I../../include -I../.. -R -DLIB6502=7103 -DOSA2KERNEL=61440 -bt 43006 -bd 56320 -bz 52 -bb 56960 $< -o rom.o65 -l rom.lab;
	${FILE} rom.o65
	${RELOC} -xt -o rom.bin rom.o65

clean:
	rm -f ${TRG} rom.lab rom.o65 boot.tgz lib.o65 lib.bin kern.bin kern.o65 rom.bin
	(cd boot; ${MAKE} clean;)
	# (cd apps; ${MAKE} clean;)

