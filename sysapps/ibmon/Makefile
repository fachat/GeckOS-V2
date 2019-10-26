

XAINPUT=../../include,../../arch,../..
XA= XAINPUT=${XAINPUT} xa

BIN=ibmon

${BIN}.o65: ${BIN}.a65
	${XA} -LKERNEL -R -G ${BIN}.a65 -o ${BIN}.o65;

clean:
	rm -f ${BIN}.o65

