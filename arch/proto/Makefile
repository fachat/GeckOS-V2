
TRG=boot/rom

XAINPUT=../../include,..,../..
XA=XAINPUT=${XAINPUT} xa
FILE=file65
RELOC=reloc65

rom ${TRG}: 
	${XA} -R -bt 32766 -bd 768 -bz 8 -bb 2560 rom.a65 -o rom.o65 -l rom.lab ;
	${FILE} rom.o65;
	${RELOC} -xt -o ${TRG} rom.o65; 
	

clean:
	rm -f ${TRG} rom.lab rom.o65 boot.tgz
	(cd boot; ${MAKE} clean;)
	# (cd apps; ${MAKE} clean;)

