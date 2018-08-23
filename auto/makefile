
all:
	make -C ree
	make -C ree-node-pool
	make -C ree-string 
	make auto.lib

clean:
	make clean -C ree
	make clean -C ree-node-pool
	make clean -C ree-string 

temp = $(shell mktemp -d)

auto.lib: ree/ree.lib ree-node-pool/ree-node-pool.lib ree-string/ree-string.lib
	rm -f auto.lib
	cd $(temp) && \
	ar x $(ROOTDIR)/auto/ree/ree.lib && \
	ar x $(ROOTDIR)/auto/ree-node-pool/ree-node-pool.lib && \
	ar x $(ROOTDIR)/auto/ree-string/ree-string.lib && \
	ar r $(ROOTDIR)/auto/auto.lib *.o
