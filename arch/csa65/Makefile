
TRG=boot/csarom

XA=xa
FILE=file65
RELOC=reloc65

csa ${TRG}: # $(wildcard *.a65)
	${XA} -I../.. -I../../include -bt 32768 \
		csarom.a65 -o ${TRG} -l csarom.lab

clean:
	rm -f ${TRG} csarom.lab csarom
	(cd boot; ${MAKE} clean ;)
	(cd apps; ${MAKE} clean ;)

