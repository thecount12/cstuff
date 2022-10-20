#include <u.h>
#include <libc.h>
#include "head.h"
// perry page: 63

main()
{
	int age;
	char childname[14] = "Thomas";
	print("\n%s have %d kids.\n", FAMILY, KIDS);

	age = 11;
	print("The oldest, %s, is %d.\n", childname, age);

	strcpy(childname, "Christopher");
	age = 6;
	print("the middle boy, %s, is %d.\n", childname, age);

	age = 3;
	strcpy(childname, "Benjamin");
	print("The youngest, %s, is %d.\n", childname, age);

	return 0;

}
