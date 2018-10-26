/*
Arthur: Yost
Title: Performance Lab 7.2 D
Date: 17 July 2018

SWITCH STATEMENT

Write a program that will evaluate a simple math formula.
Input the formula with two integers separated by an arithmetic operator from one line.
Example: 1 + 1, (-8) - 3, 2 * (-7), (-15) / (-4)
Use a switch statement to print the correct value using the operators as cases.
Set the default condition to an error.
Ensure any division provides a double answer with a precision of two decimal places.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main(void)
{
	int num1 = 0; 
	int num2 = 0;
	char op1;

	printf("Input an equation with two integers (e.g. 4 + 8, -3 * 5, 2 / (-7), etc.).\nPossible operators are: +, -, *, /, %c, and ^.\n", '%');
	scanf("%d %c %d", &num1, &op1, &num2);

	switch (op1)
	{
	case '+':
		printf("%d + %d = %d", num1, num2, (num1 + num2));
		break;
	case '-':
		printf("%d - %d = %d", num1, num2, (num1 - num2));
		break;
	case '*':
		printf("%d * %d = %d", num1, num2, (num1 * num2));
		break;
	case '/':
		printf("%d / %d = %.2lf", num1, num2, (double)num1 / num2);
		break;
	case '%':
		printf("%d %c %d = %d", num1, '%', num2, ((num1) % (num2)));
		break;
	case '^':
		printf("%d ^ %d = %.0lf", num1, num2, (pow(num1, num2)));
		break;
		
	default:
		break;

	}

	while (1);
	return 0;
}

/*
///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// DEMONSTRATION LAB X.2.A-4 /////////////////////////////
/////////////////////////////////// May I see a menu? /////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
// Input an integer from the user
// Create a menu allowing the user to:
//     Print their input as Octal
//     Print their input as Decimal
//     Print their input as Hexadecimal
//     Print their input as a Character
//     Input a new number
//     Exit
///////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int printMenu(void);

int main(void)
{
	int number = 0;
	int menuSelection = 3;
	printf("Input an number:  ");
	_flushall();
	scanf("%d", &number);


	do
	{
		printMenu();
		_flushall();
		scanf("%d", &menuSelection);
		switch (menuSelection)
		{
			case 0:												//if
				printf("\n\nExiting...");
				break;
			case 1:			// 2 - Octal						//else if
				printf("Octal:  %o\n\n", number);
				break;
			case 2:			// 3 - Decimal						//else if
				printf("Decimal:  %d\n\n", number);
				break;
			case 3:			// 4 - Hexadecimal					//else if
				printf("Hexadecimal:  %X\n\n", number);
				break;
			case 4:			// 5 - Char							//else if
				printf("Character:  %c\n\n", number);
				break;
			case 5:			// 6 - New number					//else if
				printf("\n\nEnter a new number to display:  ");
				_flushall();
				scanf("%d", &number);
			
			default:											//else
				break;
		}
	} while (menuSelection != 0);

	return 0;
}

int printMenu(void)
{
	printf("How do you want to print that number?  \n");
	printf("1 - Octal \n2 - Decimal \n3 - Hexadecimal \n4 - Char \n5 - Enter a new number \n0 - Exit this program. \n\n\n");

	return 0;
}
*/