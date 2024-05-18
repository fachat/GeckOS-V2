

TRG=geckos64.d64

BASE=../../../dist/osabase.d64
ROM=c64rom.bin

XA=xa

X64=x64sc

all: $(TRG)

##############################################################################
#
# dependencies
#

boot.bin: boot.a65
	${XA} -o $@ $<

loader: loader.bas
	petcat -w2 -o $@ $<

# init rom image
$(ROM):
	make -C .. all
	reloc65 -xt -o $(ROM) ../c64rom.o65

# base d64 distribution file
$(BASE):
	make -C ../../.. all

##############################################################################
#
# d64 emulator disk image + run
#

$(TRG): $(BASE) $(ROM) boot.bin loader 
	cp $(BASE) $@
	c1541 -attach $@ -delete place4loader
	c1541 -attach $@ -write loader -write boot.bin -write $(ROM) 
	
emurun: $(TRG)
	${X64} -autostart $(TRG)

emuslip: $(TRG)
	${X64} -rsuser -rsuserdev 2 -rsuserbaud 9600 -rsdev3 "|socat - PTY,link=/tmp/viceser" -autostart $(TRG)

##############################################################################
#
# clean up
#

clean:
	rm -f $(ROM)
	rm -f boot.bin loader
	rm -f monitor.log

topclean:
	# convenience
	make -C ../../.. clean
	
