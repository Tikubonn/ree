
all:
	make dump.lib

clean:
	rm -f compiled/dump-ree.o
	rm -f compiled/dump-ree-indentation.o
	rm -f compiled/dump-ree-character.o
	rm -f compiled/dump-ree-node.o
	rm -f compiled/dump-ree-beginning-node.o
	rm -f compiled/dump-ree-end-node.o
	rm -f compiled/dump-ree-any-node.o
	rm -f compiled/dump-ree-byte-node.o
	rm -f compiled/dump-ree-bytearray-node.o
	rm -f compiled/dump-ree-repeat-for-node.o
	rm -f compiled/dump-ree-repeat-necessary-node.o
	rm -f compiled/dump-ree-repeat-unnecessary-node.o
	rm -f compiled/dump-ree-range-node.o
	rm -f compiled/dump-ree-inclusive-set-node.o
	rm -f compiled/dump-ree-declusive-set-node.o
	rm -f compiled/dump-ree-group-node.o
	rm -f compiled/dump-ree-unnecessary-node.o
	rm -f compiled/dump-ree-or-node.o

dump.lib: compiled/dump-ree.o compiled/dump-ree-indentation.o compiled/dump-ree-character.o compiled/dump-ree-node.o compiled/dump-ree-beginning-node.o compiled/dump-ree-end-node.o compiled/dump-ree-any-node.o compiled/dump-ree-byte-node.o compiled/dump-ree-bytearray-node.o compiled/dump-ree-repeat-for-node.o compiled/dump-ree-repeat-necessary-node.o compiled/dump-ree-repeat-unnecessary-node.o compiled/dump-ree-range-node.o compiled/dump-ree-inclusive-set-node.o compiled/dump-ree-declusive-set-node.o compiled/dump-ree-group-node.o compiled/dump-ree-unnecessary-node.o compiled/dump-ree-or-node.o
	rm -f dump.lib
	ar r dump.lib compiled/dump-ree.o compiled/dump-ree-indentation.o compiled/dump-ree-character.o compiled/dump-ree-node.o compiled/dump-ree-beginning-node.o compiled/dump-ree-end-node.o compiled/dump-ree-any-node.o compiled/dump-ree-byte-node.o compiled/dump-ree-bytearray-node.o compiled/dump-ree-repeat-for-node.o compiled/dump-ree-repeat-necessary-node.o compiled/dump-ree-repeat-unnecessary-node.o compiled/dump-ree-range-node.o compiled/dump-ree-inclusive-set-node.o compiled/dump-ree-declusive-set-node.o compiled/dump-ree-group-node.o compiled/dump-ree-unnecessary-node.o compiled/dump-ree-or-node.o

compiled/dump-ree.o: src/dump-ree.c 
	$(CC) $(CFLAGS) -c src/dump-ree.c -o compiled/dump-ree.o

compiled/dump-ree-indentation.o: src/dump-ree-indentation.c 
	$(CC) $(CFLAGS) -c src/dump-ree-indentation.c -o compiled/dump-ree-indentation.o

compiled/dump-ree-character.o: src/dump-ree-character.c 
	$(CC) $(CFLAGS) -c src/dump-ree-character.c -o compiled/dump-ree-character.o

compiled/dump-ree-node.o: src/dump-ree-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-node.c -o compiled/dump-ree-node.o

compiled/dump-ree-beginning-node.o: src/dump-ree-beginning-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-beginning-node.c -o compiled/dump-ree-beginning-node.o

compiled/dump-ree-end-node.o: src/dump-ree-end-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-end-node.c -o compiled/dump-ree-end-node.o

compiled/dump-ree-any-node.o: src/dump-ree-any-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-any-node.c -o compiled/dump-ree-any-node.o

compiled/dump-ree-byte-node.o: src/dump-ree-byte-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-byte-node.c -o compiled/dump-ree-byte-node.o

compiled/dump-ree-bytearray-node.o: src/dump-ree-bytearray-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-bytearray-node.c -o compiled/dump-ree-bytearray-node.o

compiled/dump-ree-repeat-for-node.o: src/dump-ree-repeat-for-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-repeat-for-node.c -o compiled/dump-ree-repeat-for-node.o

compiled/dump-ree-repeat-necessary-node.o: src/dump-ree-repeat-necessary-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-repeat-necessary-node.c -o compiled/dump-ree-repeat-necessary-node.o

compiled/dump-ree-repeat-unnecessary-node.o: src/dump-ree-repeat-unnecessary-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-repeat-unnecessary-node.c -o compiled/dump-ree-repeat-unnecessary-node.o

compiled/dump-ree-range-node.o: src/dump-ree-range-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-range-node.c -o compiled/dump-ree-range-node.o

compiled/dump-ree-inclusive-set-node.o: src/dump-ree-inclusive-set-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-inclusive-set-node.c -o compiled/dump-ree-inclusive-set-node.o

compiled/dump-ree-declusive-set-node.o: src/dump-ree-declusive-set-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-declusive-set-node.c -o compiled/dump-ree-declusive-set-node.o

compiled/dump-ree-group-node.o: src/dump-ree-group-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-group-node.c -o compiled/dump-ree-group-node.o

compiled/dump-ree-unnecessary-node.o: src/dump-ree-unnecessary-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-unnecessary-node.c -o compiled/dump-ree-unnecessary-node.o

compiled/dump-ree-or-node.o: src/dump-ree-or-node.c 
	$(CC) $(CFLAGS) -c src/dump-ree-or-node.c -o compiled/dump-ree-or-node.o
