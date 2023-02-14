#include <u.h>
#include <libc.h>
#include <stdio.h>

// K&R page 78
// not a great example in the book I would rewrite this
// my new code counts down from 10..1

void
recur(int n)
{
	print("num: %d\n", n);
	if (n == 0)  // book had this flipped
	{
		exits(nil);
	}
	else
	{
		n = n -1;
		recur(n);
	}
}

main()
{
	print("start recursion\n");
	recur(10);
	return 0;
}
