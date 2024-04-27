
all: lib6502.o

DEFS=-DOSA2KERNEL=\$f000 -DMemstart=\$1000 -DZerostart=\$80 -DMemend=\$8000 -DROMSTART=\$9000 \
     	-DOSA_ARCH=\"TEST\" -DOSA_CPU=\"6502\"

lib6502.o: *.a65
	xa -R -o $@ -I../include -I.. $(DEFS) lib6502.a65

clean:
	rm -f lib6502.o

