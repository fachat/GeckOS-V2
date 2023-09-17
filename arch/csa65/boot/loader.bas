

;loader ==0401==
   10 on a goto 50, 70, 90, 110
   20 poke59468,14
   30 print "Load GeckOS/A65 ROM Image @$0800"
   35 a=1
   40 load"csarom",8
   50 print "Load GeckOS/A65 library @$4000"
   55 a=2
   60 load"csalib",8
   70 print "Load GeckOS/A65 kernel @$6000"
   75 a=3
   80 load"csakernel",8
   90 print "Load boot code @$0c00"
   95 a=4
   100 load"boot",8
   110 print "Press key to Start GeckOS"
   115 rem get a$:if a$="" then 115
   120 sys 828: rem boot code

