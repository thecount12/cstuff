#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 67

main()
{
	char firstIL;
	char lastIL;
	int age;
	int fav_num;

	print("Whate letter does your first name begin with?\n");
	scanf(" %c", &firstIL);

	print("Whater letter does your last name begin with?\n");
	scanf(" %c", &lastIL);

	print("How old are you?\n");
	scanf(" %d", &age);

	print("What is your favorite number (integer only)?\n");
	scanf(" %d", &fav_num);

	print("Your initials are %c.%c. and you are %d years old",
firstIL, lastIL, age);
	print("\nYour favorite number is %d.\n\n", fav_num);

	return 0;
}
