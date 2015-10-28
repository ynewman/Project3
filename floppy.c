#include <stdio.h>
#include <stdlib.h>
#include <floppy.h>

int loop;

int command()
{
int i = 0;

char input[60];
const char *fmount = "fmount";
const char *funmount = "funmount";
const char *exit = "exit";

printf("f: ");
fgets(input, 60, stdin);

   	 if(strncmp(input, fmount, 6) == 0)
	{
            printf("wants to mount\n");
		//fork and call mounting program here pass in all of input so the 
		//second arg can be accessed with argv!! TODO
    	}  

   	 if(strncmp(input, funmount, 8) == 0)
	{
            printf("wants to unmount\n");
		//fork and call mounting program here pass in all of input so the 
		//second arg can be accessed with argv!! TODO
    	}  

   	 if(strncmp(input, exit, 4) == 0)
	{
            printf("wants to exit\n");
		
	return(0);
    	} 
	
	//case statements for the rest of the commands, make in floppy.c TODO
   	


 return(1);

}


//this is code for mounting the image TODO
/*unsigned short sector_size;

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

*/

