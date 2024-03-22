
all: lib.bin kern.bin rom.bin osa.l

TRG=boot/rom

SHELL=/bin/bash	# for arithmetic expansion

XAINPUT=../../include,..,../..
XA=xa -k
FILE=file65
RELOC=reloc65

LIB=7200	# $1c20
KERNEL=61184	# $ef00
#KERNEL=61440	# $f000

osa.l: lib.lab rom.lab kern.lab
	cat rom.lab lib.lab kern.lab | sed -e 's/ 0x/ /g' | cut -d , -f 1,2,3 | tr -d , | awk '{print "al "$$2" ."$$1"_"$$3;}' > osa.l
	
lib lib.bin: lib.a65
	# start binary at 910+2 = $0390
	${XA} -I../../include -I../.. -DOSA2KERNEL=$(KERNEL) -DLIB6502=$(LIB) -R -bt 910 -bd 768 -bz 8 -bb 65535 $< -o lib.o65 -l lib.lab;
	${FILE} lib.o65
	${RELOC} -xt -o lib.bin lib.o65; 

kern kern.bin: kern.a65
	${XA} -I../../include -I../.. -R -bt $$(($(KERNEL)-2)) -bd 59648 -bz 32 -bb 58368 $< -o kern.o65 -l kern.lab;
	${FILE} kern.o65
	${FILE} -v kern.o65 | grep OSA2KERNEL
	${RELOC} -xt -o kern.bin kern.o65

rom rom.bin: rom.a65
	${XA} -I../../include -I../.. -R -DLIB6502=$(LIB) -DOSA2KERNEL=$(KERNEL) -bt 40958 -bd 55296 -bz 52 -bb 56320 $< -o rom.o65 -l rom.lab;
	${FILE} rom.o65
	${RELOC} -xt -o rom.bin rom.o65

info: rom.bin kern.bin lib.bin
	$(FILE)  rom.o65 kern.o65 lib.o65

clean:
	rm -f ${TRG} *.lab rom.o65 boot.tgz lib.o65 lib.bin kern.bin kern.o65 rom.bin
	(cd boot; ${MAKE} clean;)
	# (cd apps; ${MAKE} clean;)

