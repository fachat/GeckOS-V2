

XA=xa #-2.1.4h

FILE=file65
RELOC=reloc65

all: boot/csarom boot/csarom2

redo:
	rm -f boot/csarom
	make
	cp boot/csarom /site/mystuff/var/lptiec
	cat foo

boot/csaold: csarom.old
	${XA} -I../.. -I../../include -bt 32768 \
		csarom.old -o boot/csaold -l csaold.lab

csa boot/csarom: csarom.a65
	${XA} -I../.. -I../../include -bt 32768 \
		csarom.a65 -o boot/csarom -l csarom.lab

boot/csarom2: csarom2.a65
	${XA} -I../.. -I../../include -bt 32768 \
		csarom2.a65 -o boot/csarom2 -l csarom2.lab

clean:
	rm -f csarom.lab csarom2.lab csaold.lab
	(cd boot; ${MAKE} clean ;)
	(cd apps; ${MAKE} clean ;)
	(cd sysapps; ${MAKE} clean ;)

