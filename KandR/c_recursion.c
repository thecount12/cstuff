#include <u.h>
#include <libc.h>
#include <stdio.h>

// K&R page 78
// not a great example in the book I would rewrite this


void
printd(int n)
{
	if (n > 0)  // book had this flipped
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

main()
{
	print("start recursion\n");
	printd(10);
	return 0;
}
