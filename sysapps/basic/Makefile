

XAINPUT=../../include,../../arch,../..
XA=xa

basic: basic2.a65
	${XA} -R -LOSA2KERNEL -LLIB6502 -I../../include -I../.. basic2.a65 -o basic ;
	file65 basic

clean:
	rm -f basic

