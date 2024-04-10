
TRG=c64rom.bin

XA=xa -k -XMASM
FILE=file65
RELOC=reloc65

c64 ${TRG}: 
	${XA} -R -I../../include -I.. -I../.. -bt 36862 -bd 768 -bz 8 -bb 2640 c64rom.a65 -o c64rom.o65 -l c64rom.lab;
	${FILE} c64rom.o65;
	${RELOC} -xt -o ${TRG} c64rom.o65 | tee reloc.lst
	../labels2vice.sh c64rom.lab > c64rom.l

clean:
	rm -f ${TRG} c64rom.lab c64rom.l c64rom.o65 reloc.lst
	make -C boot clean
	(cd boot; ${MAKE} clean;)

