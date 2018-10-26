/*
Author: Yost
Title: Performance Lab 7.2 A
Date: 17 July 2018

IF STATEMENT

Initialize a char array to zero.
Safely store a user-input string in the char array.
Safely print the string IF the following conditions are both true:
The first element greater than or equal to decimal value 32.
The first element is less than decimal value 126.

*/

#include <stdio.h>

/*int main(void)
{
	char array[255] = { 0 }; //init array to zero

	printf("Tell me something good:");
	scanf("%255[^\n]s", &array); //store user input sting in array

	if (((array[0]) >= 32) && ((array[0] < 126)))
		printf("%s", array); //print if 32 <= array[0] < 126

	while (1);

	return 0;
}
*/
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