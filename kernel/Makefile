

XAINPUT=../include,..
XA=xa

kernel.o65: $(wildcard *.a65)
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -bt 61440 oa1.a65 -o kernel.o65 ;\
	if [ $$? -ne 0 ]; then rm -f kernel.o65; fi; \
	)

clean:
	rm -f kernel.o65

