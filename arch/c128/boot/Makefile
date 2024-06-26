
BASE=../../../dist/osabase.d64

ROM=kern.bin lib.bin rom40.bin rom80.bin

XA=xa -I..
RELOC=reloc65

TRG=geckos128.d64

all: $(TRG)

##############################################################################
#
# dependencies
#

romld.bin: romld.a65
	$(XA) romld.a65 -o romld.bin

loader: loader.bas romld.bin
	petcat -w70 -o loader loader.bas

../kern.o65 ../lib.o65 ../rom.o65:
	make -C .. all

#
# Note: this loads the binaries directly at their desired locations
# 	which means:
#
#	a) the load address must correspond to the text segment start address
#	b) the romld loader must copy that directly into RAM under ROM
#

kern.bin: ../kern.o65
	# add kernel load address
	file65 ../kern.o65 | grep text | tr -s " " | cut -d " " -f 5 | sed -e 's/\$$//g' -e 's/\(..\)\(..\)/\2 \1/' | xxd -r -p > kern.bin
	$(RELOC) -xt -o tmp ../kern.o65
	cat tmp >> kern.bin

lib.bin: ../lib.o65 
	# add lib load address
	# note we're using 0400 instead of the real 0300, as this would overwrite important c128 vectors
	# so the romld loader needs to move the binary one block down
	#file65 ../lib.o65 | grep text | tr -s " " | cut -d " " -f 5 | sed -e 's/\$$//g' -e 's/\(..\)\(..\)/\2 \1/' | xxd -r -p > lib.bin
	echo "00 40" | xxd -r -p > lib.bin
	$(RELOC) -xt -o tmp ../lib.o65
	cat tmp >> lib.bin

rom40.bin: ../rom40.o65 
	# add rom40 load address
	file65 ../rom40.o65 | grep text | tr -s " " | cut -d " " -f 5 | sed -e 's/\$$//g' -e 's/\(..\)\(..\)/\2 \1/' | xxd -r -p > rom40.bin
	$(RELOC) -xt -o tmp ../rom40.o65
	cat tmp >> rom40.bin
	rm -f tmp

rom80.bin: ../rom80.o65 
	# add rom80 load address
	file65 ../rom80.o65 | grep text | tr -s " " | cut -d " " -f 5 | sed -e 's/\$$//g' -e 's/\(..\)\(..\)/\2 \1/' | xxd -r -p > rom80.bin
	$(RELOC) -xt -o tmp ../rom80.o65
	cat tmp >> rom80.bin
	rm -f tmp

$(BASE):
	make -C ../../.. all

##############################################################################
#
# d64 emulator disk image + run
#

$(TRG): $(BASE) $(ROM) loader romld.bin
	make -C ..
	cp $(BASE) $@
	c1541 -attach $@ -delete place4loader
	c1541 -attach $@ -write loader -write romld.bin
	sh -c "for i in $(ROM); do\
		c1541 -attach $@ -write \$$i; \
	done;"


emurun: $(TRG)
	x128 -drive8type 1451 -autostart $(TRG)


##############################################################################
#
# clean up
#

clean:
	rm -f rom romld.bin loader *.bin
	rm -f monitor.log

topclean:
	# convenience
	(cd ../../../; make clean);

	
