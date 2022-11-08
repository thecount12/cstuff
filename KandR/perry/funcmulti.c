#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 300-301
// warning: funcmulti.c:7 set and not used: i 

void
changeSome(int i, float *newX, int Array[5])
{
	int j;
	i = 47;
	print("%d", i);
	*newX = 97.6;
	for (j = 0; j < 5; j++)
	{
		Array[j] = 100 + 100*j;
	}
	//return 0;
}

main()
{
	int i = 10;
	int ctr;
	float x = 20.5;
	int Array[] = {10, 20, 30, 40, 50};
	puts("Here are main()'s variables before the function:");
	print("i is %d\n", i);
	print("x is %.1f\n", x);
	for (ctr = 0; ctr < 5; ctr++)
	{
		print("Array[%d] is %d\n", ctr, Array[ctr]);
	}
	
	changeSome(i, &x, Array);
	puts("\n\nHere are main()'s variables after the function:");
	print("i is %d\n", i);
	print("x is %.1f\n", x);
	for (ctr = 0; ctr < 5; ctr++)
	{
		print("Array[%d] is %d\n", ctr, Array[ctr]);
	}
	
	return 0;
}

