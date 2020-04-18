
XAINPUT=../../../include
XA=xa

all: osa.d64

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


osa.d64: csarom csakernel csalib boot loader ${files} ${filter} ${sysapps} ${apps} ${inet}
	./mkdisk loader ${addprefix ${FILESDIR}/, ${files}}  ${addprefix ${FILTERDIR}/, ${filter}} ${sysapps} ${apps} ${addprefix ${INETDIR}/, ${inet}} ${MANPAGES} csarom csakernel csalib boot index.html 
	rm -f ${sysapps} ${apps}

loader: loader.bas
	petcat -w40 -o loader loader.bas

csarom:
	(cd ..; ${MAKE} csarom;)
	ln -s ../csarom

csakernel:
	(cd ..; ${MAKE} csakernel;)
	ln -s ../csakernel

csalib:
	(cd ..; ${MAKE} csalib;)
	ln -s ../csalib

boot: boot.a65
	${XA} -o boot boot.a65

inirom: inirom.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DOSA2KERNEL=61440 inirom.a65 -o inirom;\
	if [ $$? -ne 0 ]; then rm -f inirom; fi)

clean:
	rm -f csarom csakernel csalib boot inirom osa.d64 loader


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


