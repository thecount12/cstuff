#include <u.h>
#include <libc.h>

enum menu
{
	TEA, // 0 can assign a different value TEA = 10, can be offset
	COFFEE, // 1
	JUICE,
	BEER,
};


void
main(int, char* [])
{
	enum menu mario = COFFEE;
	enum menu andrea = BEER;

	print("Mario ordered: %d\n", mario);
	print("Andrea ordered: %d\n", andrea);
	
	print("\n\n=== ThinkTankWorkspaces ===\n\n");
	exits(nil);

}
