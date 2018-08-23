
all:
	make ree.lib

clean:
	rm -f compiled/allocate-ree.o
	rm -f compiled/free-ree.o
	rm -f compiled/copy-ree.o
	rm -f compiled/make-ree.o

ree.lib: compiled/allocate-ree.o compiled/free-ree.o compiled/copy-ree.o compiled/make-ree.o
	rm -f ree.lib
	ar r ree.lib compiled/allocate-ree.o compiled/free-ree.o compiled/copy-ree.o compiled/make-ree.o

compiled/allocate-ree.o: src/allocate-ree.c 
	$(CC) $(CFLAGS) -c src/allocate-ree.c -o compiled/allocate-ree.o

compiled/free-ree.o: src/free-ree.c 
	$(CC) $(CFLAGS) -c src/free-ree.c -o compiled/free-ree.o

compiled/copy-ree.o: src/copy-ree.c 
	$(CC) $(CFLAGS) -c src/copy-ree.c -o compiled/copy-ree.o

compiled/make-ree.o: src/make-ree.c 
	$(CC) $(CFLAGS) -c src/make-ree.c -o compiled/make-ree.o
