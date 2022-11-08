#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page 237-239

main()
{
	int i;
	int ctr = 0;
	char ans;

	char * movies[9] = {"Armour", "Argo", "Beasts of the Southern Wild", "Django Unchained",
						"Les Miserables", "Life of Pi", "Lincoln", "Silver Linings Playbook",
						"Zero Dark Thirty"};
	int movieratings[9]; // correspondin array of 9 integers to go with the chars above
	char * tempmovie = "This will be used to sort rated movies";
	print("asdf: %s\n", &tempmovie[0]);
	int outer, inner, didSwap, temprating;

	print("\n\n*** Oscar Season 2012 is here! ***\n\n");
	print("Time to rate this year's best picture nominees:");
	
	for (i=0; i<9; i++)
	{
		print("\nDid you see %s? (Y/N): ", movies[i]);
		scanf(" %c", &ans);
		if ((toupper(ans)) == 'Y')
		{
			print("\nWhat was your rating on a scale ");
			print("of 1-10: ");
			scanf(" %d", &movieratings[i]);
			ctr++;
			continue;
		}
		else
		{
			movieratings[i] = -1;
		}
	}
	
	// sort by movie rating, unseen will go to bottom
	// bubble sort
	for (outer = 0; outer < 8; outer++)
	{
		didSwap = 0;
		for (inner = outer; inner < 9; inner++)
		{
			if (movieratings[inner] > movieratings[outer])
			{
				tempmovie = movies[inner];
				temprating = movieratings[inner];
				movies[inner] = movies[outer];
				movieratings[inner] = movieratings[outer];
				movies[outer] = tempmovie;
				movieratings[outer] = temprating;
				didSwap = 1;
			}

		}
		if (didSwap == 0)
		{
			break;
		}
	}
	
	// no print everything you saw in order
	print("\n\n** Your Movie Ratings for the 2012 Oscar ");
	print("Contenders **\n");
	for (i=0; i < ctr; i++)
	{
		print("%s rated a %d!\n", movies[i], movieratings[i]);
	}
	
	return 0;
}
