

XAINPUT=../../include,../../arch,../..
XA=xa

basic: basic4.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -R -LOSA2KERNEL -LLIB6502 basic4.a65 -o basic ;\
	if [ $$? -ne 0 ]; then rm -f basic; else file65 basic; fi; )

clean:
	rm -f basic

