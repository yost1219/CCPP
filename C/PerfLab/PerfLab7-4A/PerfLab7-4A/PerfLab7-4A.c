/*
Author: Yost
Title: Performance Lab 7.4 A
Date: 18 July 2018


Input an unsigned integer "x".
Print the first 20 positive integers that x is divisible by utilizing the mod operator (not the most efficient)
Repeat this process.
Immediately stop this process when the user inputs an integer above 999.
Ignore any "divide by 0" errors using continue.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	unsigned int x = 0; //input
	int count1 = 0; //counter
	int count2 = 1; //holder

	printf("Input an integer between 1 and 999, inclusively.\n");
	scanf("%d", &x);

	if ((x <= 0) || (x >= 1000)) //makes sure the input is in the desired range
	{
		printf("You must select an integer in the range 1 - 999.\n");
	}
	while (count1 < 20 && x < 1000 && count2 <= x) //"count1 < 20" searches for first 20 answers, "count2 <= x" means x will be included in the search
	{
		if (x == 0) //if theyput in a value of 0 and somehow got around the first if then this will catch them
		{
			continue;
		}
		if (x % count2 == 0) //checks to see if x is evenly divisible by a number, if yes it enters the loop
		{
			printf("Your number is evenly divisible by %d.\n", count2);
			count1++;
		}
		count2++;
	}
	while (1);
	return 0;
}


/*

Author: Robert Graham

int main(void)
{
unsigned int input = 0;
int counter = 0;
int test = 1;
printf("Input a number: ");
scanf("%d", &input);
while (counter < 20 && input < 999 && test <= input)
{
if (test == 0)
{
continue;
}
if (input % test == 0)
{
printf("%d divides into %d\n", test, input);
counter++;
}
test++;
}
printf("Loop is done.");
while (1);
return 0;
}
*/



/*
Create a tailored times table
REQUIREMENTS:
- Input an integer "x".
- Print the product of x and y when y ranges from 1 through 10.
- Exit if the user inputs an integer larger than 10.
- Use continue to ignore any zeroes or negative numbers
in x, while repeating the loop.


#include <stdio.h>

int main()
{
	int x = 0;      // User inputted number
	int y = 1;      // Increment var

	printf("Enter a number between 1-10: ");
	scanf("%4d", &x);

	// Prevents user from enter a number over 10... exits
	if (x > 10)
	{
		printf("Senpai!! You can't enter numbers larger than 10");
		return 0;
	}

	// print x * y, increment y until equal to 10.
	while (y <= 10)
	{
		// Add 1 to x until positive
		if (x <= 0)
		{
			printf("Skipping Number %d! Adding 1.\n", x);
			x++;
			continue;
		}
		printf("%d x %d = %d\n", x, y, x*y);
		y++;
	}
}
*/