/*
Author: Yost
Project: Performance Lab 7-2 B
Date: 17 July 2018

IF-ELSE STATEMENT

Initialize a signed int to 0.
Input a number from the user and store it in the signed int.
Determine if the number is negative or positive utilizing a bitwise operator.
Utilizing an IF-ELSE statement:
INDICATE if the number is negative
Otherwise, print the original value in binary, and use a bitwise operation to flip one bit to make it negative
Print the binary

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number = 0; //initialize signed int to 0
	int seven = 0, six = 0, five = 0, four = 0, three = 0, two = 0, one = 0;

	printf("Pick a number, any number (between -127 and 127).");
	scanf("%d", &number); //input and store number from user

	seven = number / 64;
	six = (number % 64) / 32;
	five = (number % 32) / 16;
	four = (number % 16) / 8;
	three = (number % 8) / 4;
	two = (number % 4) / 2;
	one = number % 2;

	//determine if number is positive or negative (or neither)
	//if (number < 0) 
	if (number & (1 << 31)) //compares the input with leading 1 with 31 0s in binary (which is -0) to see if number is also negative
	{
		printf("Your number is negative.");
	}
	else if (number == 0)
	{
		printf("Your number is neither negative nor positive.");
	}
	else
	{
		printf("Your number is positive.\n");
		printf("Your number in binary is:         0%d%d%d%d%d%d%d\n", seven, six, five, four, three, two, one);
		printf("Your number flipped in binary is: 1%d%d%d%d%d%d%d\n", seven, six, five, four, three, two, one);
		//input = ~input + 1  this flips all of the bits of input and adds one to give you -(input)
	}
	
	while (1);

	return 0;
}

/*
 Performance Lab for IF ELSE Statements
* July 17, 2018
* Robert John Graham III


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 
#include <stdio.h>

int main(void)
{
	int input = 0;
	int bitNeg = 0;
	printf("Input a number: ");
	scanf("%d", &input);
	bitNeg = 1 + (input >> 31) - (-input >> 31);
	if (bitNeg == 0)
	{
		printf("Your input number %d is negative", input);
	}
	else
	{
		if (bitNeg == 2)
		{
			printf("Your input number %d ", input);
			printf("outputs as "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(input));
			printf("\nThe negative value is %d", ~input + 1);
		}
		else
		{
			printf("Your input is %d", input);
		}
	}
	while (1);
	return 0;
}


Author: Richard Mahaffey

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <inttypes.h>

int binary(int num)
{
printf("This number in binary is ");
unsigned i;
for (i = 1 << (sizeof(num) * 8) - 1; i > 0; i = i / 2)
(num & i) ? printf("1") : printf("0");
printf("\n");
}


int main()
{
int num = 0;

printf("Please Input a number: ");
scanf("%u", &num);

if (num & (1 << 31))
{
printf("Number is Negative or Unsigned");

}
else
{
printf("Number is Positive");
binary(num);
num = (~num) +1;
printf("%d", num);
}

while (1);
return 0;

}
*/
