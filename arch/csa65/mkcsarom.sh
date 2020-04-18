#!/bin/sh
#
# build the GeckOS ROM image for CS/A

# note. csa_magic is only used it init uses INIT_MMU
#FILES="csa_magic csa_devices csa_init csa_fsdev csa_fsiec"
FILES="csa_devices csa_init csa_fsdev csa_fsiec csa_lsh csa_end"

########################################
# first part: csa_magic

# ROMSTART
next_bt="-bt 32768"	

for i in ${FILES}; do

	# reloc to ROM location
	reloc65 $next_bt -o $i-reloc.o65 $i.o65
	# get start of next binary
	# only map text segment, zero/data/bss are done using MMU mapping
	next_bt=`file65 -P $i-reloc.o65 | sed -e 's/-bd.*//g'`
	# extract binary
	reloc65 -xt -o $i $i-reloc.o65
done

cat ${FILES} > csarom
