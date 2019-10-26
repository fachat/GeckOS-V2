

XA=xa

all: init.o65 initmmu.o65

init.o65: init.a65
	${XA} -I../../include -DINIT_RESTART -DROMSTART=\$8000 -DOSA2KERNEL=61440 -R init.a65 -o init.o65;

initmmu.o65: init.a65
	${XA} -DINIT_RESTART -DINIT_MMU -DINIT_MMU_BANK=2 -I../../include -DROMSTART=\$8000 -DOSA2KERNEL=61440 -R init.a65 -o initmmu.o65;

clean:
	rm -f init.o65 initmmu.o65

