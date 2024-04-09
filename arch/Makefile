
# archdirs= c64 csa65 gecko embedded proto cbm8x96 pet32k

clean:
	(for i in *; do \
	(if test -d $$i; then cd $$i; ${MAKE} clean; fi;) \
	done;)	
	rm -f reloclabels

reloclabels: reloclabels.c
	gcc -o $@ $<

