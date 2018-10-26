/*
Author: Yost
Title: Demo Lab 10-7 A
Date: 24 July 2018

CONDITIONAL COMPILATION
Write a simple C program that utilizes conditional compilation

*/

#define WEEKDAY //defines day of week
#ifdef WEEKDAY
#define DAY(a) printf("I wish it was the weekend instead of %s.\n", a)
#endif
#ifdef WEEKEND
#define DAY(a) printf("Thank goodness today is %s.\nThe weekend is great.\n", a)
#endif

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	char dayOfWeek[10] = { 0 };
	printf("What day of the week is it?");
	scanf("%s", &dayOfWeek);

	printf(DAY(dayOfWeek));

	while (1);
	return 0;
}