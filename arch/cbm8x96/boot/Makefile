
MANPAGES=../../../*/*/*.1.adoc

apps = lsh lmon
APPSDIR=../../../apps

sysapps = ps kill ontty #slipd
SYSAPPSDIR=../../../sysapps

files = mkdir rmdir rm format chkdsk ls mv
FILESDIR=../../../apps/file

filter = cat wc more hexdump
FILTERDIR=../../../apps/filter

inet = # tlogin telnet httpd
INETDIR=../../../apps/inet

XA=xa

#all: rom ${files} ${apps} ${sysapps} ${inet}
all: osa.d64

rom:
	(cd ..; ${MAKE};)

clean:
	rm -f rom osa.d64 osa.x64
	rm -f ${sysapps} 
	rm -f vice.trace reltest

topclean:
	# convenience
	(cd ../../../; make clean);

tar ../boot.tgz: rom loader howto.boot
	tar czvf ../boot.tgz rom loader howto.boot

loader: loader.bas
	petcat -l 0401 -w40 -o loader loader.bas

##############################################################################
#
# d64 emulator disk image + run
#

osa.d64: ${files} ${filter} ${sysapps} ${apps} ${inet} rom loader
	./mkdisk loader ${sysapps} ${addprefix ${FILESDIR}/, ${files}} ${addprefix ${FILTERDIR}/, ${filter}} ${apps} ${addprefix ${INETDIR}/, ${inet}} ${MANPAGES} rom 
	rm -f ${sysapps} ${apps}

emurun: osa.d64
	xpet -model 8296 -drive8type 2031 -autostart osa.d64


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
	
