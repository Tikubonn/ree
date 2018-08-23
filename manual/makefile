
all:
	make -C ree-node
	make -C ree-node-pool
	make -C ree-string
	make -C ree-stream
	make -C ree
	make -C ree-region
	make manual.lib

clean:
	make clean -C ree-node
	make clean -C ree-node-pool
	make clean -C ree-string
	make clean -C ree-stream
	make clean -C ree
	make clean -C ree-region

temp = $(shell mktemp -d)

manual.lib: ree-node/ree-node.lib ree-node-pool/ree-node-pool.lib ree-string/ree-string.lib ree-stream/ree-stream.lib ree/ree.lib ree-region/ree-region.lib
	rm -f manual.lib
	cd $(temp) && \
	ar x $(ROOTDIR)/manual/ree-node/ree-node.lib && \
	ar x $(ROOTDIR)/manual/ree-node-pool/ree-node-pool.lib && \
	ar x $(ROOTDIR)/manual/ree-string/ree-string.lib && \
	ar x $(ROOTDIR)/manual/ree-stream/ree-stream.lib && \
	ar x $(ROOTDIR)/manual/ree/ree.lib && \
	ar x $(ROOTDIR)/manual/ree-region/ree-region.lib && \
	ar r $(ROOTDIR)/manual/manual.lib *.o
