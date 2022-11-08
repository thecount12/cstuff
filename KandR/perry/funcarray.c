#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page 299 with pointer in function

int
half(int *i)
{
	*i = *i /2;
	print("Your value halved is %d.\n", *i);
	return 0;
}

main()
{
	int i;
	print("Please enter an integer... ");
	scanf(" %d", &i);
	half(&i);
	print("In min(), i is now %d.\n", i);
	return 0;
}
