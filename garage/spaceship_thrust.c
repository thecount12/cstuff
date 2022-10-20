#include <u.h>
#include <libc.h>

/* 
 * === Spaceship Thrust === 
 *
 * We are working on the man-machine interface of a revolutionary spaceship.
 * Define enumeration constants for different predefined thrust levels, these
 * levels will be used to communicate with the engine controller.
 * 
 * The thrust levels are:
 *  - none:     0
 *  - low:      5
 *  - medium:   9
 *  - high:     12
 *  - maximum:  20
 * 
 * Then launch the rocket!
 * We now want to log the thrust level in some critical points:
 *  - set thrust to none ---> log ready to go level
 *  - set thrust to maximum ---> log take off level
 *  - set thrust to medium ---> log entry into the ionosphere
 *  - set thrust to low ---> log traveling to deep space
 * 
 */

typedef enum
{
	NONE = 0,
	LOW = 5,
	MED = 9,
	HIGH = 12,
	MAX = 20,
} Thrust;

void
main(int, char* [])
{
	
	Thrust none = NONE;
	Thrust max = MAX;
	Thrust med = MED;
	Thrust low = LOW;
	Thrust high = HIGH;

	print("\n\n=== ThinkTankWorkspaces ===\n\n");
	print("Ready to go level: %d\n", none);
	print("Take off level: %d\n", max);
	print("Enter into the ionosphere %d\n", med);
	print("Traveling to deep space: %d\n", low);
	print("\n\n=== ThinkTankWorkspaces ===\n\n");

	print("high: %d\n", high);
	exits(nil);
}
