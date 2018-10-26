/*
Author: Yost
Title: DemoLab 10-6 A
Date: 24 July 2018

PREPROCESSOR DIRECTIVES

Write a simple C program that utilizes a header file
Write a definition file for the header file
Utilize the following preprocessor directives:
#include
#define
(#) Operator
(##)
#undef

*/

#include <stdio.h>
#include "Header.h"
#define BOOST 17
#define BOOST2(x) {puts(#x " is boosted!\n");}
#define DBLBOOST(a, b) a##b
#define DBLBOOST2(a, b) DBLBOOST(a, b)
#define BUFFSIZE 255
#define STR1 "boost"
#define STR2 "ing"

int main(void)
{
	printf("BOOST level is %d\n", BOOST);
	printf("NITRO level is %d\n", NITRO);

#undef NITRO;


	char string[BUFFSIZE] = DBLBOOST2(STR1, STR2);

	#define NITRO(x) x*18

	printf("NITRO(2) is %d\n", NITRO(2));
	BOOST2(2);
	printf ("DBLBOOST is %s\n", string);

	while (1);
	return 0;
}