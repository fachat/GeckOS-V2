

XAINPUT=../../include,../../arch
XA=xa

all: fsiec.o65 fsdev.o65

fsiec.o65: fsiec.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DKERNEL=61440 -R -c fsiec.a65 -o fsiec.o65 ;\
	if [ $$? -ne 0 ]; then rm -f fsiec.o65; fi; )

fsdev.o65: fsdev.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DKERNEL=61440 -R -c fsdev.a65 -o fsdev.o65 ;\
	if [ $$? -ne 0 ]; then rm -f fsdev.o65; fi; )

clean:
	rm -f fsdev.o65 fsiec.o65

