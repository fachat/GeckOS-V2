

XAINPUT=../../include,../../arch,../..
XA= XAINPUT=${XAINPUT} xa

BIN=drvmon

${BIN}.o65: ${BIN}.a65
	${XA} -LOSA2KERNEL -LLIB6502 -R -G ${BIN}.a65 -o ${BIN}.o65;

clean:
	rm -f ${BIN}.o65

