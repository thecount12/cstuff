#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 295-296

int
half(int i)
{
	i = i / 2;
	print("Your value halved is %d.\n", i);
	return 0;
}

main()
{
	int i;
	print("Please enter an integer... ");
	scanf(" %d", &i);
	half(i);
	print("In main(), i is still %d.\n", i);
	return 0;
}
