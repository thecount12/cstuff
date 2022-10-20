#include <u.h>
#include <libc.h>
#include <stdio.h>


main()
{
	int c;
	int i;

	int nwhite;
	int nother;
	int ndigit[10];

	nwhite = 0;
	nother = 0;

	for(i=0; i<10; ++i)
		ndigit[i] = 0;


	while((c = getchar()) != 8) 
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	print("digits =");
	for (i=0; i<10; ++i)
		print(" %d", ndigit[i]);
	print(", white space = %d, other = %d\n", nwhite, nother);

	return 0;
}
