
files= cat wc more hexdump

all: ${files}

${files}: %: %.a65 ../common.a65
	xa -I../../include -R -LLIB6502 $@.a65 -o $@

clean:
	rm -f ${files}


