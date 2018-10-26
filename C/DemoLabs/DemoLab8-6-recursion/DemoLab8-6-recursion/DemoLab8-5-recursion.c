/*
Author: Yost
Title: DemoLab 8-5 Recursion
Date: 19 July 2018

Fibonacci Number


Purpose
Define fibonacci_number() as a recursive function that returns a Fibonacci number of position "sequenceNumber"
Allow the user to choose how many numbers are calculated
Parameters
Fibonacci Sequence number position to calculate
Return Value
sequenceNumber
-1 if sequenceNumber is unrealistic
The Fibonacci Sequence:
Starts with 0 and 1 then each subsequent number is calculated by adding the two previous sequence numbers
F(n) = F(n-1) + F(n-2)

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//prototype fibonacci function
int fibonacci_number(int fibNum);

int main(void)
{
	int choice = 0;
	int result = 1;
	int i = 0;

	//ask user to pick number of sequence
	printf("How many numbers of the Fibonacci Sequence would you like to see?\nEnter a number greater than 0: ");
	scanf("%d", &choice);

	//reject invalid choices
	if (choice <= 0)
	{
		printf("You must choose a number greater than 0.");
	}

	//run function
	for (i = 1; i <= choice; i++)
	{
		result = fibonacci_number(i);
		printf("Position %d of the Fibonacci Sequence is: %d\n", i, result);
	}
	//result = fibonacci_number(choice);
	//printf("Ans: %d", result);

	while (1);
	return 0;
}

//prototyped function
int fibonacci_number(int fibNum)
{
	int answer = 1;
	//base case, initialize the first two values of the fibonacci sequence
	if ((1 == fibNum) || (2 == fibNum))
	{
		return 1;
	}
	
	//recursive call
	else
	{
		answer = (fibonacci_number(fibNum - 1) + (fibonacci_number(fibNum - 2)));
	}
	return answer;
}
