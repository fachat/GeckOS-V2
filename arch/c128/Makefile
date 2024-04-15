
all: lib.o65 kern.o65 rom.o65 roms.l

SHELL=/bin/bash	# for arithmetic expansion

XA=xa -k -E -XMASM
FILE=file65 
RELOC=reloc65

# where the kernel and its data are located
KERNEL=60416	# $ec00, also jump table
KERNDATA=58880	# $e600
KERNBSS=59392	# $e800

# where the init image and its data are located
ROMSTART=32768	# $8000
ROMDATA=43008	# $a800
ROMBSS=43520	# $aa00

# where the lib6502 and its data are located
LIB6502=52992	# $cf00, jump table address
LIBSTART=46592	# $b600 code start
LIBDATA=768	# data start

Zerostart=96
Memstart=2048	# keep space for screen at this time

roms.l: lib.lab rom.lab kern.lab
	../labels2vice.sh lib.lab rom.lab kern.lab > roms.l
	
lib.o65: lib.a65
	# start binary at 910+2 = $0390
	${XA} -I../../include -I../.. -DOSA2KERNEL=$(KERNEL)  -DXLIB6502=$(LIB6502) -DZerostart=$(Zerostart) -DMemstart=$(Memstart) -R -bt $(LIBSTART) -bd $(LIBDATA) -bz 8 -bb 65535 $< -o lib.o65 -l lib.lab;
	${FILE} lib.o65

kern.o65: kern.a65
	${XA} -I../../include -I../.. -R -DROMSTART=$(ROMSTART) -DMemend=8192 -bt $(KERNEL) -bd $(KERNDATA) -bz 32 -bb $(KERNBSS) $< -o kern.o65 -l kern.lab;
	${FILE} kern.o65

rom.o65: rom.a65
	${XA} -I../../include -I../.. -R -DOSA2KERNEL=$(KERNEL) -DLIB6502=$(LIB6502) -DROMSTART=$(ROMSTART) -bt $(ROMSTART) -bd $(ROMDATA) -bz 52 -bb $(ROMBSS) $< -o rom.o65 -l rom.lab;
	${FILE} rom.o65

info: rom.o65 kern.o65 lib.o65
	$(FILE)  rom.o65 kern.o65 lib.o65

clean:
	rm -f *.lab roms.l rom.o65 boot.tgz lib.o65 lib.bin kern.bin kern.o65 rom.bin
	make -C boot clean

