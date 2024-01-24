
version="2.0.9"

all:
	(cd apps; ${MAKE};)
	(cd sysapps; ${MAKE};)

clean:
	(cd arch; ${MAKE} clean;)
	(cd apps; ${MAKE} clean;)
	(cd sysapps; ${MAKE} clean;)
	(cd kernel; ${MAKE} clean;)

cbm8x96: clean
	(cd arch/cbm8x96; make; cd boot; make)

c64: clean
	(cd arch/c64; make; cd boot; make)

pet32k: clean
	(cd arch/pet32k; make; cd boot; make)

csa65: clean
	(cd arch/csa65; make; cd boot; make)

tars:
	tar czhvf ../oa-${version}.lib.tar.gz apps \
		include/lib6502.i65 include/kdefs.i65 include/inet.i65
	(cd ..; \
	tar czhvf oa-${version}.base.tar.gz \
		--exclude oa-${version}/arch/csa65 \
		--exclude oa-${version}/arch/gecko \
		--exclude oa-${version}/sysapps/basic \
		--exclude oa-${version}/sysapps/irtx \
		oa-${version} ;\
	tar czhvf oa-${version}.tar.gz \
		oa-${version} ;\
	)


