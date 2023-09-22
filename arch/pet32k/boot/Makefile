
MANPAGES=../../../*/*/*.1.adoc

apps = lsh lmon
APPSDIR=../../../apps

sysapps = slipd ps kill ontty lsmem
SYSAPPSDIR=../../../sysapps

files = mkdir rmdir rm format chkdsk ls mv
FILESDIR=../../../apps/file

filter = cat wc more hexdump
FILTERDIR=../../../apps/filter

XA=xa

all: osa.d64

rom:
	(cd ..; ${MAKE} boot/$@;)

loader: loader.bas
	petcat -w40 -o loader loader.bas

clean:
	rm -f rom osam.d64 loader
	rm -f ${sysapps}
	rm -f vice.trace reltest

topclean:
	# convenience
	(cd ../../../; make clean)

tar ../boot.tgz: rom loader howto.boot
	tar czvf ../boot.tgz rom loader howto.boot

##############################################################################
#
# d64 emulator disk image + run
#

osa.d64: ${files} ${filter} ${sysapps} ${apps} rom loader 
	./mkdisk loader  ${addprefix ${FILESDIR}/, ${files}} ${addprefix ${FILTERDIR}/, ${filter}} ${sysapps} ${apps} ${MANPAGES} rom 
	rm ${apps} ${sysapps}

emurun: osa.d64
	xpet -model 4032 -autostart osa.d64

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


	
