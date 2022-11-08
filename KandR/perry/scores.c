#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 199
// this also has a logic error 40.x on average because we don't reset to 0
// its just  learning exercise by changing average and start values

main()
{
	int gameScores[10] = {12, 5, 21, 15, 32, 10};
	int totalPoints = 0;
	int i;
	float avg;
	
	for (i=6; i<10; i++)
	{
		print("What did the player score in game %d? ", i+1);
		scanf(" %d", &gameScores[i]);
	}
	
	for (i=0; i<10; i++)
	{
		totalPoints += gameScores[i];
	}
	
	avg = ((float)totalPoints/10);
	print("\n\nThe Player's scoring average is %.1f.\n", avg);
	
	return 0;
}