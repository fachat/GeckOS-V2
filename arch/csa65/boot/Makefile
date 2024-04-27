
OSA2KERNEL=57856        # $e200

BASE=../../../dist/osabase.d80
TRG=geckoscsa.d80

ROM=../csakernel ../csalib ../csarom

XAINPUT=../../../include
XA=xa

EMU=xcsa

all: $(TRG) 

#MANPAGES=../../../*/*/*.1.adoc

#########################################################################
#
# disk images and emurun
#

$(TRG): $(BASE) rom kernel lib boot loader 
	cp $(BASE) $@
	c1541 -attach $@ -delete place4loader
	c1541 -attach $@ -write loader -write csarom -write csakernel -write csalib -write boot

romtest.d80: $(TRG)
	cp $(TRG) $@
	c1541 -attach $@ -delete csarom -write csarom_romtest 

emurun: $(TRG)
	$(EMU) 

#########################################################################
#
# rom images
#

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

#########################################################################
#
# dependencies
#

loader: loader.bas
	petcat -w40 -o loader loader.bas

boot: boot.a65
	${XA} -DOSA2KERNEL=$(OSA2KERNEL) -o boot boot.a65

inirom: inirom.a65
	(XAINPUT=${XAINPUT}; export XAINPUT;\
	${XA} -DOSA2KERNEL=61440 inirom.a65 -o inirom;\
	if [ $$? -ne 0 ]; then rm -f inirom; fi)

$(BASE):
	make -C ../../.. all


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

