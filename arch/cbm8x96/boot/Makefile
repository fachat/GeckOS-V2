
BASE=../../../dist/osabase.d64

ROM=../kern.bin ../lib.bin ../rom.bin

XA=xa

TRG=geckos8x96.d64

all: $(TRG)

##############################################################################
#
# dependencies
#

romld.bin: romld.a65
	xa romld.a65 -o romld.bin

loader: loader.bas romld.bin
	petcat -l 0401 -w40 -o loader loader.bas

$(ROM):
	make -C .. all

$(BASE):
	make -C ../../.. all

##############################################################################
#
# d64 emulator disk image + run
#

$(TRG): $(BASE) $(ROM) loader romld.bin
	cp $(BASE) $@
	c1541 -attach $@ -delete place4loader
	c1541 -attach $@ -write loader -write romld.bin
	sh -c "for i in $(ROM); do\
		c1541 -attach $@ -write \$$i; \
	done;"


emurun: $(TRG)
	xpet -model 8296 -drive8type 2031 -autostart $(TRG)


##############################################################################
#
# clean up
#

clean:
	rm -f rom romld.bin loader
	rm -f monitor.log

topclean:
	# convenience
	(cd ../../../; make clean);

	
