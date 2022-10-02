#include <u.h>
#include <libc.h>

void
main(int, char*argv[])
{
	/* lets create a problem */
	print("hi ");
	print(argv[1]);
	exits(nil);
}
