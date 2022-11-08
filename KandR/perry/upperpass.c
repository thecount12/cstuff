#include <u.h>
#include <libc.h>
#include <stdio.h>
#include <ctype.h>

// perry page: 175 ctype

main()
{
	int i;
	int hasUpper, hasLower, hasDigit;
	char user[25], password[25];
	hasUpper = hasLower = hasDigit = 0;

	print("What is user username? ");
	scanf(" %s", user);
	print("Please create a password: ");
	scanf(" %s", password);

	for (i=0; i<strlen(password); i++) {
		if (isdigit(password[i])) {
			hasDigit = 1;
			continue;
		}
		if (isupper(password[i])) {
			hasUpper = 1;
			continue;
		}
		if (islower(password[i])) {
			hasLower = 1;
		}
	}
	if ((hasDigit) && (hasUpper) && (hasLower)) {
		
		print("\n\nExcellent work, %s, \n", user);
		print("Your password has upper and lowercase ");
		print("letters and a number.\n");
	} else {
		print("\n\nYou should consider a new password, %s, \n", user);
		print("One that uses upper and lowercase letters ");
		print("and a number.\n");
	}
	return 0;

}