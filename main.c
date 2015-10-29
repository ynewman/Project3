#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{

int loop = 1;
int i = 0;
extern unsigned int sector_size;
char input[60];
const char *fmount = "fmount";
const char *funmount = "funmount";
const char *quit = "quit";

	//call up prompt and take input until user types "quit"
	while(loop == 1)
	{

		printf("f: ");
		fgets(input, 60, stdin);

	   	 if(strncmp(input, fmount, 6) == 0)
		{
			printf("wants to mount\n");

	    	}  

	   	 if(strncmp(input, funmount, 8) == 0)
		{
		    printf("wants to unmount\n");

	    	}  

	   	 if(strncmp(input, quit, 4) == 0)
		{
		    printf("wants to quit\n");
		
		loop = 0;
	    	} 
	}
	
/*
TODO

help: show commands supported 5%

structure: list structure 10%
	num FAT, num sectors used by FAT, num sectors/cluster, num ROOT entries, num bytes/sector
	sector # ------ sector types

traverse -1: list contents 20%!!!
	when -1 is turned on, it's a long list
	sort and display, show <DIR> for dirs

showsector 10: show hex dump of a sector (512 bytes) 10%

showfat: show contents of first 256 entries of FAT table as hex dump 15%

showfile filename: show content of target file as hex dump 15%

need to finish: writeup, mount and unmount program/fork thingies, write-up, clean up and comment
*/

}



