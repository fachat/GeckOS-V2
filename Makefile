
version="2.1.1"

all:
	(cd apps; ${MAKE};)
	(cd sysapps; ${MAKE};)

clean:
	(cd arch; ${MAKE} clean;)
	(cd apps; ${MAKE} clean;)
	(cd sysapps; ${MAKE} clean;)
	(cd kernel; ${MAKE} clean;)
	(cd lib6502; ${MAKE} clean;)

#####################################################

XCSA=~/8bit/xcbm/bin/xcsa

#####################################################

cbm8x96: clean
	(cd arch/cbm8x96; make; cd boot; make)

runcbm8x96: cbm8x96
	xpet +sound -model 8296 -autostart arch/cbm8x96/boot/osa.d64

##########

c64: clean
	(cd arch/c64; make; cd boot; make)

runc64: c64
	x64 +sound -autostart arch/c64/boot/osa.d64

runc64ip: c64
	x64 +sound -acia1 -acia1base 0xDE00 -acia1irq 1 -acia1mode 1 -myaciadev 2  -rsdev3 "|socat - PTY,link=/tmp/viceser" -autostart arch/c64/boot/osa.d64

##########

pet32k: clean
	(cd arch/pet32k; make; cd boot; make)

runpet32k: pet32k
	xpet +sound -model 4032 -autostart arch/pet32k/boot/osa.d64

##########

csa65: clean
	(cd arch/csa65; make; cd boot; make)

runcsa65: csa65
	(cd arch/csa65/boot; $(XCSA))


