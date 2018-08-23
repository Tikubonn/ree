
all:
	make ree-string.lib

clean:
	rm -f compiled/allocate-ree-string.o
	rm -f compiled/copy-ree-string.o
	rm -f compiled/free-ree-string.o
	rm -f compiled/make-ree-string.o
	rm -f compiled/make-ree-string0.o

ree-string.lib: compiled/allocate-ree-string.o compiled/copy-ree-string.o compiled/free-ree-string.o compiled/make-ree-string.o compiled/make-ree-string0.o
	ar r ree-string.lib compiled/allocate-ree-string.o compiled/copy-ree-string.o compiled/free-ree-string.o compiled/make-ree-string.o compiled/make-ree-string0.o

compiled/allocate-ree-string.o: src/allocate-ree-string.c 
	$(CC) $(CFLAGS) -c src/allocate-ree-string.c -o compiled/allocate-ree-string.o

compiled/copy-ree-string.o: src/copy-ree-string.c 
	$(CC) $(CFLAGS) -c src/copy-ree-string.c -o compiled/copy-ree-string.o

compiled/free-ree-string.o: src/free-ree-string.c 
	$(CC) $(CFLAGS) -c src/free-ree-string.c -o compiled/free-ree-string.o

compiled/make-ree-string.o: src/make-ree-string.c 
	$(CC) $(CFLAGS) -c src/make-ree-string.c -o compiled/make-ree-string.o

compiled/make-ree-string0.o: src/make-ree-string0.c 
	$(CC) $(CFLAGS) -c src/make-ree-string0.c -o compiled/make-ree-string0.o
