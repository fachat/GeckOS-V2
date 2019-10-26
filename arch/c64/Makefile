
TRG=boot/c64rom

XAINPUT=../../include,..,../..
XA=xa
FILE=file65
RELOC=reloc65

c64 ${TRG}: # $(wildcard *.a65)
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -R -bt 30718 -bd 768 -bz 8 -bb 2704 c64rom.a65 -o c64rom.o65 -l c64rom.lab ;\
	${FILE} c64rom.o65;\
	${RELOC} -xt -o ${TRG} c64rom.o65; \
	if [ $$? -ne 0 ]; then rm ${TRG}; fi;)
	

clean:
	rm -f ${TRG} c64rom.lab c64rom.o65 boot.tgz
	(cd boot; ${MAKE} clean;)
	(cd apps; ${MAKE} clean;)

