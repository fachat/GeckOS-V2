

BASE=../../../dist/osanonet.d64
ROM=../rom.bin

TRG=geckospet.d64

all: $(TRG)

##############################################################################
#
# dependencies
#

romld.bin: romld.a65
	xa -o $@ $<

loader: loader.bas
	petcat -w40 -o loader loader.bas

# init rom image
$(ROM):
	make -C .. all

# base d64 distribution file
$(BASE):
	make -C ../../../ all

##############################################################################
#
# d64 emulator disk image + run
#

$(TRG): $(BASE) $(ROM) loader romld.bin
	cp $(BASE) $@
	c1541 -attach $@ -delete place4loader
	c1541 -attach $@ -write loader -write romld.bin -write $(ROM) 

emurun: $(TRG)
	xpet -model 4032 -autostart $(TRG)


##############################################################################
#
# clean up
#

clean:
	rm -f loader romld.bin
	rm -f ${sysapps}
	rm -f vice.trace reltest

topclean:
	# convenience
	make -C ../../.. clean

