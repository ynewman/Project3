#include <floppy.h>
main()
{
	int loop = 1;  
	char  line[100];            
	char  *argv[100]; 
 
    	while (loop == 1) 
	{                   
		printf("f: ");     
		fgets(line, 100, stdin);             
		split(line, argv);       

		if (strcmp(argv[0], "exit") == 0)  
		loop = 0;

		else 
		command(argv); 

		//for testing purposes REMOVE 
		printf("first word: %s\nsecond word: %s\n", argv[0], argv[1]); 
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




