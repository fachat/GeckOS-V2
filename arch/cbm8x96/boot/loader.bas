

;loader ==0401==
   10 on a goto 50
   15 poke59468,14
   20 a=1
   30 print "Loading bootloader"
   40 load"romld.bin",8
   50 print "Loading GeckOS/A65 images"
   60 open 1,8,2, "lib.bin,r"
   70 open 2,8,3, "rom.bin,r"
   80 open 3,8,4, "kern.bin,r"
   90 sys 7*4096:rem call bootloader


