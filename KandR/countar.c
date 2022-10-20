#include <u.h>
#include <libc.h>
/* int arr[10] = {0,5,3,64}
arr[4] 5; */

void
main()
{
	int i;
	//nwhite, nother;
	int ndigit[10] = {1,3,4,10,9,2,8,5,7,6};

	//nwhite = nother = 0;

	for(i=0; i< 10; i++) {
		//ndigit[i] = 0;
		print("num: %d\n", ndigit[i]);
	}
		
	print("hello");
	exits(nil);

}
