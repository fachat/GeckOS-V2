
lsh = lsh
LSHDIR=../../../apps/lsh

sysapps = mon slipd ps kill 
SYSAPPSDIR=../../../sysapps

files = mkdir rmdir rm format chkdsk ls cat mv wc more hexdump
FILESDIR=../../../apps/file

inet = tlogind telnet httpd
INETDIR=../../../apps/inet

XA=xa

all: osa.d64

c64 c64rom:
	(cd ..; ${MAKE};)

boot: boot.a65
	${XA} boot.a65 -o boot

clean:
	rm -f c64rom boot osa.d64 osa.x64
	rm -f ${sysapps}
	rm -f vice.trace reltest

topclean:
	# convenience
	(cd ../../../; make clean);

tar ../boot.tgz: boot c64rom loader index.html slip howto.boot
	tar czvf ../boot.tgz boot c64rom loader index.html slip howto.boot

##############################################################################
#
# d64 emulator disk image + run
#

osa.d64: ${files} ${sysapps} ${lsh} ${inet} c64rom boot loader index.html test.bat
	./mkdisk loader ${addprefix ${FILESDIR}/, ${files}} ${sysapps} ${addprefix ${LSHDIR}/, ${lsh}} ${addprefix ${INETDIR}/, ${inet}} c64rom boot index.html test.bat
	rm -f ${sysapps}

emurun: osa.d64
	x64 -autostart osa.d64

emuslip: all
	x64+rs232 -kernal ~/csa/tmp/kernalb -speed 200

##############################################################################
#
# lib6502 programs
#

${lsh}: 
	(cd ${LSHDIR}; make $@;)

${sysapps}: 
	(if test -d ${SYSAPPSDIR}/$@; then ln -sf ${SYSAPPSDIR}/$@/$@; cd ${SYSAPPSDIR}/$@; make $@; fi)
	(if test -f ${SYSAPPSDIR}/$@.a65; then ln -sf ${SYSAPPSDIR}/$@;cd ${SYSAPPSDIR}; make $@;  fi)

${files}:
	(cd ${FILESDIR}; make $@;)

${inet}:
	(cd ${INETDIR}; make $@;)

	
