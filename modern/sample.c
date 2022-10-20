#include <u.h>
#include <libc.h>

void
main(int, char* [])
{
	int i;
	double A[5] = {
		[0] = 2.9,
		[1] = 2.4,
		[2] = 4.2,
		[3] = .007,
	};

	// do some work
	for (i= 0; i<5; ++i)
	{
		print("element %d is %g, \tits square is %g\n",
			i,
			A[i],
			A[i]*A[i]);
	}
	exits(nil);


}
