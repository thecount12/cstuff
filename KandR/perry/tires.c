#include <u.h>
#include <libc.h>
#include <stdio.h>
// perry page: 76-77


#define SALESTAX .07

main()
{
	int numTires;
	float tirePrice, beforeTax, netSales;
	float x = 19.0;
	float y = 5.1;
	float answer;
	answer = x/y;
	print("blah: %.2f\n", answer);
	
	print("How many tires did you purchase? ");
	scanf(" %d", &numTires);
	// again i need to add $
	print("What was the cost per tire (enter in $xx.xx format)? ");
	scanf(" $%2f", &tirePrice);
	// Compute the price

	beforeTax = tirePrice * numTires;
	print("before tax: $%f\n", beforeTax);
	netSales = beforeTax + (beforeTax * SALESTAX);

	print("You spent $%.2f on your tires\n\n\n", netSales);
	

	return 0;
}
