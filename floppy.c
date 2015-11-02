#include <floppy.h>
#define SECTOR 512

unsigned short num_of_fats;
unsigned short sector_per_cluster;
unsigned short root_entries;
unsigned short sector_size;
unsigned short sectors_per_fat;
unsigned short fat_bytes;
unsigned short cluster;

int fd;
char *buff;
bool unmounted; //changed this to use it negatively so that it's assumed nothing is mounted
int counter;

void split(char *line, char **argv)
{
counter = 0;
int i = 0;

	while (*line != '\0')
	{
		while (*line == ' ' || *line == '\n')
			*line++ = '\0';

		counter += (sizeof(argv[i])/ sizeof(char*));
		i++;
		*argv++ = line;


		while (*line != '\0' && *line != ' ' && *line != '\n')
			line++;
	}
		*argv = '\0';
		counter -= 2;
}

int fmount(char **argv)
{

	buff = (char*)malloc(sizeof(char *) * 100);

	//if the file extension is .img, the file is open and read to buffer.
	//sectorsize is determined.
 	if (strstr(argv[1], ".img") != NULL)
	{
		fd = open(argv[1], O_RDONLY);

		if (fd < 0)
		{
		printf("Error: Nothing was mounted.\n");
		return -1;
		}

		strcpy(image, argv[1]);
	    	lseek(fd, 0, SEEK_SET);
	   	read(fd, buff, SECTOR);

		//pull information from boot and save as global variables
		sector_size = buff[12] * (SECTOR/2) + buff[11];
		fat_bytes = sectors_per_fat * sector_size;
		cluster = (((unsigned short) buff[26]) & 0xff) | (((unsigned short) buff[27]) & 0x0f)<<8;
		unsigned short low = ((unsigned short) buff[11]) & 0xff;
		unsigned short high = ((unsigned short) buff[12]) & 0xff;
		sector_per_cluster = ((unsigned short) buff[13]) & 0xff;
		num_of_fats = ((unsigned short) buff[16]) & 0xff;
		low = ((unsigned short) buff[17]) & 0xff;
		high = ((unsigned short) buff[18]) & 0xff;
		root_entries = low | (high << 8);
		low = ((unsigned short) buff[22]) & 0xff;
		high = ((unsigned short) buff[23]) & 0xff;
		sectors_per_fat = low | (high << 8);

		unmounted = false;
		}
	else
	{
	printf("Error: File was not a floppy image. Nothing was mounted.\n");
	return -1;
	}

return 0;
}

int fumount()
{
char dummy[30];

	if (unmounted = true)
	{
		printf("Error: Nothing is currently mounted.\n");
		return -1;
	}
	else
	{
		//clear all the variables, close file directory and free buffer

		num_of_fats = 0;
		sector_per_cluster = 0;
		root_entries = 0;
		sector_size = 0;
		sectors_per_fat = 0;
		fat_bytes = 0;
		cluster = 0;
		sector_size = 0;
		strcpy(image, dummy);
		close(fd);
		free(buff);
		unmounted = true;
	}

return 0;
}
int showsector(char **argv) {
	int sectorNumber = atoi(argv[1]); //convert input to int
	if (sectorNumber > 2880 || sectorNumber < 0)  {
		printf("Please pass a valid sector");
		return -1;
	}
	if (sectorNumber == 0)
		sectorNumber = 1;

	char buffer[SECTOR] = {'\0'};
	int iterator;
	lseek(3, sectorNumber * SECTOR, SEEK_SET);
	read(3, buffer, SECTOR);
	printf("\t 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
	for (iterator = 0; iterator < SECTOR; iterator++) {
		if(iterator % 16 == 0) //next level of sector
			printf("\n%03X\t", iterator);
    	printf("%02X ", (unsigned char) buffer[iterator]);
	}
	printf("\n");
}

void structure() 
{
	printf("Number of FAT:\t\t\t%i\n", num_of_fats);
	printf("Number of sectors used by FAT:\t%i\n", sectors_per_fat);
	printf("Number of sectors per cluster:\t%i\n", sector_per_cluster);
	printf("Number of ROOT entries:\t\t%i\n", root_entries);
	printf("Number of bytes per sector:\t%i\n", sector_size);
	printf("---Sector #---\t--Sector Types---\n");
	printf("     0        		BOOT\n");
	printf("  01 -- 09		FAT1\n");
	printf("  10 -- 18		FAT2\n");
	printf("  19 -- 32		ROOT DIRECTORY\n");
}

void help() 
{
	printf("\nFLOP COMMANDS\n");
	printf("-------------\n\n");
	printf("fmount: Mounts a floppy disk from an .img file.\n\n");
	printf("fumount: Unmounts a floppy disk.\n\n");
	printf("traverse: Lists the content from the root directory.\n\n"); 
	printf("traverse -l: Lists the content from the root directory in long form.\n\n"); 
	printf("structure: Lists the strucute of the floppy disk.\n\n");
	printf("showsector [sector number]: Shows the content of a specified sector number as a hex dump.\n\n");
	printf("showfat: Shows the content of the first 256 entries in the FAT table as a hex dump.\n\n");
	printf("showfile [filename]: Shows the contents of the target file as a hex dump.\n\n");
	printf("help: Shows usable commands.\n\n");
	printf("quit: Closes the floppy shell.\n\n");
}

void command(char **argv)
{
		if (strcmp(argv[0], "fmount") == 0)
			fmount(argv);
		if (strcmp(argv[0], "fumount") == 0) 
			fumount();
		if (strcmp(argv[0], "help") == 0)
			help();
		if (strcmp(argv[0], "structure") == 0)
			if (unmounted)
				printf("You must mount a floppy first.\n");
			else
				structure();
		if(strcmp(argv[0], "showsector") == 0)
			if (unmounted)
				printf("You must mount a floppy first.\n");
			else
				showsector(argv);
		if(strcmp(argv[0], "traverse") == 0)
			if (unmounted)
				printf("You must mount a floppy first.\n");		
			else
				traverse(counter, argv);

/* TODO

		if(strcmp(argv[0], "showfat") == 0)
			if (mounted)
				showfat();
			else
				printf("You must mount a floppy first.\n");
		if(strcmp(argv[0], "showfile") == 0)	
			if (mounted)
				showfat();
			else
				printf("You must mount a floppy first.\n");

*/
}
