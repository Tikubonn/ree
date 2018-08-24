
all:
	make ree.lib

clean:
	rm -f compiled/init-ree.o
	rm -f compiled/compile-ree.o
	rm -f compiled/compile-ree-automatically.o
	rm -f compiled/compile-ree-beginning.o
	rm -f compiled/compile-ree-end.o
	rm -f compiled/compile-ree-any.o
	rm -f compiled/compile-ree-byte.o
	rm -f compiled/compile-ree-bytearray.o
	rm -f compiled/compile-ree-repeat-for.o
	rm -f compiled/compile-ree-repeat-necessary.o
	rm -f compiled/compile-ree-repeat-unnecessary.o
	rm -f compiled/compile-ree-range.o
	rm -f compiled/compile-ree-set.o
	rm -f compiled/compile-ree-group.o
	rm -f compiled/compile-ree-or.o
	rm -f compiled/compile-ree-unnecessary.o
	rm -f compiled/connect-to-ree-builder-node.o
	rm -f compiled/connect-to-ree-builder-group-node.o
	rm -f compiled/pop-ree-builder-node.o
	rm -f compiled/get-ree-group.o
	rm -f compiled/ree-group-count.o
	rm -f compiled/match-ree.o
	rm -f compiled/match-ree-node.o
	rm -f compiled/match-ree-beginning-node.o
	rm -f compiled/match-ree-end-node.o
	rm -f compiled/match-ree-any-node.o
	rm -f compiled/match-ree-byte-node.o
	rm -f compiled/match-ree-bytearray-node.o
	rm -f compiled/match-ree-repeat-for-node.o
	rm -f compiled/match-ree-repeat-necessary-node.o
	rm -f compiled/match-ree-repeat-unnecessary-node.o
	rm -f compiled/match-ree-range-node-without-next.o
	rm -f compiled/match-ree-inclusive-set-node.o
	rm -f compiled/match-ree-declusive-set-node.o
	rm -f compiled/match-ree-group-node.o
	rm -f compiled/match-ree-or-node.o
	rm -f compiled/match-ree-unnecessary-node.o
	rm -f compiled/search-ree.o
	rm -f compiled/match-ree-byte-node-without-next.o
	rm -f compiled/match-ree-bytearray-node-without-next.o
	rm -f compiled/get-ree-match.o

ree.lib: compiled/init-ree.o compiled/compile-ree.o compiled/compile-ree-automatically.o compiled/compile-ree-beginning.o compiled/compile-ree-end.o compiled/compile-ree-any.o compiled/compile-ree-byte.o compiled/compile-ree-bytearray.o compiled/compile-ree-repeat-for.o compiled/compile-ree-repeat-necessary.o compiled/compile-ree-repeat-unnecessary.o compiled/compile-ree-range.o compiled/compile-ree-set.o compiled/compile-ree-group.o compiled/compile-ree-or.o compiled/compile-ree-unnecessary.o compiled/connect-to-ree-builder-node.o compiled/connect-to-ree-builder-group-node.o compiled/pop-ree-builder-node.o compiled/get-ree-group.o compiled/ree-group-count.o compiled/match-ree.o compiled/match-ree-node.o compiled/match-ree-beginning-node.o compiled/match-ree-end-node.o compiled/match-ree-any-node.o compiled/match-ree-byte-node.o compiled/match-ree-bytearray-node.o compiled/match-ree-repeat-for-node.o compiled/match-ree-repeat-necessary-node.o compiled/match-ree-repeat-unnecessary-node.o compiled/match-ree-range-node-without-next.o compiled/match-ree-inclusive-set-node.o compiled/match-ree-declusive-set-node.o compiled/match-ree-group-node.o compiled/match-ree-or-node.o compiled/match-ree-unnecessary-node.o compiled/search-ree.o compiled/match-ree-byte-node-without-next.o compiled/match-ree-bytearray-node-without-next.o compiled/get-ree-match.o
	rm -f ree.lib
	ar r ree.lib compiled/init-ree.o compiled/compile-ree.o compiled/compile-ree-automatically.o compiled/compile-ree-beginning.o compiled/compile-ree-end.o compiled/compile-ree-any.o compiled/compile-ree-byte.o compiled/compile-ree-bytearray.o compiled/compile-ree-repeat-for.o compiled/compile-ree-repeat-necessary.o compiled/compile-ree-repeat-unnecessary.o compiled/compile-ree-range.o compiled/compile-ree-set.o compiled/compile-ree-group.o compiled/compile-ree-or.o compiled/compile-ree-unnecessary.o compiled/connect-to-ree-builder-node.o compiled/connect-to-ree-builder-group-node.o compiled/pop-ree-builder-node.o compiled/get-ree-group.o compiled/ree-group-count.o compiled/match-ree.o compiled/match-ree-node.o compiled/match-ree-beginning-node.o compiled/match-ree-end-node.o compiled/match-ree-any-node.o compiled/match-ree-byte-node.o compiled/match-ree-bytearray-node.o compiled/match-ree-repeat-for-node.o compiled/match-ree-repeat-necessary-node.o compiled/match-ree-repeat-unnecessary-node.o compiled/match-ree-range-node-without-next.o compiled/match-ree-inclusive-set-node.o compiled/match-ree-declusive-set-node.o compiled/match-ree-group-node.o compiled/match-ree-or-node.o compiled/match-ree-unnecessary-node.o compiled/search-ree.o compiled/match-ree-byte-node-without-next.o compiled/match-ree-bytearray-node-without-next.o compiled/get-ree-match.o

