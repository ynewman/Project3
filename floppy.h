#ifndef __FLOPPY_H
#define __FLOPPY_H

void parse(char *line, char **argv);

int fmount(char *argv);

int command(char **argv);

#endif
