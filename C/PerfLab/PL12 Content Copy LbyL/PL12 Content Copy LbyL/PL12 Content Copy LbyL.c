/*
Author: Yost
Title: PL 12 Content Copy Line by Line
Date: 30 July 2018
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * readFile1_ptr = fopen("read.txt", "r"); //whenever you fopen a file...
	FILE * writeFile_ptr = fopen("write.txt", "w"); //whenever you fopen a file...

	char tempBuff1[256] = { 0 };
	char tempBuff2[256] = { 0 };
	char *tempReturn1 = tempBuff1;
	char *tempReturn2 = tempBuff2;

	if (readFile1_ptr != NULL)
	{
		while (tempReturn1)
		{
			tempReturn1 = fgets(tempBuff1, 256, readFile1_ptr);
			if (tempReturn1)
			{
				//puts(tempBuff1);
				fputs(tempBuff1, writeFile_ptr);
			}
		}
		fclose(readFile1_ptr); //fclose it
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
		while (tempReturn2)
		{
			tempReturn2 = fgets(tempBuff2, 256, readFile2_ptr);
			if (tempReturn2)
			{
			puts(tempBuff2);
			}
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