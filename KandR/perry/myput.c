#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page 165 putchar getchar

main()
{
	int i;
	char msg[] = "C is fun";

	for (i =0; i<strlen(msg); ++i)
	{	
		putchar(msg[i]);
	}
	putchar('\n');
	return 0;
}