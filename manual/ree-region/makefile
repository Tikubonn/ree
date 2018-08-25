
all:
	make ree-region.lib

clean:
	rm -f compiled/init-ree-region.o
	rm -f compiled/get-ree-region.o
	rm -f compiled/ree-region-length.o
	rm -f compiled/copy-ree-region-manually.o
	rm -f compiled/read-ree-region.o

ree-region.lib: compiled/init-ree-region.o compiled/get-ree-region.o compiled/ree-region-length.o compiled/copy-ree-region-manually.o compiled/read-ree-region.o
	ar r ree-region.lib compiled/init-ree-region.o compiled/get-ree-region.o compiled/ree-region-length.o compiled/copy-ree-region-manually.o compiled/read-ree-region.o

compiled/init-ree-region.o: src/init-ree-region.c 
	$(CC) $(CFLAGS) -c src/init-ree-region.c -o compiled/init-ree-region.o

compiled/get-ree-region.o: src/get-ree-region.c 
	$(CC) $(CFLAGS) -c src/get-ree-region.c -o compiled/get-ree-region.o

compiled/ree-region-length.o: src/ree-region-length.c 
	$(CC) $(CFLAGS) -c src/ree-region-length.c -o compiled/ree-region-length.o

compiled/copy-ree-region-manually.o: src/copy-ree-region-manually.c 
	$(CC) $(CFLAGS) -c src/copy-ree-region-manually.c -o compiled/copy-ree-region-manually.o

compiled/read-ree-region.o: src/read-ree-region.c 
	$(CC) $(CFLAGS) -c src/read-ree-region.c -o compiled/read-ree-region.o
