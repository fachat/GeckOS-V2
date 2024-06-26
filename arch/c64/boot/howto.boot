
Howto Boot the C64 and the WWW server
-------------------------------------

1) build the "geckos64.d64" boot disk images using "make geckos64.d64"

2) put this disk to a VC1541 connected with a C64.

3) load the file "loader" on the C64 and run it
   After a while the new OS should come up and running
   (F1 switches between virtual terminals)

4) to start the WWW server, go to the shell (the '#' prompt) and type

   ontty a:video4 slipd c: c:tlogin a:ser1

   This starts the WWW server on serial line interface ser1, which is
   the 9600 baud userport interface by Daniel Dallmann. 
   (ser2 would be a 16550A UART at address $d600)
   Debug output goes to the fourth virtual console.

