/*
Author:  Yost
Title:  PL12 Username
Date: 31 July 2018
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE *roster_ptr = fopen("classRoster.txt", "a"); //whenever you fopen a file...

	int students = 0;

	char readFromFile = 0;


	int iter1 = 0; //students
	int iter2 = 0; //first name
	int iter3 = 0; //middle name
	int iter4 = 0; //last name
	int iter5 = 0; //username

	//prompt user for number of students
	printf("How many students are you entering?");
	scanf("%d", &students);

	if (roster_ptr != NULL)
	{
		for (iter1 = 0; iter1 < students; iter1++) //run a loop to collect data for each student one at a time
		{
			iter5 = 0; //resets username iterator from previous student
			char firstName[32] = { 0 };
			char middleName[32] = { 0 };
			char lastName[32] = { 0 };
			char username[32] = { 0 };

			//read first, middle, and last name of each student (collecting three character strings as input)
			printf("Enter the student's first, middle, and last names and press <Enter> between each entry.\
			\nIf no middle name, type NONE in place.\nIf two middle names, remove spaces (e.g. JohnPaul).\
			\nIf student has two last names, or a hyphenated last name, remove spaces (e.g. CarterWilliamson).\
			\nNOTE: Only capitalize the FIRST letter of each word to avoid username generation errors.\n");
			scanf("%s%s%s", &firstName, &middleName, &lastName);

			if (middleName[0] == 'N' && middleName[1] == 'O' && middleName[2] == 'N' && middleName[3] == 'E')
			{
				middleName[32] = 32;
			}

			//remove any newline characters from all strings (replace/remove all '\n' characters)

			//append each name to a "class roster" file in the following format:  
				//For George Herbert Dubya Bush, write the following to the the file...George H. Dubya Bush has a username of ghdbush.
				//(search the first and middle names for capital letters and write them in order to a new string
				//then write the last name in lowercase letters at the end of the string to get username

			for (iter2 = 0; iter2 < 32; iter2++) //check first name
			{
				if ((firstName[iter2] > 64) && (firstName[iter2] < 91)) //check first name for capital letters and write lowercase to username
				{
					username[iter5] = (firstName[iter2] + 32);
					iter5++;
				}
			}
			for (iter3 = 0; iter3 < 32; iter3++) //check middle name
			{
				if (middleName[0] == 'N' && middleName[1] == 'O' && middleName[2] == 'N' && middleName[3] == 'E')
				{
					middleName[32] = 32;
				}
				else if ((middleName[iter3] > 64) && (middleName[iter3] < 91)) //check middle name for capital letters and write lowercase to username
				{
					username[iter5] = (middleName[iter3] + 32);
					iter5++;
				}
			}
			for (iter4 = 0; iter4 < 32; iter4++) //check last name
			{
				if ((lastName[iter4] > 64) && (lastName[iter4] < 91)) //if letter is uppercase then flip it and write to username
				{
					username[iter5] = (lastName[iter4] + 32);
					iter5++;
				}
				else if ((lastName[iter4] > 96) && (lastName[iter4] < 123))
				{
					username[iter5] = lastName[iter4];
					iter5++;
				}
			}
			printf("The username for %s %s %s is: %s\n", firstName, middleName, lastName, username);
			fputs("The username for ", roster_ptr);
			fputs(firstName, roster_ptr);
			fputs(" ", roster_ptr);
			fputs(middleName, roster_ptr);
			fputs(" ", roster_ptr);
			fputs(lastName, roster_ptr);
			fputs(" is ", roster_ptr);
			fputs(username, roster_ptr);
			fputs("\n", roster_ptr);

		}
		fclose(roster_ptr); //fclose it
	}
	else
	{
		printf("Error opening file.");
	}
	while (1);
	return 0;
}
