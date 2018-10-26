/*
Author: Yost
Title: PL15 Errno
Date: 6 August 2018
*/

/*
Write (or modify) a program that implements the following:

feof()
perror()
Return errno
strerror()

Replicate some error to test your implementation…

Read a non-existent file.
Write to a locked file.
Misuse a math function .
*/


#define _CRT_SECURE_NO_WARNINGS	
#include <string.h>
#include <math.h>
#include <errno.h>
#include <stdio.h>

void error_reporting(int currErrno);

int main(void)
{
	int currentErrno = 0;
	char currentChar = 0;
	char word[5] = { 0 };
	
	printf("Enter a word.\n", &word);
	scanf("%s", word);
	currentErrno = errno;

	if (!word == '\0')
	{
		error_reporting(currentErrno);
		return currentErrno;
	}

	assert(word[4] = '\0');

	/*
	//file not found error - error code 2
	FILE * weirdFile = fopen("C:\\Temp\\TR-Test-Input-File.txt", "r");
	currentErrno = errno;
	error_reporting(currentErrno);

	if (!weirdFile)
	{
		// Print an error message utilizing the string associated with the errno
		error_reporting(currentErrno);

		// Immediately utilize errno as the return value
		return currentErrno;
	}
	else
	{
		// Utilize feof() to read a file char by char until the end
		while (!feof(weirdFile))
		{
			currentChar = getc(weirdFile);	// Read a char and...
			putchar(currentChar);			// ...print a char
		}
	}
	*/
	/*
	//permission denied error - error code 13
	FILE * locked = fopen("C:\\Windows\\Notepad.exe", "w");
	currentErrno = errno;
	error_reporting(currentErrno);

	if (!locked)
	{
		error_reporting(currentErrno);
		return currentErrno;
	}
	else
	{
		while (!feof(locked))
		{
		currentChar = getc(locked);
		putchar(currentChar);
		}
	}
	*/
	/*
	//math/domain error - error code 0
	float imaginaryNumber = sqrt(-4);
	currentErrno = errno;
	error_reporting(currentErrno);
	*/

	while (1);
	return 0;
}

void error_reporting(int currErrno)
{
	char* errStr;
	if (currErrno)
	{

		perror("Error");
	}

	return;
}