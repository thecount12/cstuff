#include <u.h>
#include <libc.h>
#include <stdio.h>

/* sig localtime and man localtime
char* ctime(long clock)
Tm*   localtime(long clock)
Tm*   gmtime(long clock)
char* asctime(Tm *tm)
long  tm2sec(Tm *tm)

also look for struc in ctime or localtime man page
*/
  


main()
{

	long now;
	struct Tm *clock;
	time(&now);
	print("%s", ctime(now));
	clock = localtime(now);
	puts("Time details:");
	print(" Day of the year: %d\n", clock->yday);

	return 0;
}