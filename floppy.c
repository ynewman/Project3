#include <stdio.h>
#include <stdlib.h>
#include <floppy.h>

unsigned short sector_size;


//this is code for mounting the image TODO
int fmount(char *img)
{

char *buf = (char*)malloc(size_of(char *) * 512);
char *fd = img;

   	if (open(fd, RD_ONLY) == NULL) 
	{
	lseek(fd, 0, SEEK_SET);
	read(fd, buff, 512);
	sector_size = buff[12] *256 + buff[11];

	return 1;
	}

return 0;
}

