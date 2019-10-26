
all: drv_wd1770.o65 buffer.o65 drive.o65

drv_wd1770.o65: drv_wd1770.a65
	xa -R -c ../../../include/kdefs.i65 defs.a65 drv_wd1770.a65 \
		-I../../../include -DANZDRV=4 -o drv_wd1770.o65
	file65 -V drv_wd1770.o65

buffer.o65: buffer.a65
	xa -R -c ../../../include/kdefs.i65 defs.a65 buffer.a65 \
		-I../../../include -o buffer.o65
	file65 -V buffer.o65

drive.o65: drive.a65
	xa -R -c ../../../include/kdefs.i65 defs.a65 drive.a65 \
		-I../../../include -o drive.o65
	file65 -V drive.o65

clean: 
	rm -f *.o65

