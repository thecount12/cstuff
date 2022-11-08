#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 166 prints it out in reverse

main()
{
	int i;
	char msg[25];
	print("Type up to 25 char and press enter...\n");
	for (i=0; i<25; i++) {
		msg[i] = getchar();
		if (msg[i] == '\n') {
			i--;
			break;	
		}

	}
	putchar('\n');
	for (; i>=0; i--) {
		putchar(msg[i]);
	}
	putchar('\n');
	return 0;
}

