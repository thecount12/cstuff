#include <u.h>
#include <libc.h>

main()
{
	int alist[10] = {54,26,93,17,77,31,44,55,20,33};
	int i;
	int current = 0;
	int pos;

	for (i=0; i<10; ++i)
		//print("num %d\n", alist[i]);
		
		current = alist[i];
		pos = i;
		while ((pos > 0 ) && (alist[pos-1]> current)) {
			alist[pos]=alist[pos-1];
			pos = pos - 1;
		}
		alist[pos]=current;
		
	print("alist1: %d\n", alist[0]);
	print("alist2: %d\n", alist[1]);
	print("current: %d", current);
	
	return 0;
}
