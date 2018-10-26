/*
Author: Yost
Title: PL 12 Content Copy Char by Char
Date: 30 July 2018
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * readFile_ptr = fopen("read.txt", "r"); //whenever you fopen a file...
	FILE * writeFile_ptr = fopen("write.txt", "w"); //whenever you fopen a file...

	char readFromFile1 = 0;
	char readFromFile2 = 0;

	if (readFile_ptr != NULL)
	{
		while (readFromFile1 != EOF)
		{
			readFromFile1 = getc(readFile_ptr);
			putc(readFromFile1, writeFile_ptr);
		}
		fclose(readFile_ptr); //fclose it
		fclose(writeFile_ptr); //fclose it
	}
	else
	{
		puts("Error opening file.");
		return -1;
	}
	
	FILE * readFile2_ptr = fopen("write.txt", "r"); //whenever you fopen a file...

	if (readFile2_ptr != NULL)
	{
		while (readFromFile2 != EOF)
		{
			readFromFile2 = getc(readFile_ptr);
			putc(readFromFile2, stdout);
		}
		fclose(readFile2_ptr); //fclose it
	}
	else
	{
		puts("Error opening file.");
		return -1;
	}
	while (1);
	return 0;
}
