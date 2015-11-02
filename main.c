#include <floppy.h>

int main()
{
	bool loop = true;
	char  line[100];
	char  *argv[100];

  while (loop)
	{
		printf("flop: ");
		fgets(line, 100, stdin);
		split(line, argv);

		if (strcmp(argv[0], "quit") == 0)
			return 0;
		else
			command(argv);
	}
	return 0;
}

/*
TODO

showfat: show contents of first 256 entries of FAT table as hex dump 15%

showfile filename: show content of target file as hex dump 15%

need to finish: write-up, clean up and comments
*/
