
all:
	make ree-string.lib

clean:
	rm -f compiled/init-ree-string.o
	rm -f compiled/get-ree-string.o
	rm -f compiled/ree-string-length.o
	rm -f compiled/copy-ree-string-manually.o

ree-string.lib: compiled/init-ree-string.o compiled/get-ree-string.o compiled/ree-string-length.o compiled/copy-ree-string-manually.o
	rm -f ree-string.lib
	ar r ree-string.lib compiled/init-ree-string.o compiled/get-ree-string.o compiled/ree-string-length.o compiled/copy-ree-string-manually.o

compiled/init-ree-string.o: src/init-ree-string.c
	$(CC) $(CFLAGS) -c src/init-ree-string.c -o compiled/init-ree-string.o

compiled/get-ree-string.o: src/get-ree-string.c
	$(CC) $(CFLAGS) -c src/get-ree-string.c -o compiled/get-ree-string.o

compiled/ree-string-length.o: src/ree-string-length.c
	$(CC) $(CFLAGS) -c src/ree-string-length.c -o compiled/ree-string-length.o

compiled/copy-ree-string-manually.o: src/copy-ree-string-manually.c
	$(CC) $(CFLAGS) -c src/copy-ree-string-manually.c -o compiled/copy-ree-string-manually.o
