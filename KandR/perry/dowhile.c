#include <u.h>
#include <libc.h>
#include <stdio.h>

main()
{
	float num1, num2, result;
	char choice;
	
	do {
		print("Enter your first number: ");
		scanf(" %f", &num1);
		print("Enter your second number: ");
		scanf(" %f", &num2);
		result = num1 * num2;
		print("%.2f times %.2f equalas %.2f\n\n", num1, num2, result);
		print("Do you want to enter new numbers ");
		print("to multiply (Y/N): ");
		scanf(" %c", &choice);
		if (choice == 'n') {
			choice = 'N';
		}
	} while (choice != 'N');

	return 0;
}
