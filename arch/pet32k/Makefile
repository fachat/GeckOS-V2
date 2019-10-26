
TRG=boot/rom

XAINPUT=../../include,..,../..
XA=xa
FILE=file65
RELOC=reloc65

pet ${TRG}: 
	${XA} -I../../include -I../..  -R -bt 4862 -bd 768 -bz 8 -bb 2432 rom.a65 -o rom.o65 -l rom.lab;
	${FILE} rom.o65;
	${RELOC} -xt -o ${TRG} rom.o65; 
	
rom2 ${TRG}2:
	${XA} -DHAVE_MON -I../../include -I../..  -R -bt 5030 -bd 768 -bz 8 -bb 2656 rom.a65 -o rom.o65 -l rom.lab;
	${FILE} rom.o65;
	${RELOC} -xt -o ${TRG}2 rom.o65; 
	
clean:
	rm -f ${TRG} rom.lab rom.o65 boot.tgz
	(cd boot; ${MAKE} clean;)
	# (cd apps; ${MAKE} clean;)

