/*
Author: Yost
Title: PL 12 Your Song
Date: 30 July 2018
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * readFile_ptr = fopen("read.txt", "r"); //whenever you fopen a file...

	char tempBuff[256] = { 0 };
	char *tempReturn = tempBuff;

	if (readFile_ptr != NULL)
	{
		while (tempReturn)
		{
			tempReturn = fgets(tempBuff, 256, readFile_ptr);
			if (tempReturn)
			{
				puts(tempBuff);
			}
		}
		fclose(readFile_ptr); //fclose it
	}
	else
	{
		puts("Error opening file.");
		return -1;
	}

	while (1);
	return 0;
}