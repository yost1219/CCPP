#pragma once
#include <stdio.h>
#include <stdlib.h>

int diceRoll() //works correctly
{
	time_t t;
	/* Intializes random number generator */
	srand((unsigned)time(&t));
	int roll = (rand() % 6) + 1;

	return roll;
}

int menu(void) //ask user which of the options they would like to view
{
	printf();

	return 0;

	/*
	pairs with this:
	
	int menuSelection = 0;
	char tempSelect[10] = {0};
	menu();
	fgets(tempSelect, sizeof(tempSelect), stdin); //receive and store user input
	menuSelection = atoi(tempSelect);
	_flushall();
	*/
}

int classMenu(void)
{
	printf("Choose your class!\nType one of the following choices and press the <Enter> key.\
			\n1 - Warrior\
			\n2 - Thief\
			\n3 - Mage\
}

struct Class
{
	int * power;
	int * toughness;
	int * hitPoints;
};