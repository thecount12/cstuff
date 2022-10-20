#include <u.h>
#include <libc.h>
/* perry page: 55-56 */

main()
{
	char Kid1[12];
	char Kid2[] = "Maddie";
	char Kid3[7] = "Andrew";
	char Hero1[] = "Batman"; // char Hero1 = "Batman"; will not work in plan9
	char Hero2[34] = "Spiderman";
	char Hero3[25];

	Kid1[0] = 'K';
	Kid1[1] = 'a';
	Kid1[2] = 't';
	Kid1[3] = 'i';
	Kid1[4] = 'e';
	Kid1[5] = '\0';

	strcpy(Hero3, "The Incredible Hulk");

	print("%s\'s favorite hero is %s.\n", Kid1, Hero1);
	print("%s\'s favorite hero is %s.\n", Kid2, Hero2);
	print("%s\'s favorite hero is %s.\n", Kid3, Hero3);

	return 0;
}
