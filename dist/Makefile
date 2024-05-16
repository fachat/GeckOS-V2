
IMGS=osabase.d64 osanonet.d64 osabase.d80

all: $(IMGS)

APPS=cat hexdump lmon lsh basic wc
SYS=kill lsmem ontty ps
DISK=chkdsk format mkdir ls more mv rm rmdir 
INET=httpd telnet tlogin index.html
SLIP=slipd slipmind 
TEST=sample.bat testcon

osabase.d80: $(APPS) $(SYS) $(DISK) $(INET) $(SLIP) $(TEST)
	./mkdisk d80 $@ place4loader $(APPS) $(SYS) $(DISK) $(INET) $(SLIP) $(TEST)

osabase.d64: $(APPS) $(SYS) $(DISK) $(INET) $(SLIP) $(TEST)
	./mkdisk d64 $@ place4loader $(APPS) $(SYS) $(DISK) $(INET) $(SLIP) $(TEST)

osanonet.d64: $(APPS) $(SYS) $(DISK) $(TEST)
	./mkdisk d64 $@ place4loader $(APPS) $(SYS) $(DISK) $(TEST)

clean:
	rm -f $(IMGS)

