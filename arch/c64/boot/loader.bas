

;loader ==0801==
    5 on a goto 110, 120, 130
   10 print  "set basic end"
   20 poke 56, 16
   30 clr
   90 a=1
   91 ad=peek(186)
   92 if ad < 8 or ad > 11 then ad = 8
   95 rem print"load charom"
  100 rem load"charom",ad,1
  110 a=2
  112 print"load rom image"
  115 load"c64rom.bin",ad,1
  120 a=3
  122 print"load boot routine"
  125 load"boot.bin",ad,1
  130 print"start csa65"
  135 sys 12*256

