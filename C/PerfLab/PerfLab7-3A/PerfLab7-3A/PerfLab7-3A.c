/*
Author: Yost
Title: Performance Lab 7.3 A
Date: 17 July 2018

FOR LOOP: OCCUPANDI TEMPORIS

Following demo lab 1 for 7.3, you should have identified your past code/programs where a for loop would have been more economical. 
Well NOW is your chance. Create a C file where your previous code is commented out and directly underneath, you implement a for loop.

*/

#include <stdio.h>

int main(void)
{
	int age[13] = { 0 };
	int i = 0;

	/*
	age[0] = 28;
	age[1] = 30;
	age[2] = 33;
	age[3] = 28;
	age[4] = 32;
	age[5] = 29;
	age[6] = 36;
	age[7] = 19;
	age[8] = 26;
	age[9] = 23;
	age[10] = 21;
	age[11] = 34;
	age[12] = 24;
	*/

	for (i = 0; i < 13; i++)
	{
		age[i] = i + 20;
	}


	char quote[256] = { "The\n only\n thing\n necessary\n for\n the\n triumph\n of\n evil\n is\n for\n good\n men\n to\n do\n nothing.\n ~Edmund Burke" };
	quote[255] = 0;

	printf("The instructor's age is %d. \n", age[0]);
	printf("The students' ages are %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, and %d. \n",
		age[1], age[2], age[3], age[4], age[5], age[6], age[7], age[8], age[9], age[10], age[11], age[12]);

	printf("The quote is: \n %s \n", quote);


	while (1);
	return 0;
}