

;loader ==0401==
   10 on a goto 50
   15 poke59468,14
   20 a=1
   30 print "Load GeckOS/A65 Image"
   40 load"rom",8
   50 print "Start GeckOS"
   60 sys 4926: rem text segment addr from makefile

