/*
Author: Yost
Title: PerfLab 8C Recursion
Date: 19 July 2018


Purpose
Define shadow_sequence_number() as a recursive function that returns a "shadow sequence" number of position "placeNumber"
Do not calculate a sequence number greater than 2300
Parameters - Shadow Sequence number position to calculate
Return Value
placeNumber on success
105 if placeNumber is unrealistic or dangerous
The Shadow Sequence:
Starts with 9 and 0 then each subsequent number is calculated by adding the previous value and the square of the position
S(n) = S(n-1) + (n*n)

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned long shadow_sequence_number(int placeNumber); //prototype function

int main(void)
{
	int choice = 0;
	int result = 1;
	int i = 0;

	//ask user to pick number of sequence
	printf("How many numbers of the Shadow Sequence would you like to see?\nEnter a number between 1 and 2300: ");
	scanf("%d", &choice);

	//reject invalid choices
	if ((choice <= 0) || (choice > 2300))
	{
		printf("You must choose a number greater than 0 and less than 2300.");
	}

	//run function
	for (i = 1; i <= choice; i++)
	{
		result = shadow_sequence_number(i);
		printf("Position %d of the Shadow Sequence is: %d\n", i, result);
	}
	//result = shadow_sequence_number(choice);
	//printf("Ans: %d", result);

	while (1);
	return 0;
}
//prototyped function
unsigned long shadow_sequence_number(int placeNumber)
{
	int answer = 1;
	//base case 1, initialize first value
	if (1 == placeNumber)
	{
		return 9;
	}
	//base case 2, initialize second value
	else if (2 == placeNumber)
	{
		return 0;
	}
	//recursive call
	else
	{
		answer = shadow_sequence_number(placeNumber - 1) + (placeNumber * placeNumber);
	}
	return answer;
}