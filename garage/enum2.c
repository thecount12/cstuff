#include <u.h>
#include <libc.h>

typedef enum
{
	TEA, // 0 can assign a different value TEA = 10, can be offset
	COFFEE, // 1
	JUICE,
	BEER,
} Menu;


void
main(int, char* [])
{
	Menu mario = COFFEE;
	Menu andrea = BEER;

	print("Mario ordered: %d\n", mario);
	print("Andrea ordered: %d\n", andrea);
	
	print("\n\n=== ThinkTankWorkspaces ===\n\n");
	exits(nil);

}