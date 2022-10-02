#include <u.h>
#include <libc.h>

void
main(int, char* [])
{
	char msg[] = "hello\n";
	int item;
	item = strlen(msg);
	write(1, msg, item);
	exits(nil);
}