

XAINPUT=../../include,../../arch,../..
XA=xa

basic4.o65: basic4.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DKERNEL=61440 -R -c basic4.a65 -o basic4.o65 ;\
	if [ $$? -ne 0 ]; then rm -f basic4.o65; fi; )

clean:
	rm -f basic4.o65

