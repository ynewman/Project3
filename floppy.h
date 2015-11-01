#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#include <stdbool.h>

#ifndef __FLOPPY_H
#define __FLOPPY_H

char image[30];

void split(char *line, char **argv);

int fmount(char **argv);

int funmount();

void trimWhiteSpace(char *str);

void printFiles(char *buf, char *directory, char *flag);

void printDir(unsigned short cluster, char *directory, unsigned short file_bytes,
                       unsigned short num_of_sectors, unsigned short bytes_per_sector, char *flag);

int traverse(int argc, char **argv);

void command(char **argv);

#endif
