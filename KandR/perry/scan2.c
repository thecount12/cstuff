#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 70-71

main()
{
	char topping[10];
	int slices;
	int month, day, year;
	float cost;
	
	print("How much does a pizza cost in your area? ");
	print("enter as $xx.xx)\n");
	scanf(" $%f", &cost); // I need to enter $ before decimal values
	
	print("cost: %f\n", cost);

	print("What is yor favorite one word pizza topping?\n");
	scanf("%s", topping); // char array does not need pointer
	print("topping: %s\n", topping);

	
	print("how man slices of %s pizza ", topping); 
	print("can you eat in one sitting?\n");
	scanf(" %d", &slices);

	print("What is today's date (enter it in xx/xx/xx format).\n");
	scanf(" %d/%d/%d", &month, &day, &year);

	print("\n\nWhy not treat yourself to dinner on %d/%d/%d", month, day, year); // needs reference

	print("\nand have %d slilces of %s pizza!\n", slices, topping);
	print("It will only cost you $%.2f!\n\n\n", cost);
	
	return 0;
	

}

