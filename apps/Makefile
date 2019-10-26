
# appdirs= lsh file inet
# appdirs= $(wildcard [a-z]*)

all:
	(for i in * ; do\
	(if test -d $$i; then cd $$i; ${MAKE}; fi;); \
	done)

clean:
	(for i in * ; do\
	(if test -d $$i; then cd $$i; ${MAKE} clean; fi;); \
	done)

