#pragma once

struct Student 
{
	char * initials;
	char * favoriteMusicalArtist;
	char * dreamCar;
	struct Student * next_node;
};

int firstMenu(void) //ask user which of three options they would like to view
{
	printf("What would you like to do?  Type your selection and press the <Enter> key.  Choose from the following:\
			\n1 - Print all students and all data.\
			\n2 - Print all students and either their initials, favorite musical artist, or dream car.\
			\n3 - Print out only one student and all of their data.\
			\n4 - Add student to database.\n\n");

	return 0;
}

int secondMenu(void) //if they choose selection 2 from first menu, send them to this menu
{
	printf("Which data point would you like to see?  Type your selection and press the <Enter> key.  Choose from the following:\
			\n1 - Initials.\
			\n2 - Favorite musical artist.\
			\n3 - Dream car.\n\n");

	return 0;
}

int thirdMenu(void) //if they choose selection 3 from first menu, send them to this menu
{
	printf("Which student's data would you like to see?  Enter a number and press the <Enter> key.\n");

	return 0;
}