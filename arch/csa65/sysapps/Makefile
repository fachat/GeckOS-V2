
apps = lsh
sysapps = mon slipd
files = mkdir rmdir rm format chkdsk ls cat mv
inet = tlogin telnet httpd

XA=xa

all: osa.d64

redo: 
	rm -f fsibm.o65
	make
	cat foo

fsibm.o65: fsibm.a65
	${XA} -bz 32 -bt 1280 -bd 768 -bb 12288 -l fsibm.lab -r -I.. -I../../../include -I../../.. -R -DOSA2KERNEL=\$$f000 $< -o $@
	file65 -V fsibm.o65
	reloc65 -xt -o fsibm fsibm.o65

osa.d64: ${files} ${sysapps} ${apps} fsibm.o65
	./mkdisk ${files} ${sysapps} ${apps} ${inet} fsibm.o65
	dd if=osa.x64 of=osa.d64 bs=64 skip=1

clean:
	rm -f fsibm.o65 fsibm.lab fsibm
	rm -f ${files} ${sysapps} ${apps} ${inet}
	rm -f osa.d64 osa.x64

${apps}:
	(cd ../../../apps/lsh; make lsh;)
	(if test ! -r lsh; then ln -s ../../../apps/lsh/lsh lsh; fi)

${sysapps}:
	(cd ../../../sysapps/$@; make $@;)
	(if test ! -r $@; then ln -s ../../../sysapps/$@/$@ $@; fi)

${files}:
	(cd ../../../apps/file; make $@;)
	(if test ! -r $@; then ln -s ../../../apps/file/$@ $@; fi)

${inet}:
	(cd ../../../apps/inet; make $@;)
	(if test ! -r $@; then ln -s ../../../apps/inet/$@ $@; fi)


