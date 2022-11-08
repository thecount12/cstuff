#include <u.h>
#include <libc.h>
#include <ctype.h>
#include <stdio.h>

// perry page: 254-254

main()
{
	int i, aSize;
	int * randomNums;
	long tp;
	double total = 0;
	int biggest, smallest;
	float average;
	srand(time(&tp));
	
	print("How many random numbers do you want in your array? ");
	scanf(" %d", &aSize);

	// allocate array equal to number requested by user
	randomNums = (int *) malloc(aSize * sizeof(int));
	
	if (!randomNums)
	{
		print("Random array allocation failed!\n");
		exits(nil);
	}
	// loop through the array and assign rnd
	for (i = 0; i < aSize; i++)
	{
		randomNums[i] = (rand() % 500) + 1;
	}
	// initialize the biggest and smallest number
	biggest = 0;
	smallest = 500;

	// loop through the filed array and test for numbers that are 
	// biggest and smallest, add and caluclate the average

	for (i = 0; i < aSize; i++)
	{
		total += randomNums[i];
		if (randomNums[i] > biggest)
		{
			biggest = randomNums[i];
		}
		if (randomNums[i] < smallest)
		{
			smallest = randomNums[i];
		}
	}

	average = ((float)total)/((float)aSize);
	print("The biggest random number is %d.\n", biggest);
	print("The smallest random number is %d.\n", smallest);
	print("The average of the random number is %.2f.\n", average);

	// don't forget to free the memory
	free(randomNums);

	return 0;
	
}