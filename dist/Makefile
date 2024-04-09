
IMGS=osabase.d64 osanonet.d64

all: $(IMGS)

APPS=cat hexdump lmon lsh basic wc
SYS=kill lsmem ontty ps
DISK=chkdsk format mkdir ls more mv rm rmdir 
INET=httpd telnet tlogin
SLIP=slipd slipmind

osabase.d64: $(APPS) $(SYS) $(DISK) $(INET) $(SLIP)
	./mkdisk $@ place4loader $(APPS) $(SYS) $(DISK) $(INET) $(SLIP)

osanonet.d64: $(APPS) $(SYS) $(DISK) 
	./mkdisk $@ place4loader $(APPS) $(SYS) $(DISK) 

clean:
	rm -f $(IMGS)

