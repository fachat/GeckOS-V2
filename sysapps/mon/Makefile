

XAINPUT=../../include,../..
XA= XAINPUT=${XAINPUT} xa

all: mon

mon: mon.a65 shmon.a65 shdir.a65
	${XA} -R -LLIB6502 -LOSA2KERNEL mon.a65 -o mon;

clean:
	rm -f mon

