#include <u.h>
#include <libc.h>

void
swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void
mqsort(int v[], int left, int right)
{
	int i, last;
	swap(int v[], int i, int j);
	if (left >= right)
		exits(0);
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if (v[i] < v[left])
		{
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	mqsort(v, left, last-1);
	mqsort(v, last+1, right);		
}

main()
{
	mqsort([3,5,3]);
	return 0;
}