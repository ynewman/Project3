#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int loop;

main()
{
loop = 1;

	while(loop == 1)
	{
	loop = command();
	}
}


