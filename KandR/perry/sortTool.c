#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 212-214

main()
{
	int ctr;
	int inner, outer, didSwap, temp;
	int nums[10];
	long tp; // time_t t; in modern c
	
	srand(time(&tp));
	// fill array with random
	for (ctr = 0; ctr<10; ctr++)
	{
		nums[ctr] = (rand() %99) +1;
	}
	// print data in array
	for (ctr = 0; ctr<10; ctr++)
	{
		print("%d\n", nums[ctr]);
	}

	// sort array
	for (outer = 0; outer <9; outer++)
	{
		didSwap = 0; // true if list is not yet ordered
		for (inner=outer; inner<10; inner++)
		{
			if (nums[inner] < nums[outer])
			{
				temp = nums[inner];
				nums[inner] = nums[outer];
				nums[outer] = temp;
				didSwap = 1;
			}
		}
		if (didSwap == 0)
		{
			break;
		}
	}
	puts("\nHere is the list after the sort:");
	for (ctr = 0; ctr<10; ctr++)
	{
		print("%d\n", nums[ctr]);
	}

	return 0;
}