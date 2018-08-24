
export CC := gcc
export CFLAGS := -I$(CURDIR) -L$(CURDIR) -g3
export MAKEFLAGS := -r
export ROOTDIR := $(CURDIR)

all:
	make -C manual
	make -C auto
	make -C debug
	make dist/ree.lib
	make dist/ree.dll
	make test.exe
	
clean:
	make clean -C manual
	make clean -C auto
	make clean -C debug

temp = $(shell mktemp -d)

dist/ree.lib: manual/manual.lib auto/auto.lib debug/debug.lib
	rm -f dist/ree.lib
	cd $(temp) && \
	ar x $(ROOTDIR)/manual/manual.lib && \
	ar x $(ROOTDIR)/auto/auto.lib && \
	ar x $(ROOTDIR)/debug/debug.lib && \
	ar r $(ROOTDIR)/dist/ree.lib *.o

dist/ree.dll: manual/manual.lib auto/auto.lib debug/debug.lib
	rm -f dist/ree.dll
	cd $(temp) && \
	ar x $(ROOTDIR)/manual/manual.lib && \
	ar x $(ROOTDIR)/auto/auto.lib && \
	ar x $(ROOTDIR)/debug/debug.lib && \
	$(CC) $(CFLAGS) -shared -o $(ROOTDIR)/dist/ree.dll *.o

test.exe: test.c dist/ree.lib
	$(CC) $(CFLAGS) test.c dist/ree.lib -o test.exe
