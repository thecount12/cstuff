#include <u.h>
#include <libc.h>

// perry page: 290-291
// I had to move stuff around and add plan9 void stuff 

int g1 = 10;
float g2 = 19.0;

void
prAgain(void)
{
	int L2 = 5;
	print("%d %.2f %d\n", L2, g2, g1);
	//return 0;
}

main()
{
	float L1;
	L1 = 9.0;
	print("%d %.2f\n", g1, L1);
	prAgain();
	return 0;
}
