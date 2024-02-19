

XAINCLUDE=-I../include -I.. -I../arch/cbm8x96
XA=xa

DEFS=-DMemend=32768 -DPETPIA1=\$e810 -DPIA_PA=0 -DPIA_CRA=1 -DNEED_SETINFO

kernel.o65: $(wildcard *.a65)
	${XA} -R -E -bt 61440 kernel.a65 $(XAINCLUDE) $(DEFS) -o kernel.o65 ;\
	if [ $$? -ne 0 ]; then rm -f kernel.o65; fi; \
	

clean:
	rm -f kernel.o65

