#include <u.h>
#include <libc.h>


void
main(int, char* [])
{
	// no bools in plan9
	//bool abool = true;
	//bool bbool = false;

	int abool = 1;

	if (abool == 1) {
		print("a (true): %d\n", abool);
	} else {
		print("a (false): %d\n", abool);
	}
	print("\n\n=== ThinkTankWkspaces ===\n\n");
	exits(nil);

}


