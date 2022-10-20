#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry book 152-153 exit(1) is exits(nil) in plan9

main()
{
	int choice;
	print("What do you want to d?\n");
	print("1. Add New Contact\n");
	print("2. Edit Existing Contact\n");
	print("3. Call Contact\n");
	print("4. Text Contact\n");
	print("5. Exit\n");
	do {
		print("Enter your choice: ");
		scanf(" %d", &choice);
		switch (choice) {
			case (1): print("\nTo add you will need the ");
					  print("contact's\n");
					  print("First name, last name, and number.\n");
					  break;
			case (2): print("\nGet ready to enter the name of ");
					  print("name of the \n");
					  print("contact you wish to change.\n");
					  break;
			case (3): print("\nWhich contact do you ");
					  print("wish to call?\n");
					  break;
			case (4): print("\nWhich contact do you ");
					  print("wish hto text?\n");
					  break;
			case (5): exits(nil);
			default:  print("\n%d is not a valid choice. \n", choice);
					  print("Try again.\n");
					  break;
		}
	} while ((choice < 1) || (choice > 5));
	return 0;
}
