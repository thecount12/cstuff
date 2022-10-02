#include <u.h>
#include <libc.h>

void
main(int, char* [])
{
	char b = 'B';
	char var;
	
	print("the char: %d\n", b);
	print("the char: %c\n", b);
	print("Input a char: ");
	var = getchar();
	print("the char is %c\n", var);


}