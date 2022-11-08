#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 280-281

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
	for (letter = 'A'; letter <= 'Z'; letter++)
	{
		fputc(letter, fptr);
	}
	puts("Just wrote the letters A through Z");
	// Now read the file backwards
	fseek(fptr, -1, SEEK_END); // Minus 1 byte from the end
	print("Here is the file backwards:\n");
	for (i = 26; i > 0; i--)
	{
		letter = fgetc(fptr);
		// reads a letter, then back up 2
		fseek(fptr, -2, SEEK_CUR);
		print("The next letter is %c.\n", letter);
	}
	fclose(fptr);
	return 0;
}