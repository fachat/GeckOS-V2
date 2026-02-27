
TRG=c64rom.o65

XA=xa -k -XMASM
FILE=file65
RELOC=reloc65

all: $(TRG)

ROMSTART=36352	# $8e00

${TRG}: 
	${XA} -R -I../../include -I.. -I../.. \
		-DROMSTART=$(ROMSTART) \
		-bt $$(($(ROMSTART)-2)) -bd 768 -bz 8 -bb 2640 c64rom.a65 -o c64rom.o65 -l c64rom.lab;
	${FILE} c64rom.o65;
	../labels2vice.sh c64rom.lab > roms.l

info:
	$(FILE) c64rom.o65

clean:
	rm -f ${TRG} c64rom.lab roms.l c64rom.o65 reloc.lst
	make -C boot clean
	(cd boot; ${MAKE} clean;)

