
apps = lsh
sysapps = mon slipd
files = mkdir rmdir rm format chkdsk ls cat mv
inet = tlogin telnet httpd

XA=xa

all: boot c64rom ${files} ${apps} ${sysapps} ${inet}

c64 c64rom:
	(cd ..; ${MAKE};)

boot: boot.a65
	${XA} boot.a65 -o boot

clean:
	rm -f c64rom boot osa.d64 osa.x64
	rm -f ${files} ${sysapps} ${apps} ${inet}
	rm -f vice.trace reltest

tar ../boot.tgz: boot c64rom loader index.html slip howto.boot
	tar czvf ../boot.tgz boot c64rom loader index.html slip howto.boot

##############################################################################
#
# d64 emulator disk image + run
#

osa.d64: ${files} ${sysapps} ${apps} ${inet} c64rom boot loader index.html
	./mkdisk ${files} ${sysapps} ${apps} ${inet} c64rom boot loader index.html
	dd if=osa.x64 of=osa.d64 bs=64 skip=1

emurun: osa.d64
	x64 -1541 -8 osa.d64

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

	
