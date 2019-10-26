
c64: main.a65 csascsi1.a65 pcpart.a65 printc64.a65 paccess.a65 part.i65
	xa -DC64 -l main.lab -I../oa-2.0.0a/include \
		-bz 250 -bb 4096 \
		main.a65 -o mainc64

csa: main.a65 csascsi1.a65 pcpart.a65 printcsa.a65 paccess.a65 part.i65
	xa -DCSA -R -l main.lab -I../oa-2.0.0a/include -DOSA2KERNEL=\$$f000 -bz 128 -bt 1024 -bb 3072 main.a65 -o main.o65
	file65 main.o65
	reloc65 -xt -o maincsa main.o65 

clean:
	rm -f *.o65 *.lab main maincsa

dist: c64 clean
	(cd ..; tar czv --exclude=scsi/csascsi1.fig -f scsidist.tar.gz scsi ; )

mrproper: clean
	rm -f mainc64

arc: mrproper
	(cd ..; tar czvf scsi.tar.gz scsi ; )


