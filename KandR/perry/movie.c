#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page 137-138

main()
{
	int ctr, numMovies, rating, favRating, leastRating;
	char movieName[40], favorite[40], least[40];
	favRating = 0;
	leastRating = 10;
	do {
		print("How many movies have you seen this year? ");
		scanf(" %d", &numMovies);
		if (numMovies < 1) {
			print("No movies! How can you rank them?\nTry again!\n\n");
		}
	} while (numMovies < 1);

	for (ctr = 1; ctr <= numMovies; ctr++) {
		print("\nWhat was the name of the movie? ");
		print("(1-word title only!) ");
		scanf(" %s", movieName);
		print("On a scale of 1 to 10, what would ");
		print("you rate it? ");
		scanf(" %d", &rating);
		if (rating > favRating) {
			strcpy(favorite, movieName);
			favRating = rating;
		}
		if (rating < leastRating) {
			strcpy(least, movieName);
			leastRating = rating;
		}
	}
	print("\nYour Favorite Movie was %s.\n", favorite);
	print("\nYour Least-favorite Movie was %s.\n", least);
	return 0;
}
