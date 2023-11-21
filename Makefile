# Names: Mustafa Mohamed, Sami Elsayed
# Lab: 9-11

# Variables
CC=gcc
CFLAGS=-Wall -std=c11

# Creates Rotate Executable
Rotate: Rotate.o RotateFunc.o
	$(CC) $(CFLAGS) $^ -lm -lc -lncurses -ltinfo -o $@

# Creates .o files from all .c files
%.o: %.c
	$(CC) $(CFLAGS) $^ -c

# Creates phony target called clean. Removes Rotate and all .o files
.PHONY: clean
clean:
	rm -f Rotate *.o
