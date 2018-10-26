/*
Author: Yost
Title: Perf Lab 10-6 A
Date: 24 July 2018


PERFORMANCE LAB A 10.6
PREPROCESSOR DIRECTIVES 10.6
Write a C program with preprocessor directives to:

Combine two string literals
Wrap those string literals in quotes
Define a constant buffer size of 64

Define an array:

Of standard buffer size
Assign the wrapped string literals to the array

Print the array
*/

#define COMBINESTRING(a, b) a##b //double hash the two strings
#define COMBINEFORREAL(a, b) COMBINESTRING(a, b) //toss the strings into the double hash macro
#define BUFFSIZE 64 //set the buffer size
#define STR1 "super" //first string
#define STR2 "man" //second string

#include <stdio.h>

int main(void)
{
	char stringArray[BUFFSIZE] = COMBINEFORREAL(STR1, STR2);

	printf("%s\n", stringArray);

	while (1);
	return 0;
}