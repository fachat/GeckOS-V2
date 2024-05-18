
all: lib.o65 kern.o65 rom40.o65 rom80.o65 roms.l

SHELL=/bin/bash	# for arithmetic expansion

XA=xa -k -E -XMASM
FILE=file65 
RELOC=reloc65

# where the kernel and its data are located
KERNEL=60416	# $ec00, also jump table
KERNDATA=57344	# $e000
KERNBSS=58880	# $e600

# where the init image and its data are located
ROMSTART=32768	# $8000
ROMDATA80=45696	# $b280
ROMDATA40=45696	# $b280
ROMBSS=46080	# $b400

# where the lib6502 and its data are located
LIB6502=783	# $030f, jump table address
LIBSTART=768	# $0300 code start
LIBDATA=7168	# $1c00 data start

Zerostart=96
#Memstart=2048	# automatically set to end of lib6502 data
Memend=57344	# $e000 end of allocatable memory in user env

roms.l: lib.lab rom.lab kern.lab
	../labels2vice.sh lib.lab rom.lab kern.lab > roms.l
	
lib.o65: lib.a65
	# start binary at 910+2 = $0390
	${XA} -I../../include -I../.. -DOSA2KERNEL=$(KERNEL)  -DLIB6502START=$(LIB6502) -DZerostart=$(Zerostart) -DMemend=$(Memend) -R -bt $(LIBSTART) -bd $(LIBDATA) -bz 8 -bb 65535 $< -o lib.o65 -l lib.lab;
	${FILE} lib.o65

kern.o65: kern.a65 kernel/*.a65
	${XA} -I../../include -I../.. -R -DROMSTART=$(ROMSTART) -DMemend=$(Memend) -bt $(KERNEL) -bd $(KERNDATA) -bz 32 -bb $(KERNBSS) $< -o kern.o65 -l kern.lab;
	${FILE} kern.o65

rom40.o65: rom.a65 devices/*.a65
	${XA} -I../../include -I../.. -R -DOSA2KERNEL=$(KERNEL) -DLIB6502=$(LIB6502) -DROMSTART=$(ROMSTART) -bt $(ROMSTART) -bd $(ROMDATA40) -bz 52 -bb $(ROMBSS) $< -o $@ -l rom.lab;
	${FILE} $@

rom80.o65: rom.a65 devices/*.a65
	${XA} -I../../include -I../.. -R -DOSA2KERNEL=$(KERNEL) -DLIB6502=$(LIB6502) -DROMSTART=$(ROMSTART) -DVDCSCREEN -bt $(ROMSTART) -bd $(ROMDATA80) -bz 52 -bb $(ROMBSS) $< -o $@ -l rom.lab;
	${FILE} $@

info: rom80.o65 rom40.o65 kern.o65 lib.o65
	$(FILE)  $^

clean:
	rm -f *.lab roms.l rom40.o65 rom80.o65 boot.tgz lib.o65 lib.bin kern.bin kern.o65 rom.bin
	make -C boot clean

