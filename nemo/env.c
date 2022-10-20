#include <u.h>
#include <libc.h>

void
main(int, char*[])
{
	char* home;
	home = getenv("home");
	if (home == nil)
		sysfatal("we are not here");
	print("home is %s\n", home);
	exits(nil);
}