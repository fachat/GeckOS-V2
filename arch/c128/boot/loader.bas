

   10 on a goto 50
   15 print chr$(14)
   20 a=1
   30 print "Loading bootloader"
   40 load"romld.bin",8,1
   50 print "Loading GeckOS/A65 images"
   90 sys 3*4096:rem call bootloader


