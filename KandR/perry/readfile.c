#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 273-274

FILE * fptr;

main()
{
	char fileLine[100];  // will hold each line of input
	fptr = fopen("./bookinfo.txt", "r");
	if (fptr != 0)
	{
		while (!feof(fptr))
		{
			fgets(fileLine, 100, fptr);
			if (!feof(fptr))
			{
				puts(fileLine);
			}
		}
	}
	else
	{
		print("\nError opening file.\n");
	}
	fclose(fptr); // always close file
	return 0;
}
