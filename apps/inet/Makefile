
XA=xa -k

files= tlogin telnet httpd

all: ${files}

${files}: %: %.a65
	$(XA) -I../../include -R -LLIB6502 $@.a65 -o $@

clean:
	rm -f ${files}