compiled/init-ree.o: src/init-ree.c 
	$(CC) $(CFLAGS) -c src/init-ree.c -o compiled/init-ree.o

compiled/compile-ree.o: src-compile/compile-ree.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree.c -o compiled/compile-ree.o

compiled/compile-ree-automatically.o: src-compile/compile-ree-automatically.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-automatically.c -o compiled/compile-ree-automatically.o

compiled/compile-ree-beginning.o: src-compile/compile-ree-beginning.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-beginning.c -o compiled/compile-ree-beginning.o

compiled/compile-ree-end.o: src-compile/compile-ree-end.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-end.c -o compiled/compile-ree-end.o

compiled/compile-ree-any.o: src-compile/compile-ree-any.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-any.c -o compiled/compile-ree-any.o

compiled/compile-ree-byte.o: src-compile/compile-ree-byte.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-byte.c -o compiled/compile-ree-byte.o

compiled/compile-ree-bytearray.o: src-compile/compile-ree-bytearray.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-bytearray.c -o compiled/compile-ree-bytearray.o

compiled/compile-ree-repeat-for.o: src-compile/compile-ree-repeat-for.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-repeat-for.c -o compiled/compile-ree-repeat-for.o

compiled/compile-ree-repeat-necessary.o: src-compile/compile-ree-repeat-necessary.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-repeat-necessary.c -o compiled/compile-ree-repeat-necessary.o

compiled/compile-ree-repeat-unnecessary.o: src-compile/compile-ree-repeat-unnecessary.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-repeat-unnecessary.c -o compiled/compile-ree-repeat-unnecessary.o

compiled/compile-ree-range.o: src-compile/compile-ree-range.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-range.c -o compiled/compile-ree-range.o

compiled/compile-ree-set.o: src-compile/compile-ree-set.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-set.c -o compiled/compile-ree-set.o

compiled/compile-ree-group.o: src-compile/compile-ree-group.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-group.c -o compiled/compile-ree-group.o

compiled/compile-ree-or.o: src-compile/compile-ree-or.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-or.c -o compiled/compile-ree-or.o

compiled/compile-ree-unnecessary.o: src-compile/compile-ree-unnecessary.c 
	$(CC) $(CFLAGS) -c src-compile/compile-ree-unnecessary.c -o compiled/compile-ree-unnecessary.o

compiled/connect-to-ree-builder-node.o: src-compile/connect-to-ree-builder-node.c 
	$(CC) $(CFLAGS) -c src-compile/connect-to-ree-builder-node.c -o compiled/connect-to-ree-builder-node.o

