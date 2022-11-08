#include <u.h>
#include <libc.h>
#include "bookinfo.h"
#include <stdio.h>

// perry page 270-273
// create, read it, and write to it using fprintf()

FILE * fptr;

main()
{
	int ctr;
	int mychar;
	struct bookInfo books[3]; 

	for (ctr = 0; ctr < 3; ctr++)
	{
		print("What is the name of the book #%d?\n", (ctr+1));
		gets(books[ctr].title);
		puts("Who is the author? ");
		gets(books[ctr].author);
		puts("how much did the book cost? ");
		scanf(" $%f", &books[ctr].price);
		puts("How many pages in the book? ");
		scanf(" %d", &books[ctr].pages);
		mychar = getchar(); // clears last new line for next loop
		print("%c\n", mychar);
	}

	// use double \\ for dos and single forward slash for unix
	fptr = fopen("./bookinfo.txt", "w");
	if (fptr == 0)
	{
		print("Error--file could not be opened.\n");
		exits(nil);
	}
	fprintf(fptr, "\n\nHere is the collectino of books: \n");
	for (ctr = 0; ctr < 3; ctr++)
	{
		fprintf(fptr, "#%d: %s by %s", (ctr+1), books[ctr].title,  books[ctr].author);
		fprintf(fptr, "\nIt is %d pages and costs $%.2f", books[ctr].pages, books[ctr].price);
		fprintf(fptr, "\n\n");
	}
	fclose(fptr); // always close files
	return 0;

}
