

XA=xa

all: init.o65

init.o65: init.a65
	${XA} -I../../include -DROMSTART=\$8000 -DKERNEL=61440 -R init.a65 -o init.o65;

clean:
	rm -f init.o65

