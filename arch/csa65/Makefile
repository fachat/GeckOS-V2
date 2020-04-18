

XA=xa #-2.1.4h

FILE=file65
RELOC=reloc65

all: boot/csarom #boot/csarom2

redo:
	rm -f boot/csarom
	make
	cp boot/csarom /site/mystuff/var/lptiec
	cat foo

boot/csaold: csarom.old
	${XA} -I../.. -I../../include -bt 32768 \
		csarom.old -o boot/csaold -l csaold.lab

csa boot/csarom: csarom.a65
	${XA} -I../.. -I../../include -R -bt 32768 \
		csarom.a65 -o boot/csarom -l csarom.lab

boot/csarom2: csarom2.a65
	${XA} -I../.. -I../../include -bt 32768 \
		csarom2.a65 -o boot/csarom2 -l csarom2.lab

clean:
	rm -f csarom.lab csarom2.lab csaold.lab 
	rm -f csakernel csakernel.o65 csakernel.lab
	rm -f csalib csalib.o65 csalib.lab
	(cd boot; ${MAKE} clean ;)
	(cd apps; ${MAKE} clean ;)
	(cd sysapps; ${MAKE} clean ;)

csakernel: ../../kernel/*.a65 kernel/*.a65 csakernel.a65
	@echo "Building kernel at 0xE400 (with gap at E800-EFFF)"
	${XA} -I../.. -I../../include -R -bt 58368 -bz 8 -bd 768 -bb 2048 \
		-DSPLIT1K=61440 \
		-l csakernel.lab \
		-o csakernel.o65 \
		csakernel.a65
	${RELOC} -xt -o csakernel csakernel.o65

csalib: ../../lib6502/*.a65 csalib.a65
	@echo "Building lib at 0xCC00"
	${XA} -I../.. -I../../include -R -bt 51200 -bz 8 -bd 768 -bb 1536 \
		-DOSA2KERNEL=58368 \
		-DROMSTART=51200 \
		-l csalib.lab \
		-o csalib.o65 \
		csalib.a65
	${RELOC} -xt -o csalib csalib.o65

#.PHONY: kernel
	
