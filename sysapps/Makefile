

files= ps kill ontty lsmem

all: ${files} slip
	make -C basic

${files}: %: %.a65
	xa -I../include -R -XCA65 -LLIB6502 -LOSA2KERNEL $@.a65 -o $@

slip:
	make -C slipd

clean:
	(for i in *; do\
	(if test -d $$i; then cd $$i; ${MAKE} clean; fi); \
	done)
	rm -f ${files}
	make -C slipd clean

