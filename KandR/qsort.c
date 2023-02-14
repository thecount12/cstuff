#include <u.h>
#include <libc.h>
#define MAXLINES 5000 // max lines to be sorted
#define MAXLEN 1000

char *lineptr[MAXLINES]; // pointers to the next lines
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void vqsort(char *lineptr[], int left, int right);
int getline(char *, int);
char *alloc(int);

// sort input lines
main()
{
	int nlines;  // num lines read
	if ((nlines = readlines(lineptr, 5000)) > = 0)
	{
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		print("error: input too big to sort\n");
		return 1;
	}
	return 0;
}

int
readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while((len = getline(line, MAXLEN)) > 0)
	{
		if(nlines >= maxlines || p = alloc(len) == NULL)
		{
			return -1;
		}
		else
		{
			line[len-1] = '\0'; // delete newline
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void
writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
	{
		print("%s\n", lineptr[i]);
	}
}

void
vqsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
	{
		exits(nil);
	}
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+i; i <= right; i++)
	{
		if (strcmp(v[i], v[left]) < 0)
		{
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v last+1, right);
}
