

BASE=../../../dist/osanonet.d64
ROM=../rom

TRG=geckospet.d64

all: $(TRG)

rom:
	(cd ..; ${MAKE} boot/$@;)

loader: loader.bas
	petcat -w40 -o loader loader.bas

clean:
	rm -f loader
	rm -f ${sysapps}
	rm -f vice.trace reltest

topclean:
	# convenience
	make -C ../../.. clean

$(ROM):
	make -C .. all

$(BASE):
	make -C ../../../ all

##############################################################################
#
# d64 emulator disk image + run
#

$(TRG): $(BASE) $(ROM) loader 
	cp $(BASE) $@
	c1541 -attach $@ -delete place4loader
	c1541 -attach $@ -write loader -write $(ROM)

emurun: $(TRG)
	xpet -model 4032 -autostart $(TRG)



	
