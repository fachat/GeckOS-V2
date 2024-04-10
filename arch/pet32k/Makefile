
TRG=rom.bin

XAINPUT=../../include,..,../..
XA=xa -k
FILE=file65
RELOC=reloc65

all: pet

# note extract address is 766, to account for the load address embedded in the rom.bin
pet ${TRG}: 
	make -C .. reloclabels
	# note no defined segment addresses. This is done with reloc below, incl. relocating the label file
	${XA} -I../../include -I../.. -R rom.a65 -o rom.o65 -l rom.lab;
	# display build info
	${FILE} rom.o65;
	# relocate to actual address. text starts at $0300. data and bss follow directly
	${RELOC} -v -bt 766 -bz 8 -X -o ${TRG} rom.o65 | tee reloc.lst
	../reloclab.sh reloc.lst rom.lab > rom.lab.tmp 2>/dev/null
	mv rom.lab.tmp rom.lab
	../labels2vice.sh rom.lab > rom.l
	
clean:
	rm -f ${TRG} rom.lab rom.o65 rom reloc.lst rom.l
	(cd boot; ${MAKE} clean;)

