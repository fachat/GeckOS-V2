
apps = lsh
sysapps = mon # slipd
files = mkdir rmdir rm format chkdsk ls cat mv
inet = # tlogin telnet httpd

XA=xa

all: rom ${files} ${apps} ${sysapps} ${inet}

rom:
	(cd ..; ${MAKE};)

clean:
	rm -f rom osa.d64 osa.x64
	rm -f ${files} ${sysapps} ${apps} ${inet}
	rm -f vice.trace reltest

tar ../boot.tgz: rom loader howto.boot
	tar czvf ../boot.tgz rom loader howto.boot

##############################################################################
#
# d64 emulator disk image + run
#

osa.d64: ${files} ${sysapps} ${apps} ${inet} rom loader
	./mkdisk ${files} ${sysapps} ${apps} ${inet} rom loader
	dd if=osa.x64 of=osa.d64 bs=64 skip=1

emurun: osa.d64
	xpet -model 8096 -8 osa.d64

emuslip: all
	x64+rs232 -kernal ~/csa/tmp/kernalb -speed 200

##############################################################################
#
# lib6502 programs
#

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

	