compiled/connect-to-ree-builder-group-node.o: src-compile/connect-to-ree-builder-group-node.c 
	$(CC) $(CFLAGS) -c src-compile/connect-to-ree-builder-group-node.c -o compiled/connect-to-ree-builder-group-node.o

compiled/pop-ree-builder-node.o: src-compile/pop-ree-builder-node.c 
	$(CC) $(CFLAGS) -c src-compile/pop-ree-builder-node.c -o compiled/pop-ree-builder-node.o

compiled/get-ree-group.o: src/get-ree-group.c 
	$(CC) $(CFLAGS) -c src/get-ree-group.c -o compiled/get-ree-group.o

compiled/ree-group-count.o: src/ree-group-count.c 
	$(CC) $(CFLAGS) -c src/ree-group-count.c -o compiled/ree-group-count.o

compiled/match-ree.o: src-match/match-ree.c 
	$(CC) $(CFLAGS) -c src-match/match-ree.c -o compiled/match-ree.o

compiled/match-ree-node.o: src-match/match-ree-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-node.c -o compiled/match-ree-node.o

compiled/match-ree-beginning-node.o: src-match/match-ree-beginning-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-beginning-node.c -o compiled/match-ree-beginning-node.o

compiled/match-ree-end-node.o: src-match/match-ree-end-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-end-node.c -o compiled/match-ree-end-node.o

compiled/match-ree-any-node.o: src-match/match-ree-any-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-any-node.c -o compiled/match-ree-any-node.o

compiled/match-ree-byte-node.o: src-match/match-ree-byte-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-byte-node.c -o compiled/match-ree-byte-node.o

compiled/match-ree-bytearray-node.o: src-match/match-ree-bytearray-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-bytearray-node.c -o compiled/match-ree-bytearray-node.o

compiled/match-ree-repeat-for-node.o: src-match/match-ree-repeat-for-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-repeat-for-node.c -o compiled/match-ree-repeat-for-node.o

compiled/match-ree-repeat-necessary-node.o: src-match/match-ree-repeat-necessary-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-repeat-necessary-node.c -o compiled/match-ree-repeat-necessary-node.o

compiled/match-ree-repeat-unnecessary-node.o: src-match/match-ree-repeat-unnecessary-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-repeat-unnecessary-node.c -o compiled/match-ree-repeat-unnecessary-node.o

compiled/match-ree-range-node-without-next.o: src-match/match-ree-range-node-without-next.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-range-node-without-next.c -o compiled/match-ree-range-node-without-next.o

compiled/match-ree-inclusive-set-node.o: src-match/match-ree-inclusive-set-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-inclusive-set-node.c -o compiled/match-ree-inclusive-set-node.o

compiled/match-ree-declusive-set-node.o: src-match/match-ree-declusive-set-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-declusive-set-node.c -o compiled/match-ree-declusive-set-node.o

compiled/match-ree-group-node.o: src-match/match-ree-group-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-group-node.c -o compiled/match-ree-group-node.o

compiled/match-ree-or-node.o: src-match/match-ree-or-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-or-node.c -o compiled/match-ree-or-node.o

compiled/match-ree-unnecessary-node.o: src-match/match-ree-unnecessary-node.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-unnecessary-node.c -o compiled/match-ree-unnecessary-node.o

compiled/search-ree.o: src-search/search-ree.c 
	$(CC) $(CFLAGS) -c src-search/search-ree.c -o compiled/search-ree.o

compiled/match-ree-byte-node-without-next.o: src-match/match-ree-byte-node-without-next.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-byte-node-without-next.c -o compiled/match-ree-byte-node-without-next.o

compiled/match-ree-bytearray-node-without-next.o: src-match/match-ree-bytearray-node-without-next.c 
	$(CC) $(CFLAGS) -c src-match/match-ree-bytearray-node-without-next.c -o compiled/match-ree-bytearray-node-without-next.o

compiled/get-ree-match.o: src/get-ree-match.c 
	$(CC) $(CFLAGS) -c src/get-ree-match.c -o compiled/get-ree-match.o
