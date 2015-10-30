#include <stdio.h>
#include <stdlib.h>
#include <floppy.h>

unsigned short sector_size;

void  split(char *line, char **argv) 
{
	while (*line != '\0') 
	{       
		while (*line == ' ' || *line == '\n')
			*line++ = '\0';    

			*argv++ = line;          

		while (*line != '\0' && *line != ' ' && *line != '\n') 
			line++;           
	} 
		*argv = '\0';                
 
}

//TODO
int fmount(char *argv)
{

/*	char *buf = (char*)malloc(size_of(char *) * 512);
	char *fd = argv[0];

   	if (open(fd, O_RDONLY) == NULL) 
	{ 

	lseek(fd, 0, SEEK_SET);
	read(fd, buff, 512);
	sector_size = buff[12] *256 + buff[11];

	 }
	else 
	printf("Not a valid floppy.\n");
*/
}

//TODO
int command(char **argv)
{
/*
		if(strncmp(argv[0], "fmount", 6) == 0)
		{
			
			printf("wants to mount\n");
			fmount(argv[1]);

	    	}  
		if(strncmp(argv[0], "funmount", 8) == 0)
		{

		    printf("wants to unmount\n");

	    	}  
*/
}

