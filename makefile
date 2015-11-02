CC=gcc
CFLAGS=-I.

floppy: main.o floppy.o traverse.o
	$(CC) -o floppy main.c floppy.c traverse.c -g -I.
run:
	./floppy

clean:
	rm floppy main.o floppy.o traverse.o
