

files= lmon

all: ${files}

${files}: %: %.a65
	xa -I../../include -I../../ -R -LLIB6502 -LOSA2KERNEL $@.a65 -o $@

clean:
	(for i in *; do\
	(if test -d $$i; then cd $$i; ${MAKE} clean; fi); \
	done)
	rm -f ${files}

