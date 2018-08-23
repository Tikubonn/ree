
all:
	make ree-node-pool.lib

clean:
	rm -f compiled/allocate-node-from-ree-node-pool.o
	rm -f compiled/init-ree-node-pool.o
	rm -f compiled/get-ree-node-pool.o
	rm -f compiled/clear-ree-node-pool.o
	rm -f compiled/ree-node-pool-length.o
	rm -f compiled/ree-node-pool-max-length.o
	rm -f compiled/copy-ree-node-pool-manually.o

ree-node-pool.lib: compiled/allocate-node-from-ree-node-pool.o compiled/init-ree-node-pool.o compiled/get-ree-node-pool.o compiled/clear-ree-node-pool.o compiled/ree-node-pool-length.o compiled/ree-node-pool-max-length.o compiled/copy-ree-node-pool-manually.o
	rm -f ree-node-pool.lib
	ar r ree-node-pool.lib compiled/allocate-node-from-ree-node-pool.o compiled/init-ree-node-pool.o compiled/get-ree-node-pool.o compiled/clear-ree-node-pool.o compiled/ree-node-pool-length.o compiled/ree-node-pool-max-length.o compiled/copy-ree-node-pool-manually.o

compiled/allocate-node-from-ree-node-pool.o: src/allocate-node-from-ree-node-pool.c
	$(CC) $(CFLAGS) -c src/allocate-node-from-ree-node-pool.c -o compiled/allocate-node-from-ree-node-pool.o

compiled/init-ree-node-pool.o: src/init-ree-node-pool.c
	$(CC) $(CFLAGS) -c src/init-ree-node-pool.c -o compiled/init-ree-node-pool.o

compiled/get-ree-node-pool.o: src/get-ree-node-pool.c 
	$(CC) $(CFLAGS) -c src/get-ree-node-pool.c -o compiled/get-ree-node-pool.o

compiled/clear-ree-node-pool.o: src/clear-ree-node-pool.c 
	$(CC) $(CFLAGS) -c src/clear-ree-node-pool.c -o compiled/clear-ree-node-pool.o

compiled/ree-node-pool-length.o: src/ree-node-pool-length.c 
	$(CC) $(CFLAGS) -c src/ree-node-pool-length.c -o compiled/ree-node-pool-length.o

compiled/ree-node-pool-max-length.o: src/ree-node-pool-max-length.c 
	$(CC) $(CFLAGS) -c src/ree-node-pool-max-length.c -o compiled/ree-node-pool-max-length.o

compiled/copy-ree-node-pool-manually.o: src/copy-ree-node-pool-manually.c 
	$(CC) $(CFLAGS) -c src/copy-ree-node-pool-manually.c -o compiled/copy-ree-node-pool-manually.o
