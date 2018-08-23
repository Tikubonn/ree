
all:
	make ree-stream.lib

clean:
	rm -f compiled/init-ree-stream.o
	rm -f compiled/init-ree-stream-from-string.o
	rm -f compiled/get-ree-stream.o
	rm -f compiled/peek-ree-stream.o
	rm -f compiled/seek-ree-stream.o
	rm -f compiled/ree-stream-index.o
	rm -f compiled/ree-stream-eof.o

ree-stream.lib: compiled/init-ree-stream.o compiled/init-ree-stream-from-string.o compiled/get-ree-stream.o compiled/peek-ree-stream.o compiled/seek-ree-stream.o compiled/ree-stream-index.o compiled/ree-stream-eof.o
	rm -f ree-stream.lib
	ar r ree-stream.lib compiled/init-ree-stream.o compiled/init-ree-stream-from-string.o compiled/get-ree-stream.o compiled/peek-ree-stream.o compiled/seek-ree-stream.o compiled/ree-stream-index.o compiled/ree-stream-eof.o

compiled/init-ree-stream.o: src/init-ree-stream.c 
	$(CC) $(CFLAGS) -c src/init-ree-stream.c -o compiled/init-ree-stream.o

compiled/init-ree-stream-from-string.o: src/init-ree-stream-from-string.c 
	$(CC) $(CFLAGS) -c src/init-ree-stream-from-string.c -o compiled/init-ree-stream-from-string.o

compiled/get-ree-stream.o: src/get-ree-stream.c 
	$(CC) $(CFLAGS) -c src/get-ree-stream.c -o compiled/get-ree-stream.o

compiled/peek-ree-stream.o: src/peek-ree-stream.c 
	$(CC) $(CFLAGS) -c src/peek-ree-stream.c -o compiled/peek-ree-stream.o

compiled/seek-ree-stream.o: src/seek-ree-stream.c 
	$(CC) $(CFLAGS) -c src/seek-ree-stream.c -o compiled/seek-ree-stream.o

compiled/ree-stream-index.o: src/ree-stream-index.c 
	$(CC) $(CFLAGS) -c src/ree-stream-index.c -o compiled/ree-stream-index.o

compiled/ree-stream-eof.o: src/ree-stream-eof.c 
	$(CC) $(CFLAGS) -c src/ree-stream-eof.c -o compiled/ree-stream-eof.o
