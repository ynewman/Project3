CC=gcc
CFLAGS=-I.

floppy: main.o floppy.o
	$(CC) -o floppy main.o floppy.o -g -I.

clean:
	rm floppy main.o floppy.o
