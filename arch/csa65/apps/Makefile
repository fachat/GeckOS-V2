

XAINPUT=../../../include,../../..
XA=xa

irtx.o65: irtx.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DKERNEL=61440 -c irtx.a65 -o irtx.o65 ;\
	if [ $$? -ne 0 ]; then rm -f irtx.o65; fi; )

clean:
	rm -f irtx.o65

