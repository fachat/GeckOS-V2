

XAINPUT=../../include,../..
XA= XAINPUT=${XAINPUT} xa

all: mon

mon: mon.a65 shdir.a65
	${XA} -R -XCA65 -LLIB6502 -LOSA2KERNEL mon.a65 -o mon;

clean:
	rm -f mon

