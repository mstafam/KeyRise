# Names: Mustafa Mohamed, Sami Elsayed
# Lab: 9-11

# Variables
CC=gcc
CFLAGS=-Wall -std=c11

# Creates KeyRise Executable
KeyRise: KeyRise.o KeyRiseFunc.o
	$(CC) $(CFLAGS) $^ -lm -lc -lncurses -ltinfo -o $@

# Creates .o files from all .c files
%.o: %.c
	$(CC) $(CFLAGS) $^ -c

# Creates phony target called clean. Removes KeyRise and all .o files
.PHONY: clean
clean:
	rm -f KeyRise *.o

# Doxygen target
doc:
	doxygen Doxyfile
