
TRG=boot/rom

XAINPUT=../../include,..,../..
XA=xa -k
FILE=file65
RELOC=reloc65

pet ${TRG}: 
	#${XA} -I../../include -I../..  -R -bt 4926 -bd 768 -bz 8 -bb 2556 rom.a65 -o rom.o65 -l rom.lab;
	${XA} -I../../include -I../..  -R -bt 4940 -bd 768 -bz 8 -bb 2570 rom.a65 -o rom.o65 -l rom.lab;
	${FILE} rom.o65;
	${RELOC} -xt -o ${TRG} rom.o65; 
	
clean:
	rm -f ${TRG} rom.lab rom.o65 boot.tgz
	(cd boot; ${MAKE} clean;)
	# (cd apps; ${MAKE} clean;)

