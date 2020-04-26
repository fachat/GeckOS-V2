#!/bin/sh
#
# build the GeckOS ROM image for CS/A

OUT="$1"
shift 1;

FILES="$@"

# ROMSTART
next_bt="-bt 32768"	

rm -f ${OUT}

for i in ${FILES}; do

	i=${i%.o65}
	echo "i="$i
	# reloc to ROM location
	reloc65 $next_bt -o $i-reloc.o65 $i.o65
	# get start of next binary
	# only map text segment, zero/data/bss are done using MMU mapping
	next_bt=`file65 -P $i-reloc.o65 | sed -e 's/-bd.*//g'`
	# extract binary
	reloc65 -xt -o $i $i-reloc.o65
	cat $i >> ${OUT}
done

