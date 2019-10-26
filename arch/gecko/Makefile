
TRG=boot/geckorom

XAINPUT=../../include,../..
XA=xa
FILE=file65
RELOC=reloc65

gecko ${TRG}: geckorom.o65
	${RELOC} -xt -o ${TRG} geckorom.o65

geckorom.o65: gecko.a65 config.i65 gecko.i65
	${XA} -I../.. -I../../include -R -bt 32768 -bd 768 -bz 8 -bb 2048 gecko.a65 -o geckorom.o65 -l gecko.lab ;
	${FILE} geckorom.o65;

fsiectst: fsiectst.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DKERNEL=61440 -bt 6144 -bz 128 -bd 4096 -bb 4352 fsiectst.a65 -o fsiectst  ;\
	if [ $$? -ne 0 ]; then rm -f fsiectst; fi; )

clean:
	rm -f ${TRG} geckorom gecko.lab geckorom.o65 fsiectst
	(cd boot; ${MAKE} clean;)

