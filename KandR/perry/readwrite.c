#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 274-275

FILE * fptr;

main()
{
	fptr = fopen("./bookinfo.txt", "a"); // append to the end
	if (fptr == 0)
	{
		print("Error opening the file! Sorry!\n");
		exits(nil);
	}
	fprintf(fptr, "\nMore books to come!\n");
	fclose(fptr);  // Always close your files
	return 0;
}

