
lsh = lsh
LSHDIR=../../../apps/lsh

sysapps = mon slipd ps kill 

files = mkdir rmdir rm format chkdsk ls cat mv
FILESDIR=../../../apps/file

inet = tlogind telnet httpd
INETDIR=../../../apps/inet

XA=xa

all: boot c64rom ${files} ${lsh} ${sysapps} ${inet}

c64 c64rom:
	(cd ..; ${MAKE};)

boot: boot.a65
	${XA} boot.a65 -o boot

clean:
	rm -f c64rom boot osa.d64 osa.x64
	rm -f ${files} ${sysapps} ${lsh} ${inet}
	rm -f vice.trace reltest

tar ../boot.tgz: boot c64rom loader index.html slip howto.boot
	tar czvf ../boot.tgz boot c64rom loader index.html slip howto.boot

##############################################################################
#
# d64 emulator disk image + run
#

osa.d64: ${files} ${sysapps} ${lsh} ${inet} c64rom boot loader index.html
	./mkdisk loader ${addprefix ${FILESDIR}/, ${files}} ${sysapps} ${addprefix ${LSHDIR}/, ${lsh}} ${addprefix ${INETDIR}/, ${inet}} c64rom boot index.html

emurun: osa.d64
	x64 -8 osa.d64

emuslip: all
	x64+rs232 -kernal ~/csa/tmp/kernalb -speed 200

##############################################################################
#
# lib6502 programs
#

${lsh}: 
	(cd ${LSHDIR}; make $@;)

${sysapps}: 
	(if test -d ../../../sysapps/$@; then ln -sf ../../../sysapps/$@/$@ $@; cd ../../../sysapps/$@; make $@; fi)
	(if test -f ../../../sysapps/$@.a65; then ln -sf ../../../sysapps/$@ $@; cd ../../../sysapps; make $@; fi)

${files}:
	(cd ${FILESDIR}; make $@;)

${inet}:
	(cd ${INETDIR}; make $@;)

	
