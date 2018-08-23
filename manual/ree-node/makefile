
all:
	make ree-node.lib

clean:
	rm -f compiled/connect-ree-node.o
	rm -f compiled/default-ree-node.o
	rm -f compiled/disconnect-ree-node.o
	rm -f compiled/next-ree-node.o
	rm -f compiled/previous-ree-node.o
	rm -f compiled/fix-ree-node.o
	rm -f compiled/fix-ree-group-node.o
	rm -f compiled/fix-ree-repeat-for-node.o
	rm -f compiled/fix-ree-repeat-necessary-node.o
	rm -f compiled/fix-ree-repeat-unnecessary-node.o
	rm -f compiled/fix-ree-set-node.o
	rm -f compiled/fix-ree-unnecessary-node.o

ree-node.lib: compiled/connect-ree-node.o compiled/default-ree-node.o compiled/disconnect-ree-node.o compiled/next-ree-node.o compiled/previous-ree-node.o compiled/fix-ree-node.o compiled/fix-ree-group-node.o compiled/fix-ree-repeat-for-node.o compiled/fix-ree-repeat-necessary-node.o compiled/fix-ree-repeat-unnecessary-node.o compiled/fix-ree-set-node.o compiled/fix-ree-unnecessary-node.o
	rm -f ree-node.lib
	ar r ree-node.lib compiled/connect-ree-node.o compiled/default-ree-node.o compiled/disconnect-ree-node.o compiled/next-ree-node.o compiled/previous-ree-node.o compiled/fix-ree-node.o compiled/fix-ree-group-node.o compiled/fix-ree-repeat-for-node.o compiled/fix-ree-repeat-necessary-node.o compiled/fix-ree-repeat-unnecessary-node.o compiled/fix-ree-set-node.o compiled/fix-ree-unnecessary-node.o

compiled/connect-ree-node.o: src/connect-ree-node.c 
	$(CC) $(CFLAGS) -c src/connect-ree-node.c -o compiled/connect-ree-node.o

compiled/default-ree-node.o: src/default-ree-node.c 
	$(CC) $(CFLAGS) -c src/default-ree-node.c -o compiled/default-ree-node.o

compiled/disconnect-ree-node.o: src/disconnect-ree-node.c 
	$(CC) $(CFLAGS) -c src/disconnect-ree-node.c -o compiled/disconnect-ree-node.o

compiled/next-ree-node.o: src/next-ree-node.c 
	$(CC) $(CFLAGS) -c src/next-ree-node.c -o compiled/next-ree-node.o

compiled/previous-ree-node.o: src/previous-ree-node.c 
	$(CC) $(CFLAGS) -c src/previous-ree-node.c -o compiled/previous-ree-node.o

compiled/fix-ree-node.o: src-fix/fix-ree-node.c 
	$(CC) $(CFLAGS) -c src-fix/fix-ree-node.c -o compiled/fix-ree-node.o

compiled/fix-ree-group-node.o: src-fix/fix-ree-group-node.c 
	$(CC) $(CFLAGS) -c src-fix/fix-ree-group-node.c -o compiled/fix-ree-group-node.o

compiled/fix-ree-repeat-for-node.o: src-fix/fix-ree-repeat-for-node.c 
	$(CC) $(CFLAGS) -c src-fix/fix-ree-repeat-for-node.c -o compiled/fix-ree-repeat-for-node.o

compiled/fix-ree-repeat-necessary-node.o: src-fix/fix-ree-repeat-necessary-node.c 
	$(CC) $(CFLAGS) -c src-fix/fix-ree-repeat-necessary-node.c -o compiled/fix-ree-repeat-necessary-node.o

compiled/fix-ree-repeat-unnecessary-node.o: src-fix/fix-ree-repeat-unnecessary-node.c 
	$(CC) $(CFLAGS) -c src-fix/fix-ree-repeat-unnecessary-node.c -o compiled/fix-ree-repeat-unnecessary-node.o

compiled/fix-ree-set-node.o: src-fix/fix-ree-set-node.c 
	$(CC) $(CFLAGS) -c src-fix/fix-ree-set-node.c -o compiled/fix-ree-set-node.o

compiled/fix-ree-unnecessary-node.o: src-fix/fix-ree-unnecessary-node.c 
	$(CC) $(CFLAGS) -c src-fix/fix-ree-unnecessary-node.c -o compiled/fix-ree-unnecessary-node.o
