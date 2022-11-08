#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 282-283

FILE * fptr;

main()
{
	char letter;
	int i;
	fptr = fopen("./letters.txt", "w+");
	if (fptr == 0)
	{
		print("There was an error while opening the file.\n");
		exits(nil);
	}
	print("Which # letter would you like to change (1-26)? ");
	scanf(" %d", &i);

	// seeks to that position from the beginning
	fseek(fptr, (i-1), SEEK_SET);
	fputc('*', fptr); //overwrite

	// now iterate from beginning
	fseek(fptr, 0, SEEK_SET);
	print("Here is the file now:\n");
	for (i = 0; i < 26; i++)
	{
		letter = fgetc(fptr);
		print("The next letter is %c.\n", letter);
	}
	fclose(fptr);
	return 0;
}