
version="2.1.1"

all:
	(cd apps; ${MAKE};)
	(cd sysapps; ${MAKE};)
	(cd tests; ${MAKE};)
	(cd dist; ${MAKE};)

clean:
	(cd arch; ${MAKE} clean;)
	(cd apps; ${MAKE} clean;)
	(cd sysapps; ${MAKE} clean;)
	(cd kernel; ${MAKE} clean;)
	(cd lib6502; ${MAKE} clean;)
	(cd dist; ${MAKE} clean;)
	(cd tests; ${MAKE} clean;)

dclean: clean
	git checkout */*/*/*.d64
	git checkout */*/*/*.d80

#####################################################

XCSA=~/8bit/xcbm/bin/xcsa

#####################################################

cbm8x96: clean
	(cd arch/cbm8x96; make; cd boot; make)

runcbm8x96: cbm8x96
	xpet +sound -model 8296 -autostart arch/cbm8x96/boot/geckos8x96.d64

##########

c64: clean
	(cd arch/c64; make; cd boot; make)

runc64: c64
	x64 +sound -autostart arch/c64/boot/geckos64.d64

runc64ip: c64
	x64 +sound -acia1 -acia1base 0xDE00 -acia1irq 1 -acia1mode 1 -myaciadev 2  -rsdev3 "|socat - PTY,link=/tmp/viceser" -autostart arch/c64/boot/geckos64.d64

##########

c128: clean
	(cd arch/c128; make; cd boot; make)

runc128: c128
	x128 +sound -autostart arch/c128/boot/geckos128.d64

runc128ip: c128
	x128 +sound -acia1 -acia1base 0xDE00 -acia1irq 1 -acia1mode 1 -myaciadev 2  -rsdev3 "|socat - PTY,link=/tmp/viceser" -autostart arch/c128/boot/geckos64.d64

##########

pet32k: clean
	(cd arch/pet32k; make; cd boot; make)

runpet32k: pet32k
	xpet +sound -model 4032 -autostart arch/pet32k/boot/geckospet.d64

##########

csa65: clean
	(cd arch/csa65; make; cd boot; make)

runcsa65: csa65
	(cd arch/csa65/boot; $(XCSA))


