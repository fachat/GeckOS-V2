
BASE=../../../dist/osabase.d80
TRG=geckoscsa.d80

ROM=../csakernel ../csalib ../csarom

XAINPUT=../../../include
XA=xa

all: $(TRG) prom prom_romtest

#MANPAGES=../../../*/*/*.1.adoc

prom: rom kernel lib
	((cat ../csarom.bin /dev/zero | dd bs=1024 count=18 ) && cat ../csalib.bin ../csakernel.bin) > prom

prom_romtest: rom kernel_romtest lib
	((cat ../csarom_romtest.bin /dev/zero | dd bs=1024 count=18 ) && cat ../csalib.bin ../csakernel_romtest.bin) > prom_romtest

$(TRG): $(BASE) rom kernel lib boot loader 
	cp $(BASE) $@
	c1541 -attach $@ -delete place4loader
	c1541 -attach $@ -write loader -write csarom -write csakernel -write csalib -write boot

romtest.d80: $(TRG)
	cp $(TRG) $@
	c1541 -attach $@ -delete csarom -write csarom_romtest 

loader: loader.bas
	petcat -w40 -o loader loader.bas

rom:
	(cd ..; ${MAKE} csarom.bin;)
	echo "00 00 08" | xxd -r > csarom
	cat ../csarom.bin >> csarom

rom_romtest:
	(cd ..; ${MAKE} csarom_romtest.bin;)
	echo "00 00 10" | xxd -r > csarom_romtest
	cat ../csarom_romtest.bin >> csarom_romtest

kernel:
	(cd ..; ${MAKE} csakernel.bin;)
	# prime target with load address 0x6000
	echo "00 00 60" | xxd -r > csakernel
	cat ../csakernel.bin >> csakernel

kernel_romtest:
	(cd ..; ${MAKE} csakernel_romtest.bin;)
	# prime target with load address 0x6000
	echo "00 00 60" | xxd -r > csakernel_romtest
	cat ../csakernel_romtest.bin >> csakernel_romtest

lib:
	(cd ..; ${MAKE} csalib.bin;)
	# prime target with load address 0x4000
	echo "00 00 40" | xxd -r > csalib
	cat ../csalib.bin >> csalib

boot: boot.a65
	${XA} -o boot boot.a65

inirom: inirom.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DOSA2KERNEL=61440 inirom.a65 -o inirom;\
	if [ $$? -ne 0 ]; then rm -f inirom; fi)

#########################################################################
#
# clean up
#

clean:
	rm -f csarom csakernel csalib boot inirom loader
	rm -f csakernel_romtest.bin csakernel.bin csarom.bin csalib.bin osa_romtest.d64
	rm -f csakernel_romtest prom prom_romtest
	rm -f csarom_romtest csarom_romtest.bin

topclean:
	make -C ../../.. clean

