
MANPAGES=../../../*/*/*.1.adoc

apps = lsh lmon
APPSDIR=../../../apps

sysapps = slipd ps kill ontty lsmem
SYSAPPSDIR=../../../sysapps

files = mkdir rmdir rm format chkdsk ls mv
FILESDIR=../../../apps/file

filter = cat wc more hexdump
FILTERDIR=../../../apps/filter

inet = tlogind telnet httpd
INETDIR=../../../apps/inet

XA=xa

X64=x64sc

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

osa.d64: ${files} ${filter} ${sysapps} ${apps} ${inet} c64rom boot loader index.html test.bat
	./mkdisk loader ${addprefix ${FILESDIR}/, ${files}}  ${addprefix ${FILTERDIR}/, ${filter}} ${sysapps} ${apps} ${addprefix ${INETDIR}/, ${inet}} ${MANPAGES} c64rom boot index.html test.bat
	rm -f ${sysapps} ${apps}

emurun: osa.d64
	${X64} -autostart osa.d64

emuslip: all
	x64+rs232 -kernal ~/csa/tmp/kernalb -speed 200

##############################################################################
#
# lib6502 programs
#

${apps}: 
	(if test -d ${APPSDIR}/$@; then ln -sf ${APPSDIR}/$@/$@; cd ${APPSDIR}/$@; make $@; fi)
	(if test -f ${APPSDIR}/$@.a65; then ln -sf ${APPSDIR}/$@;cd ${APPSDIR}; make $@;  fi)

${sysapps}: 
	(if test -d ${SYSAPPSDIR}/$@; then ln -sf ${SYSAPPSDIR}/$@/$@; cd ${SYSAPPSDIR}/$@; make $@; fi)
	(if test -f ${SYSAPPSDIR}/$@.a65; then ln -sf ${SYSAPPSDIR}/$@;cd ${SYSAPPSDIR}; make $@;  fi)

${files}:
	(cd ${FILESDIR}; make $@;)

${filter}:
	(cd ${FILTERDIR}; make $@;)

${inet}:
	(cd ${INETDIR}; make $@;)

	
