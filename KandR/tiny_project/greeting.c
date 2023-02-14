#include <u.h>
#include <libc.h>

// tiny c: page: 17

int main()
{
	long tp;
	time(&tp);
	print("The computer thinks it's %ld\n", tp);
	print("%s", ctime(tp));
	return 0;
}