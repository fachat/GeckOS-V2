#!/bin/bash

#cat $@ | sed -e 's/ 0x/ /g' | cut -d , -f 1,2,3 | tr -d , | awk '{print "al "$$2" ."$$1"_"$$3;}' 
cat $@ | sed -e 's/ 0x/ /g' | cut -d , -f 1,2,3 | tr -d , | awk '{print "al "$2" ."$1"_"$3;}'

