
export CC := gcc
export CFLAGS := -I$(CURDIR) -L$(CURDIR) -g3
export ROOTDIR := $(CURDIR)

all:
	make -C manual
	make -C auto
	make dist/ree.lib
	make dist/ree.dll
	
clean:
	make clean -C manual
	make clean -C auto

temp = $(shell mktemp -d)

dist/ree.lib: manual/manual.lib auto/auto.lib
	rm -f dist/ree.lib
	cd $(temp) && \
	ar x $(ROOTDIR)/manual/manual.lib && \
	ar x $(ROOTDIR)/auto/auto.lib && \
	ar r $(ROOTDIR)/dist/ree.lib *.o

dist/ree.dll: manual/manual.lib auto/auto.lib
	rm -f dist/ree.dll
	cd $(temp) && \
	ar x $(ROOTDIR)/manual/manual.lib && \
	ar x $(ROOTDIR)/auto/auto.lib && \
	$(CC) $(CFLAGS) -shared -o $(ROOTDIR)/dist/ree.dll *.o
