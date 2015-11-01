
#include <floppy.h>

unsigned short sector_size;

int fd;
char *buff;
bool mounted;
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

		//for testing purposes REMOVE
		printf("%i\n", counter);
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
		printf("Error: Nothing was mounted.");
		return -1;
		}

		strcpy(image, argv[1]);
	    	lseek(fd, 0, SEEK_SET);
	   	read(fd, buff, 512);
		sector_size = buff[12] *256 + buff[11];
		mounted = true;
	}
	else
	{
	printf("Error: File was not a floppy image. Nothing was mounted.");
	return -1;
	}

	//for testing purposes REMOVE
	printf("%i\n", sector_size);

return 0;
}

int funmount()
{
char dummy[30];

	if (sector_size == 0)
	{
		printf("Error: Nothing is currently mounted.");
		return -1;
	}
	else
	{
	close(fd);
	free(buff);
	sector_size = 0;
	strcpy(image, dummy);
	mounted = false;

	//for testing purposes REMOVE (shows 0 if successful)
	printf("%i\n", sector_size);
	}

return 0;
}
void help() {
	printf("Usable commands: fmount, funmount, traverse [-l],structure, showsector [#], showfat, showfile [FILE], help, quit\n");
}

void command(char **argv)
{
		if (strcmp(argv[0], "fmount") == 0)
			fmount(argv);
		if (strcmp(argv[0], "funmount") == 0)
			funmount();
		if (strcmp(argv[0], "help") == 0)
			help();

		//add cases for other options as we build them

		if(strcmp(argv[0], "traverse") == 0)
		{
		//here I pass in the number of args and the **char array argv to traverse.c
		//I renamed "main" to traverse. I'm getting a segmentation fault with "traverse" but not
		//"traverse -l", so something I'm passing isn't working with your logic, since it was originally
		//written as a standalone program. I combined it in with main.c and floppy.c so it can be called
		//from within the shell. I also tweaked it to use any floppy image file rather than the static one.
		//I've saved the image string from when it was mounted as a global array called
		//image in the header file.
			if (mounted)
				traverse(counter, argv);
			else
				printf("You must mount a floppy first.");
		}
/* TODO
		if(strcmp(argv[0], "structure") == 0)
		{
			if (mounted)
				structure();
			else
				printf("You must mount a floppy first.");
		}

		if(strcmp(argv[0], "showsector") == 0)
		{
			if (mounted)
				showsector();
			else
				printf("You must mount a floppy first.");
		}

		if(strcmp(argv[0], "showfat") == 0)
		{
			if (mounted)
				showfat();
			else
				printf("You must mount a floppy first.");
		}
*/
}
