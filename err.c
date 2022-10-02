#include <u.h>
#include <libc.h>

void
main(int, char* [])
{
	DIR *d;
	struct dirent 
	
	if (chdir("magic") < 0) {
		fprint(2, "chdir failed: %r\n");
		exits("failed");
	}
	print("interesting");
	

	exits(nil);
}