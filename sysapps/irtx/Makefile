

XAINPUT=../../include,../..
XA= XAINPUT=${XAINPUT} xa

BIN=irtx

all: ${BIN}.o65

${BIN}.o65: ${BIN}.a65
	${XA} -LKERNEL -LVIA -R -G ${BIN}.a65 -o ${BIN}.o65;

clean:
	rm -f ${BIN}.o65

