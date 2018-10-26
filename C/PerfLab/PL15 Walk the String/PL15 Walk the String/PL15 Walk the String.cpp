/*
Author: Yost
Title: Walk the String
Date: 6 August 2018
*/
	
/*	OBJECTIVES:

READ A STRING AND WRITE IT TO A ZEROIZED CHAR ARRAY.
USE ASSERT() TO VERIFY THE LAST ELEMENT OF THE CHAR ARRAY IS NUL.
STEP #1 - SAFELY WRITE TO THE ARRAY.
STEP #2 - BREAK ASSERT() BY UNSAFELY READING INPUT INTO THE CHAR ARRAY.
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
	char string[10] = { 0 };


	printf("What do you want to put into the array?\n");
	scanf("%s", &string);
	assert(string[9] == '\0'); //if you enter a string of 10 or more characters this will fail
	printf("Your string is: %s\n", string);

	/*fgets(string, 10, stdin);
	assert(string[9] == '\0');
	puts(string);*/

	while (1);
	return 0;

}