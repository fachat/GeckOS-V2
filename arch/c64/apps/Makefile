

XAINPUT=../../../include,../../..
XA=xa

test.o65: test.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DKERNEL=61440 -c test.a65 -o test.o65 ;\
	if [ $$? -ne 0 ]; then rm -f test.o65; fi; )

clean:
	rm -f test.o65

