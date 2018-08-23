
all:
	make ree-node-pool.lib

clean:
	rm -f compiled/allocate-ree-node-pool.o
	rm -f compiled/free-ree-node-pool.o
	rm -f compiled/copy-ree-node-pool.o

ree-node-pool.lib: compiled/allocate-ree-node-pool.o compiled/free-ree-node-pool.o compiled/copy-ree-node-pool.o
	rm -f ree-node-pool.lib
	ar r ree-node-pool.lib compiled/allocate-ree-node-pool.o compiled/free-ree-node-pool.o compiled/copy-ree-node-pool.o

compiled/allocate-ree-node-pool.o: src/allocate-ree-node-pool.c 
	$(CC) $(CFLAGS) -c src/allocate-ree-node-pool.c -o compiled/allocate-ree-node-pool.o

compiled/free-ree-node-pool.o: src/free-ree-node-pool.c 
	$(CC) $(CFLAGS) -c src/free-ree-node-pool.c -o compiled/free-ree-node-pool.o

compiled/copy-ree-node-pool.o: src/copy-ree-node-pool.c 
	$(CC) $(CFLAGS) -c src/copy-ree-node-pool.c -o compiled/copy-ree-node-pool.o
