#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS 1

int menu(void); //runs menu function

int main(void)
{
	int menuSelection1 = 0;
	int menuSelection2 = 0;
	int menuSelection3 = 0;

	int newNum = 0;
	int createSpace = 0; //for new student entry
	char newStudentInitials = 0; //for new student entry
	char newStudentArtist = 0; //for new student entry
	char newStudentCar = 0; //for new student entry


	struct Student student8 = { "RG", "Billy Joel", "1983 DeLorean DMC-12", NULL };
	struct Student student7 = { "KY", "U2", "2018 Bugatti Chiron", &student8 };
	struct Student student6 = { "DM", "AC/DC", "1969 Chevrolet Camaro Z/28", &student7 };
	struct Student student5 = { "EP", "Metallica", "2003 Mazda 3", &student6 };
	struct Student student4 = { "RS", "The Beatles", "1969 Dodge Charger", &student5 };
	struct Student student3 = { "CY", "Megadeth", "1985 Renault Turbo 5", &student4 };
	struct Student student2 = { "WK", "Led Zepplin", "1969 Chevrolet Corvette Stingray", &student3 };
	struct Student student1 = { "ZV", "Guns N' Roses", "1962 Buick Special", &student2 };
	struct Student student0 = { "TB", "Queen", "1936 Lancia Astura Pinin Farina 'Bocca' Cabriolet", &student1 };
	
	struct Student studentArray[100] = { student0, student1, student2, student3, student4, student5, student6, student7, student8 }; //array of structs

	int numTotalStudents = sizeof(studentArray) / sizeof(studentArray[0]); //calc num of students

	do
	{
		char tempSelect1[10] = { 0 }; //stores user input from menu1
		char tempSelect2[10] = { 0 }; //stores user input from menu2
		char tempSelect3[10] = { 0 }; //stores user input from menu1
		
		
		printf("\n");
		firstMenu();

		fgets(tempSelect1, sizeof(tempSelect1), stdin); //receive and store user input
		menuSelection1 = atoi(tempSelect1);
		_flushall();

		if ((menuSelection1 < 1) || (menuSelection1 > 4))
		{
			printf("Invalid selection.  Try again.\n\n");
		}

		printf("\n");

		switch (menuSelection1)
		{
		case 1: //prints all students and all personal information

			for (int i = 0; i < numTotalStudents; i++)
			{
				if (studentArray[i].initials)
				{
					printf("Student %d\'s initials are %s, their favorite musical artist is %s, and their dream car is a %s.\n", \
						(i + 1), studentArray[i].initials, studentArray[i].favoriteMusicalArtist, studentArray[i].dreamCar);
				}
			}
			break;

		case 2: //prints all students and one piece of personal information (initials, student number, favorite band, or favorite car)

			secondMenu();

			fgets(tempSelect2, sizeof(tempSelect2), stdin); //receive and store user input
			menuSelection2 = atoi(tempSelect2);
			_flushall();

			if ((menuSelection1 < 1) || (menuSelection1 > 3))
			{
				printf("Invalid selection.  Try again.\n\n");
			}
			
			printf("\n");

			switch (menuSelection2)
			{
			case 1: //prints students' initials
				for (int i = 0; i < numTotalStudents; i++)
				{
					printf("Student %d\'s initials are %s.\n", \
						(i + 1), studentArray[i].initials);
				}
				break;

			case 2: //prints students' favorite band
				for (int i = 0; i < numTotalStudents; i++)
				{
					printf("Student %d\'s favorite musical artist is %s.\n", \
						(i + 1), studentArray[i].favoriteMusicalArtist);
				}
				break;

			case 3: //prints students' dream car
				for (int i = 0; i < numTotalStudents; i++)
				{
					printf("Student %d\'s dream car is a %s.\n", \
						(i + 1), studentArray[i].dreamCar);
				}
				break;
			}
			break;

		case 3: //prints only one student and all of their personal information

			thirdMenu();
			printf("There are currently %d students in the database.  Select a number between 1 and %d.\n\n", numTotalStudents, numTotalStudents);

			fgets(tempSelect3, sizeof(tempSelect3), stdin); //receive and store user input
			menuSelection3 = atoi(tempSelect3);
			_flushall();

			if ((menuSelection3 < 1) || (menuSelection3 > numTotalStudents))
			{
				printf("Invalid selection.  Try again.\n\n");
			}

			printf("\n");
			printf("Student %d\'s initials are %s, their favorite musical artist is %s, and their dream car is a %s.\n\n", \
				(menuSelection3), studentArray[(menuSelection3 - 1)].initials, studentArray[(menuSelection3 - 1)].favoriteMusicalArtist, studentArray[(menuSelection3 - 1)].dreamCar);
			break;

		case 4: //add new student

			struct Student *student9 = { 0 };
			char *student9 = calloc(3, sizeof(char));

			//createSpace = (struct *)malloc(sizeof(student0)); //allocates memory the size of student0 in which to store the new student's data

			//newNum = numTotalStudents + 1; //sets position to write new info to

			printf("What is the student's initials?\n");
			scanf_s("%s", &newStudentInitials);
			*student9->initials = newStudentInitials;
			

			//printf("What is the student's favorite musical artist?\n");
			//fgets(newStudentArtist, sizeof(newStudentArtist), stdin);


			//printf("What is the student's dream car?\n");
			//fgets(newStudentCar, sizeof(newStudentCar), stdin);

			break;


		}
	} 
	while (1);
	return 0;
}