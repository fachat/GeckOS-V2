
version="2.0.9"

all:
	(cd apps; ${MAKE};)

clean:
	(cd arch; ${MAKE} clean;)
	(cd apps; ${MAKE} clean;)
	(cd sysapps; ${MAKE} clean;)
	(cd kernel; ${MAKE} clean;)

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


