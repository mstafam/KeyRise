CC=gcc
CFLAGS=-Wall -std=c11

Rotate: Rotate.o RotateFunc.o
	$(CC) $(CFLAGS) $^ -lm -lc -lncurses -ltinfo -o $@

%.o: %.c
	$(CC) $(CFLAGS) $^ -c

.PHONY: clean
clean:
	rm -f Rotate *.o
