
XAINPUT=../../../include
XA=xa

all: inirom csarom

csarom:
	(cd ..; ${MAKE};)

inirom: inirom.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DOSA2KERNEL=61440 inirom.a65 -o inirom;\
	if [ $$? -ne 0 ]; then rm -f inirom; fi)

clean:
	rm -f csarom inirom

