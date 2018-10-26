// MyStringHeader.c
#include <stdio.h>
#include <ctype.h>

#define ERR_NULL_POINTER -1;        // string is null
#define ERR_INVALID_LENGTH -2;      // string length is zero or less

extern int print_the_count(char * inputString, int strLen)
{
	char tempChar = 0;      // Current char being acted on
	int table[26] = { 0 };    // Alpha
	int count = 0;

	if (!inputString)
	{
		return ERR_NULL_POINTER;
	}
	else if (!strLen)
	{
		return ERR_INVALID_LENGTH;
	}

	for (int i = 0; i < strLen; i++)
	{
		if (inputString[i] >= 65 && inputString[i] <= 122)
		{
			tempChar = inputString[i];
			tempChar = toupper(tempChar);
			table[tempChar - 65] += 1;
			count++;
		}
	}

	// Print the table
	for (int i = 0; i < sizeof(table) / sizeof(table[0]); i++)
	{
		printf("%c: %d\n", i + 65, table[i]);
	}
	return count;
}

extern reverse_it(char * forwardString, int strLen)
{
	char tempChar;

	if (!forwardString)
	{
		return ERR_NULL_POINTER;
	}
	else if (!strLen)
	{
		ERR_INVALID_LENGTH;
	}

	for (int i = 0; i < strLen; i++)
	{
		tempChar = forwardString[i];
		forwardString[i] = forwardString[strLen - 1];
		forwardString[strLen - 1] = tempChar;
		strLen--;
	}
	return 0;
}