/*
C Content Review
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define get(x) #x

int main(void)
{
// Chapter 2 - variables
	
	/* Lab A - initialize variables and get sizeof

	int integer = 7;
	float floatingNumber = 3.784321;
	double doubleFloat = 0.947823746897352;
	char character = 'S';

	printf("My int has a value of %d and a size of %d.\n", integer, sizeof(integer));
	printf("My float has a value of %f and a size of %d.\n", floatingNumber, sizeof(floatingNumber));
	printf("My double has a value of %.15f and a size of %d.\n", doubleFloat, sizeof(doubleFloat));
	printf("My char has a value of %c and a size of %d.\n", character, sizeof(character));
	*/
	/* Lab B - casting variables as other variable types

	int integer = 73;
	float floatingNumber = 3.784321;
	double doubleFloat = 0.947823746897352;
	char character = 'S';

	printf("My int cast as a float is %f.\n", (float)integer);
	printf("My int cast as a char is %c.\n", (char)integer);
	printf("My float cast as a double is %.15f.\n", (double)floatingNumber);
	printf("My double cast as a float is %f.\n", (float)doubleFloat);
	printf("My char cast as an int is %d.\n", (int)character);
	printf("33 cast as a char is %c.\n", (char)33);
	*/

//Chapter 3 - array strings

	/* Lab A - initialize and print integer array

	int ageArray[10] = { 0 };
	ageArray[0] = 28;
	ageArray[1] = 28;
	ageArray[2] = 29;
	ageArray[3] = 30;
	ageArray[4] = 32;
	ageArray[5] = 34;
	ageArray[6] = 21;
	ageArray[7] = 27;
	ageArray[8] = 32;
	ageArray[9] = 28;

	printf("The ages are: %d, %d, %d, %d, %d, %d, %d, %d, %d, and %d.\n", ageArray[0], ageArray[1], \
		ageArray[2], ageArray[3], ageArray[4], ageArray[5], ageArray[6], ageArray[7], ageArray[8], ageArray[9]);

	char quoteArray[256] = { "She'd \nprobably \nlove \nto \nhonky \ntonk." };

	printf("%s\n", quoteArray);
	*/
	/* Lab B - initialize and print character array (not a string)

	char phraseArray[256] = { 0 };

	phraseArray[0] = 'B';
	phraseArray[1] = 'r';
	phraseArray[2] = 'i';
	phraseArray[3] = 'l';
	phraseArray[4] = 'l';
	phraseArray[5] = 'i';
	phraseArray[6] = 'a';
	phraseArray[7] = 'n';
	phraseArray[8] = 't';
	phraseArray[9] = '!';
	phraseArray[10] = '\0';

	printf("%s\n", phraseArray);
	printf("The phrase length is %d.\n", sizeof(phraseArray));
	*/

// Chapter 4 - print/scan

	/* Lab A - getchar and putchar

	char input = 0;

	printf("Put in a character to transform.\n");
	input = getchar();

	putchar(input + 1);
	*/
	/* Lab B - getc and putc

	char input = 0;

	printf("Put in a character to transform.\n");
	input = getc(stdin);

	putc(input - 1, stdout);
	*/
	/* Lab C - string i/o - fgets and fputs

	char inputString[10] = { 0 };

	printf("Input a string.\n");
	fgets(inputString, 10, stdin);
	fputs(inputString, stdout);
	*/
	/* Lab D - scanf

	char firstName[32] = { 0 };
	char middleName[32] = { 0 };
	char lastName[32] = { 0 };
	int integer1 = 0;
	int integer2 = 0;

	printf("Type in the first, middle, and last name separated by tabs.\n");
	scanf("%s %s %s", &firstName, &middleName, &lastName);
	printf("The name is: \n\t%s \n\t%s \n\t%s\n", firstName, middleName, lastName);

	printf("Enter two integers, separated by an asterisk (e.g. 7*5).\n");
	scanf("%d\*%d", &integer1, &integer2);
	printf("%d times %d equals %d.\n", integer1, integer2, (integer1 * integer2));
	*/

// Chapter 5

	/* Lab A - operators and expressions

	float side1 = 0;
	float side2 = 0;
	float hypotenuse = 0;

	printf("Input the two known sides of the right triangle separated by a space (e.g. 4.5 7.221).  I will calculate the hypotenuse.\n");
	scanf("%f %f", &side1, &side2);

	if ((side1 <= 0) || (side2 <= 0))
	{
		printf("You cannot enter zero or a negative number.");
	}
	else
	{
		hypotenuse = sqrt((side1 * side1) + (side2 * side2));
		printf("The hypotenuse is %f.\n", hypotenuse);
	}
	*/
	
// Chapter 6

	/* Lab A

	uint32_t userInput = 0;
	uint32_t control = 0x01;
	int bitShift = 0;

	printf("Input a number between 0 and 255 for conversion.\n");
	fscanf(stdin, "%d", &userInput);
	printf("How many bits would you like to shift?\n");
	fscanf(stdin, "%d", &bitShift);
	printf("Your number shifted left %d bits is %d.\n", bitShift, userInput << bitShift);
	printf(get(Your number shifted right %d bits is %d.\n), bitShift, userInput >> bitShift);
	
	//int bit8 = userInput / 128;
	//int bit7 = (userInput % 128) / 64;
	//int bit6 = (userInput % 64) / 32;
	//int bit5 = (userInput % 32) / 16;
	//int bit4 = (userInput % 16) / 8;
	//int bit3 = (userInput % 8) / 4;
	//int bit2 = (userInput % 4) / 2;
	//int bit1 = userInput % 2;

	bool bit8 = userInput & 0x80;
	bool bit7 = userInput & 0x40;
	bool bit6 = userInput & 0x20;
	bool bit5 = userInput & 0x10;
	bool bit4 = userInput & 0x08;
	bool bit3 = userInput & 0x04;
	bool bit2 = userInput & 0x02;
	bool bit1 = userInput & 0x01;

	printf("Your number represented in binary is %d%d%d%d%d%d%d%d\n", bit8, bit7, bit6, bit5, bit4, bit3, bit2, bit1);
	*/
	// Capstone

	unsigned int unsignedInt = 7;
	int flipBit = 0;
	int inputMask = 0;


	printf("Which bit would you like to flip?");
	scanf("%d", &flipBit);
	





	while (1);
	return 0;
}


/*  Calculates run time of program
#include <time.h>

clock_t start, end;
double cpu_time_used;

start = clock();
...//Do the work. main function, etc
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
*/

/* alternate print function
#define get(x) #x
int main()
{
	printf(get(icecream)); //prints "icecream" onto the screen
	printf(get(Your number is %d.\n), 7); //prints "Your number is 7." followed by a line break
	return 0;
}
*/

/* how to count without loops
void printNos (unsigned int n)
{
	if (n > 0)
	{
		printNos (n - 1);
		printf ("%d", n);
	}
	return;
}
int main ()
{
	printNos (100);
	getchar();
	return 0;
}
*/