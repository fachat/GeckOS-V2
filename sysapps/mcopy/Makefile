

XAINPUT=../../include,../../arch,../..
XA=xa

mcopy.o65: mcopy.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DKERNEL=61440 -R -c mcopy.a65 -o mcopy.o65 ;\
	if [ $$? -ne 0 ]; then rm -f mcopy.o65; fi; )

clean:
	rm -f mcopy.o65

