
XAINPUT=../../../include
XA=xa

all: inigecko geckorom inig2 inig3

gecko geckorom:
	(cd ..; ${MAKE} ;)

inigecko: inigecko.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DKERNEL=61440 inigecko.a65 -o inigecko;\
	if [ $$? -ne 0 ]; then rm -f inigecko; fi)

inig2: inig2.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DKERNEL=61440 inig2.a65 -o inig2;\
	if [ $$? -ne 0 ]; then rm -f inig2; fi)

inig3: inig3.a65
	${XA} -DXCSA -I../../../include -DKERNEL=61440 inig3.a65 -o inig3;

clean:
	rm -f geckorom inigecko inig2 inig3


