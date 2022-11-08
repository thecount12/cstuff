#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 226-228

main()
{
	int kids;
	float price;
	char code;

	int * pKids;	
	float * pPrice;
	char * pCode;

	price = 17.50;
	pPrice = &price;

	print("\nHow many kids are you taking to the water park? ");
	scanf(" %d", &kids);
	pKids = &kids;
	
	print("\nDo you have a discount ticket for the park?");
	print("\nEnter E for Employment Disc ount, S for Sav-More ");
	printf("\Discount, or N ofr No Disc ount: ");
	scanf(" %c", &code);
	pCode = &code;

	printf("\nFirst let's do it with the variables:\n");
	print("You've got %d kids...\n", kids);
	switch (code)
	{
		case ('E'): 
			print("The employee discount saves you 25%% on the ");
			print("$%.2f price", price);
			print("\nTotal ticket cost: $%.2f", (price*.75*kids));
			break;
		case ('S'):
			print("The Sav-more discount saves you 15%% on the ");
			print("$%.2f price", price);
			print("\nTotal ticket cost: $%.2f", (price*.85*kids));
			break;
		default:
			print("You will be paying full price of ");
			print("$%.2f for your tickets", price);
	}

	// ----------------------------------------------------
	// repeate same thing but use dereferenced
	print("\n\n\nNow let's do it with the pointers:\n");
	print("Yo've got %d kids...\n", *pKids);

	switch (*pCode)
	{
		case ('E'): 
			print("The employee discount saves you 25%% on the ");
			print("$%.2f price", *pPrice);
			print("\nTotal ticket cost: $%.2f", 
				(*pPrice * .75 * *pKids));
			break;
		case ('S'):
			print("The Sav-more discount saves you 15%% on the ");
			print("$%.2f price", *pPrice);
			print("\nTotal ticket cost: $%.2f", 
				(*pPrice * .85 * *pKids));
			break;
		default:
			print("You will be paying full price of ");
			print("$%.2f for your tickets", price);
	}
	return 0;

}