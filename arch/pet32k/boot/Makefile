
lsh = lsh
LSHDIR=../../../apps/lsh

sysapps = lmon slipd ps kill ontty
SYSAPPSDIR=../../../sysapps

files = mkdir rmdir rm format chkdsk ls cat mv wc more hexdump
FILESDIR=../../../apps/file

XA=xa

all: osa.d64

rom:
	(cd ..; ${MAKE} boot/$@;)

loader: loader.bas
	petcat -w40 -o loader loader.bas

clean:
	rm -f rom osa.d64 osam.d64 osa.x64 loader
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

osa.d64: ${files} ${sysapps} ${lsh} rom loader 
	./mkdisk loader ${addprefix ${FILESDIR}/, ${files}} ${sysapps} ${addprefix ${LSHDIR}/, ${lsh}} rom 
	dd if=osa.x64 of=osa.d64 bs=64 skip=1
	rm osa.x64

emurun: osa.d64
	xpet -model 4032 -autostart osa.d64

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


	
