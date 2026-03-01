
# Tests for the C64 Ultimate

The C64 ultimate has a disk drive emulation - however, when using it via the C64
serial IEC bus, the whole machine grinds down to its original 1MHz speed, no matter
what other speed is set. Therefore, using an IEC disk drive (wether real or emulated)
is a moot point if you want to use the speed that the machine is capable of.

Therfore, the Ultimate command interface is being used to access the host filesystem
directly through some I/O locations at full speed.

This folder contains some tests, before porting a GeckOS filesystem task to it.

* https://github.com/GideonZ/1541ultimate/blob/master/doc/Command%20Interface%20V1.0.pdf

