#include <u.h>
#include <libc.h>
#include <stdio.h>
#include <ctype.h>

// perry page: 189-190

main()
{
	int dice1;
	int dice2;
	int total1; 
	int total2;
	long tp;
	char ans;

	//print("dice1: %d, dice2: %d\n, total1: %d, total2L %d\n", dice1,dice2,total1,total2);
	print("");
	srand(time(&tp)); // random mixed with time for seed
	dice1 = (rand() % 5) + 1;
	dice2 = (rand() % 5) + 1;
	total1 = dice1 + dice2;
	print("First roll of the dice was %d and %d, ", dice1, dice2);
	print("for a total of %d.\n\n\n", total1);
	do {
		puts("Do you think the next roll will be ");
		puts("(H)igher, (L)ower, or (S)ame?\n");
		puts("Enter H, L, or S to reflect your guess.");
		scanf(" %c", &ans);
		ans = toupper(ans);
	} while ((ans != 'H') && (ans != 'L') && (ans != 'S'));
	dice1 = (rand() % 5) + 1;
	dice2 = (rand() % 5) + 1;
	total2 = dice1 + dice2;
	print("First roll of the dice was %d and %d, ", dice1, dice2);
	print("for a total of %d.\n\n\n", total1);
	if (ans == 'L')
	{
		if (total2 <total1)
		{
			print("Good job! Youo were right!\n");
			print("%d is lower than %d\n", total2, total1);
		}
		else
		{
			print("Sorry! %d is not lower than %d\n\n", total2, total1);
		}
	}
	else if (ans == 'H')
	{
		if (total2 > total1)
		{
			print("Good job! You are right!\n");
			print("%d is higher than %d\n", total2, total1);
		}
		else
		{
			print("Sorry! %d is not higher than %d\n\n", total2, total1);
		}
	}
	else if (ans == 'S')
	{
		if (total2 == total1)
		{
			print("Good job! You are right!\n");
			print("%d is the same as as %d\n\n", total2, total1);
		}
		else
		{
			print("Sorry ! %d is not the same as %d\n\n", total2, total1);
		}
	}
	else
	{
		print("Cool");
	}
	return 0;

}