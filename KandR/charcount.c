#include <u.h>
#include <libc.h>
#include <stdio.h>

# define MAXLINE 1000 // max input by length

void
copy(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0') 
	{
		++i;
	}
}

int
getline(char s[],int lim)
{
	int c;
	int i;

	for (i=0; i<lim-1 && c=getchar()!=nil && c!='\n'; i++)
	{
		s[i] = c;
		if (c == '\n')
		{
			s[i] = c;
			++i;
		}
		s[i] = '\0';
	//	return i;
	}
	return i;
}

main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while((len = getline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) {
		print("%s", longest);
	}
	return 0;
}

