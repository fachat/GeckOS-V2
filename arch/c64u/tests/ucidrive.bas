
100 rem test program for the ultimate command interface
101 rem 
102 rem the uci uses addresses $df1c-$df1f
110 rem
112 rem these tests access the uci target drive 0
199 rem

200 i=57116
210 cs=i:rem control (write) and status (read)
212 cd=i+1:rem cmd data (write) and id (read)
214 rd=i+2:rem response data (read)
216 sd=i+3:rem status data (read)

300 tr=1:rem dos target


1000 rem dos cmd identify
1010 gosub 9000:rem ensure idle
1020 poke cd,tr:rem target
1030 poke cd,1
1032 poke cd,1
1040 poke cs,1:rem push

1100 rem read response
1110 gosub 9100
1120 end

9000 rem check for idle
9010 s=peek(cs)
9020 s=(s/16)and3
9030 on s+1 goto 9060,9070,9080,9090
9040 print "error":end
9060 print "idle":return
9070 print "command busy":end
9080 print "data last":goto 9095
9090 print "data next":goto 9095
9095 poke cs,2+8:rem ack, clr err
9099 return

9100 rem print out status
9110 s=peek(cs)
9120 if s and 64 then print chr$(peek(sd));:goto 9110
9130 return

