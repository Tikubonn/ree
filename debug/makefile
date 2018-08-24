
all:
	make -C dump
	make debug.lib

clean:
	make clean -C dump

temp = $(shell mktemp -d)

debug.lib: dump/dump.lib
	rm -f debug.lib
	cd $(temp) && \
	ar x $(ROOTDIR)/debug/dump/dump.lib && \
	ar r $(ROOTDIR)/debug/debug.lib *.o
