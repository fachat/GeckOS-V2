
XAINPUT=../../../include
XA=xa

all: osa.d64 prom prom_romtest

MANPAGES=../../../*/*/*.1.adoc

apps = lsh lmon
APPSDIR=../../../apps

sysapps = slipd ps kill ontty
SYSAPPSDIR=../../../sysapps

files = mkdir rmdir rm format chkdsk ls mv
FILESDIR=../../../apps/file

filter = cat wc more hexdump
FILTERDIR=../../../apps/filter

inet = tlogind telnet httpd
INETDIR=../../../apps/inet

prom: rom kernel lib
	((cat csarom.bin /dev/zero | dd bs=1024 count=18 ) && cat csalib.bin csakernel.bin) > prom

prom_romtest: rom kernel_romtest lib
	((cat csarom_romtest.bin /dev/zero | dd bs=1024 count=18 ) && cat csalib.bin csakernel_romtest.bin) > prom_romtest

osa.d64: rom rom_romtest kernel kernel_romtest lib boot loader ${files} ${filter} ${sysapps} ${apps} ${inet}
	./mkdisk loader ${addprefix ${FILESDIR}/, ${files}}  ${addprefix ${FILTERDIR}/, ${filter}} ${sysapps} ${apps} ${addprefix ${INETDIR}/, ${inet}} ${MANPAGES} csarom csarom_romtest csakernel csakernel_romtest csalib boot index.html 
	rm -f ${sysapps} ${apps} # csarom csakernel csalib

osa_romtest.d64: osa.d64
	cp osa.d64 osa_romtest.d64
	c1541 -attach osa_romtest.d64 -delete csakernel -rename csakernel_romtest csakernel
	#c1541 -attach osa_romtest.d64 -delete csarom -rename csarom_romtest csarom

loader: loader.bas
	petcat -w40 -o loader loader.bas

rom:
	(cd ..; ${MAKE} csarom.bin;)
	ln -sf ../csarom.bin
	echo "00 00 10" | xxd -r > csarom
	cat csarom.bin >> csarom

rom_romtest:
	(cd ..; ${MAKE} csarom_romtest.bin;)
	ln -sf ../csarom_romtest.bin
	echo "00 00 10" | xxd -r > csarom_romtest
	cat csarom_romtest.bin >> csarom_romtest

kernel:
	(cd ..; ${MAKE} csakernel.bin;)
	ln -sf ../csakernel.bin
	# prime target with load address 0x6000
	echo "00 00 60" | xxd -r > csakernel
	cat csakernel.bin >> csakernel

kernel_romtest:
	(cd ..; ${MAKE} csakernel_romtest.bin;)
	ln -sf ../csakernel_romtest.bin
	# prime target with load address 0x6000
	echo "00 00 60" | xxd -r > csakernel_romtest
	cat csakernel_romtest.bin >> csakernel_romtest

lib:
	(cd ..; ${MAKE} csalib.bin;)
	ln -sf ../csalib.bin
	# prime target with load address 0x4000
	echo "00 00 40" | xxd -r > csalib
	cat csalib.bin >> csalib

boot: boot.a65
	${XA} -o boot boot.a65

inirom: inirom.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DOSA2KERNEL=61440 inirom.a65 -o inirom;\
	if [ $$? -ne 0 ]; then rm -f inirom; fi)

clean:
	rm -f csarom csakernel csalib boot inirom osa.d64 loader
	rm -f csakernel_romtest.bin csakernel.bin csarom.bin csalib.bin osa.d64 osa_romtest.d64
	rm -f csakernel_romtest prom prom_romtest
	rm -f csarom_romtest csarom_romtest.bin


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


