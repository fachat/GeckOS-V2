
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
	rm -f c64rom boot slip test test2 ktest test osa.d64 tstenv 
	rm -f ${files} ${sysapps} ${apps} ${inet}
	rm -f vice.trace reltest

tar ../boot.tgz: boot c64rom loader charom index.html slip howto.boot
	tar czvf ../boot.tgz boot c64rom loader charom index.html slip howto.boot

ktest: ktest.a65
	(XAINPUT=../../../; export XAINPUT; ${XA} -DSTDIOADDR=53248 -DKERNEL=61440 ktest.a65 -o ktest)

ttest2: test2.a65
	(XAINPUT=../../../; export XAINPUT; ${XA} -DSTDIOADDR=53248 -DKERNEL=61440 test2.a65 -o test2)

test: test.a65
	(XAINPUT=../../../include; export XAINPUT; ${XA} -R -DSTDIOADDR=53248 test.a65 -o test)

tstenv: tstenv.a65
	${XA} -R -I ../../../include -DSTDIOADDR=53248 tstenv.a65 -o tstenv

reltest: reltest.a65
	${XA} -R reltest.a65 -LOSA2KERNEL -LLIB6502 -o reltest

##############################################################################
#
# d64 emulator disk image + run
#

osa.d64: ${files} ${sysapps} ${apps} ${inet} c64rom boot loader charom index.html
	./mkdisk ${files} ${sysapps} ${apps} ${inet} c64rom boot loader charom index.html

emurun: osa.d64
	x64+rs232 -1541 -8 osa.d64

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

	
