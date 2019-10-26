
TRG=boot/rom

XAINPUT=../../include,..,../..
XA=xa
FILE=file65
RELOC=reloc65

pet ${TRG}: # $(wildcard *.a65)
	${XA} -I../../include -I../..  -R -bt 2814 -bd 768 -bz 8 -bb 61440 rom.a65 -o rom.o65 -l rom.lab;
	# ${XA} -I../../include -I../..  -R -bt 2046 -bd 30720 -bz 8 -bb 61440 rom.a65 -o rom.o65 -l rom.lab;
	${FILE} rom.o65;
	${RELOC} -xt -o ${TRG} rom.o65; 
	

clean:
	rm -f ${TRG} rom.lab rom.o65 boot.tgz
	(cd boot; ${MAKE} clean;)
	# (cd apps; ${MAKE} clean;)

