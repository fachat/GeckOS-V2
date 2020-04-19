

XA=xa #-2.1.4h

FILE=file65
RELOC=reloc65

PARTS=csakernel csalib csa_init.o65 csa_magic.o65 csa_devices.o65 csa_fsdev.o65 csa_fsiec.o65 csa_lsh.o65 csa_end.o65

all: csarom

#all: boot/csarom #boot/csarom2

redo:
	rm -f boot/csarom
	make
	cp boot/csarom /site/mystuff/var/lptiec
	cat foo

boot/csaold: csarom.old
	${XA} -I../.. -I../../include -bt 32768 \
		csarom.old -o boot/csaold -l csaold.lab

#csa csarom: csarom.a65
#	${XA} -I../.. -I../../include -bt 32768 \
#		csarom.a65 -o csarom -l csarom.lab

boot/csarom2: csarom2.a65
	${XA} -I../.. -I../../include -bt 32768 \
		csarom2.a65 -o boot/csarom2 -l csarom2.lab

csarom: ${PARTS} mkcsarom.sh
	./mkcsarom.sh
	echo "00 00 10" | xxd -r > csarom
	cat csarom.bin >> csarom

clean:
	rm -f csarom.lab csarom2.lab csaold.lab 
	rm -f csakernel csakernel.o65 csakernel.lab csakernel.bin
	rm -f csalib csalib.o65 csalib.lab csalib.bin
	rm -f csarom csarom.o65 csarom.lab csarom.bin
	rm -f csa_devices csa_devices.o65 
	rm -f csa_init csa_init.o65 
	rm -f csa_magic csa_magic.o65 
	rm -f csa_fsdev csa_fsdev.o65 
	rm -f csa_fsiec csa_fsiec.o65 
	rm -f csa_lsh csa_lsh.o65 
	rm -f csa_end csa_end.o65 
	rm -f csa*-reloc.o65
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
	${FILE} csakernel.o65
	${RELOC} -xt -o csakernel.bin csakernel.o65
	# prime target with load address 0x6000
	echo "00 00 60" | xxd -r > csakernel
	cat csakernel.bin >> csakernel

csalib: ../../lib6502/*.a65 csalib.a65
	@echo "Building lib at 0xCC00"
	# note: ROMSTART here is shared ROM, so start of lib6502
	${XA} -I../.. -I../../include -R -bt 51200 -bz 8 -bd 768 -bb 1536 \
		-DOSA2KERNEL=58368 \
		-DROMSTART=51200 \
		-l csalib.lab \
		-o csalib.o65 \
		csalib.a65
	${FILE} csalib.o65
	${RELOC} -xt -o csalib.bin csalib.o65
	# prime target with load address 0x4000
	echo "00 00 40" | xxd -r > csalib
	cat csalib.bin >> csalib

csa_magic.o65: ../../sysapps/magic/* csa_magic.a65
	@echo "Building magic at 0x8000"
	${XA} -I../.. -I../../include -R -bt 32768 -bz 64 -bd 768 -bb 2048 \
		-DROMSTART=32768 \
		-o csa_magic.o65 \
		csa_magic.a65
	${FILE} $@

csa_init.o65: ../../sysapps/init/* csa_init.a65 csalib
	@echo "Building init at 0x8000"
	LIB6502=`hexdump -C csalib.o65 | grep LIB6502 | cut -d " " -f 18-20 | sed -e s/\ /" + 100*"/ | awk '{print toupper($$0)}' | sed -e "s/^/ibase=16; /" | bc`; \
	echo "LIB6502=$${LIB6502}"; \
	${XA} -I../.. -I../../include -R -bt 32768 -bz 64 -bd 768 -bb 2048 \
		-DOSA2KERNEL=58368 \
		-DLIB6502=$${LIB6502} \
		-DROMSTART=32768 \
		-o csa_init.o65 \
		csa_init.a65
	${FILE} $@

csa_devices.o65: ../../devices/* devices/* csa_devices.a65
	@echo "Building devices at 0x8000"
	${XA} -I../.. -I../../include -R -bt 32768 -bz 200 -bd 1800 -bb 3300 \
		-DOSA2KERNEL=58368 \
		-DROMSTART=32768 \
		-o csa_devices.o65 \
		csa_devices.a65
	${FILE} $@

csa_fsdev.o65: csa_fsdev.a65
	@echo "Building fsdev at 0x8000"
	${XA} -I../.. -I../../include -R -bt 32768 -bz 64 -bd 768 -bb 2048 \
		-DOSA2KERNEL=58368 \
		-DROMSTART=32768 \
		-o csa_fsdev.o65 \
		csa_fsdev.a65
	${FILE} $@

csa_fsiec.o65: csa_fsiec.a65
	@echo "Building fsiec at 0x8000"
	${XA} -I../.. -I../../include -R -bt 32768 -bz 64 -bd 768 -bb 2048 \
		-DOSA2KERNEL=58368 \
		-DROMSTART=32768 \
		-o csa_fsiec.o65 \
		csa_fsiec.a65
	${FILE} $@

csa_lsh.o65: csa_lsh.a65
	@echo "Building lsh at 0x8000"
	${XA} -I../.. -I../../include -R -bt 32768 -bz 64 -bd 768 -bb 2048 \
		-o csa_lsh.o65 \
		csa_lsh.a65
	${FILE} $@

csa_end.o65: csa_end.a65
	@echo "Building lsh at 0x8000"
	${XA} -I../.. -I../../include -R -bt 32768 -bz 64 -bd 768 -bb 2048 \
		-o csa_end.o65 \
		csa_end.a65
	${FILE} $@



#.PHONY: kernel
	
