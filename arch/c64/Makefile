
TRG=boot/c64rom

XA=xa -k -XMASM
FILE=file65
RELOC=reloc65

c64 ${TRG}: 
	${XA} -R -I../../include -I.. -I../.. -bt 36862 -bd 768 -bz 8 -bb 2640 c64rom.a65 -o c64rom.o65 -l c64rom.lab;
	${FILE} c64rom.o65;
	${RELOC} -xt -o ${TRG} c64rom.o65; 
	if [ $$? -ne 0 ]; then rm ${TRG}; fi;
	cat c64rom.lab | sed -e 's/ 0x/ /g' | cut -d , -f 1,2,3 | tr -d , | awk '{print "al "$$2" ."$$1"_"$$3;}' > osa.l

andre: 
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DANDRE -R -bt 36862 -bd 768 -bz 8 -bb 2640 c64rom.a65 -o c64rom.o65 -l c64rom.lab ;\
	${FILE} c64rom.o65;\
	${RELOC} -xt -o ${TRG} c64rom.o65; \
	if [ $$? -ne 0 ]; then rm ${TRG}; fi;)
	cat c64rom.lab | sed -e 's/ 0x/ /g' | cut -d , -f 1,2,3 | tr -d , | awk '{print "al "$$2" ."$$1"_"$$3;}' > osa.l
	

clean:
	rm -f ${TRG} c64rom.lab c64rom.l c64rom.o65 boot.tgz
	(cd boot; ${MAKE} clean;)
	(cd apps; ${MAKE} clean;)

