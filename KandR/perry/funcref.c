#include <u.h>
#include <libc.h>

// perry page: 297-298

char
change(char name[15])
{
	strcpy(name, "XXXXXXXXXXX");
	return 0;
}

main()
{
	char name[15] = "Michael Hatton";
	change(name);
	print("Back in main(), the name is now %s.\n", name);
	return 0;
}