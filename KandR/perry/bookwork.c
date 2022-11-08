#include <u.h>
#include <libc.h>
#include <stdio.h>
#include "bookinfo.h"

// perry page 264-265
// other things wrong when you enter the data you need to make sure 
// $ is entered before decimal
// getchar() should work by itself in ansi c but plan9 wants to do more with it
// assing to a variable then just print it

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
	// print header line and start next loop
	print("\n\nHere is the collection of books; n");
	for (ctr = 0; ctr < 3; ctr++)
	{
		print("#%d: %s by %s", (ctr+1), books[ctr].title, books[ctr].author);
		print("\nIt is %d pages and costs $%.2f", books[ctr].pages, books[ctr].price);
		print("\n\n");
	}
	return 0;
}