#!/bin/sh

DIFFS=$1
INPUT=$2

seg=1

textoffset=
dataoffset=
bssoffset=
zerooffset=

cat $DIFFS | tr -s " " | cut -d " " -f 12 \
| { 
	while read n; do 
		if [ "X$n" != "X" ]; then
			seg=$(($seg+1))

			case $seg in
			2)
				textoffset=$n ;;
			3)
				dataoffset=$n ;;
			4)
				bssoffset=$n ;;
			5)
				zerooffset=$n ;;
			*)
			esac;
		fi;
	done; 

	cat $INPUT | ../reloclabels $textoffset $dataoffset $bssoffset $zerooffset 
}

