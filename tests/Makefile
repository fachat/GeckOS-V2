
FILES=testcon

XA=xa -I../include -I../apps

all: $(FILES)
	
$(FILES): %: %.a65 ../apps/common.a65
	$(XA) -I../include -R -LLIB6502 $@.a65 -o $@

clean:
	rm -f $(FILES)

