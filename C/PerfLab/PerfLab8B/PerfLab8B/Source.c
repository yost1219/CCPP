#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "MyStringHeader.h"

int main()
{
	char reverseString[] = { 't','e','s','t' };
	char someString[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd' }; // Non null term
	int someStringLen = 11;

	int counter = print_the_count(someString, someStringLen);

	//char reverseString[] = reverse_it(someString, someStringLen);

	printf("\n\n\n\nTotal count: %d\n", counter);
	printf("%s", reverseString);

	while (1);
	return 0;
}