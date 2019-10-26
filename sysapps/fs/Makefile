

XA=xa

all: fsibm.o65 # fsiec.o65 fsdev.o65

fsibm.o65: fsibm.a65 $(wildcard fsibm/*.a65)
	${XA} -R -I../.. -I../../include -LOSA2KERNEL \
		-DFSIBM_DEVICE_DRV="sysapps/fs/fsibm/drv_ramd1.a65" \
		$< -o $@

fsiec.o65: fsiec.a65
	${XA} -R -I../.. -I../../include -LOSA2KERNEL $< -o $@

fsdev.o65: fsdev.a65
	${XA} -R -I../.. -I../../include -LOSA2KERNEL $< -o $@

clean:
	rm -f *.o65
	make -C fsibm clean


