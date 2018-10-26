/*
Author: Yost
Project: Performance Lab 7.5
Date: 18 July 2018

NESTED CONTROL FLOW

Print all the even or odd numbers from 0 to 100.
Prompt the user for input to indicate odds or evens.
Loop from 0 to 100 and print all indicated numbers.
Use an IF statement to check if even or odd.

BONUS: Ask the user to continue with a DO-WHILE loop

* write a version with the counting loop written as a FOR loop, and a WHILE loop version.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int max = 0;
	int min = 0;
	int i = 0;
	int choice;

	//ask user for lower limit
	printf("What is the lower limit?  Please enter a positive integer value.\n");
	scanf("%d", &min);

	if (min < 0)
	{
		printf("You must enter a number greater than or equal to 0 for the lower limit.");
	}

	//ask user for the upper limit
	printf("What is the upper limit?  Please enter an integer greater than 0.\n");
	scanf("%d", &max);

	if (max <= 0)
	{
		printf("You must enter a number greater than 0 for the upper limit.");
	}

	//makes sure upper limit is greater than lower limit
	if (max <= min)
	{
		printf("You upper limit must be greater than your lower limit");
		while (1);
		return 0;
	}

	//ask user if they want to print even or odd numbers
	printf("Would you like to see all even numbers or all odd numbers from %d to %d?\nEnter <0> for even numbers or <1> for odd numbers.\n", min, max);
	scanf("%d", &choice);

	if ((choice != 0) || (choice != 1))
	{
		printf("That is an invalid choice.  You must enter <0> for even or <1> for odd.");
	}

	//print all even numbers in the range
	if (choice == 0) 
	{
		printf("The even numbers between %d and %d are: ", min, max);
		for (i = min; i <= max; i++)
		{
			if (i % 2 == 0)
			{
				printf("%d, ", i);
			}
		}
	}
	//print all odd numbers in the range
	if (choice == 1) 
	{
		printf("The odd numbers between %d and %d are: ", min, max);
		for (i = min; i <= max; i++)
		{
			if (i % 2 == 1)
			{
				printf("%d, ", i);
			}
		}
	}
	while (1);
	return 0;
}
