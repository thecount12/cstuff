#include <u.h>
#include <libc.h>

// perry book 217

main()
{
	int ctr;
	int idSearch;
	int found = 0;

	int custID[10] = {313, 345, 502, 101, 892, 475, 792, 912, 343, 633};
	float custBal[10] = {0.00, 45.43, 71.23, 301.56, 9.08, 192.41,
						 389.41, 229.67, 18.31, 59.54};
	int tempID, inner, outer, didSwap, i;
	float tempBal;

	for (outer = 0; outer < 9; outer++)
	{
		didSwap = 0; // true if not yet ordered
		for (inner = outer; inner< 10; inner++)
		{
			if ( custID[inner] < custID[outer] )
			{
				tempID = custID[inner];
				tempBal = custBal[inner];
				custID[inner] = custID[outer];
				custBal[inner] = custBal[outer];
				custID[outer] = tempID;
				custBal[outer] = tempBal;
				didSwap = 1; // true because a swap too place
			}
		}
		if (didSwap == 0)
		{
			break;
		}

	}
	// left of on page 218

}