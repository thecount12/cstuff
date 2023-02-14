#include <u.h>
#include <libc.h>

int moon_phase(int year, int month, int day)
{
	int d;
	int g;
	int e;
	d = day;
	if(month == 2)
		d+=31;
	else if(month > 2)
		d +=59+(month-3)*30.6+0.5;
	g = (year-1900)%19;
	e = (11*g +29) %30;
	if(e== 25 || e == 24)
		++e;
	return ((((e+d)*6+5)%177)/22 &7);
}

main()
{
	int data;
	print("hello\n");
	data = moon_phase(2022,2,10);
	print("The moon is %d\n", data);
	return 0;
}