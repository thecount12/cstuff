#include <u.h>
#include <libc.h>

void
main(int, char* [])
{
	char msg[] = "hello\n";
	int fd;
	fd = open("/usr/glenda/code/cstuff/afile", OWRITE);
	write(fd, msg, strlen(msg));
	close(fd);
	exits(nil);
}