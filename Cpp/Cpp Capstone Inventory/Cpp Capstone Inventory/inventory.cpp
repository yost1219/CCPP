#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "classes.h"
#include "player.h"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int, int); //go to coord position

//pointers
Item *weaponPtr = NULL;
Item *armorPtr = NULL;
Item *item1Ptr = NULL;
Item *item2Ptr = NULL;
Item *item3Ptr = NULL;
Item *item4Ptr = NULL;

//player initialization
Player player;

//item initialization
Stick stick;
Sword sword;
Probe probe;
Halberd halberd;
Scimitar scimitar;
FaceDestroyer face_destroyer;
Bucket bucket;
CanLid can_lid;
Helmet helmet;
ChainMail chain_mail;
PlateMail plate_mail;
Mythril mythril;
Apple apple;
Banana banana;
RedPotion red_potion;
MedKit med_kit;

void print_inventory();

void main() //void inventory();
{
	int inventory_menu_item = 0;
	int y = 13;
	bool inventory_menu = true;
	int currentHP = player.getHP();
	int maxHP = player.getMaxHP();
	
	//for test
	weaponPtr = (Sword *)&sword;
	armorPtr = (Bucket *)&bucket;
	item1Ptr = (Apple *)&apple;
	item2Ptr = (Banana *)&banana;
	item3Ptr = (Apple *)&apple;
	item4Ptr = (Banana *)&banana;

	print_inventory();

	gotoXY(35, 13); std::cout << "->";

	//start menu
	do
	{
		//if not null
		if (armorPtr != NULL)
		{
			gotoXY(53, 11); std::cout << armorPtr->getName(); gotoXY(68, 11); std::cout << "Armor +" << armorPtr->getStat();
		}
		else
		{
			gotoXY(53, 11); std::cout << "Empty                      ";
		}
		//if not null
		if (item1Ptr != NULL)
		{
			gotoXY(50, 13); std::cout << item1Ptr->getName() << "      "; gotoXY(68, 13); std::cout << "Heal +" << item1Ptr->getStat();
		}
		else
		{
			gotoXY(50, 13); std::cout << "Empty                      ";
		}
		//if not null
		if (item2Ptr != NULL)
		{
			gotoXY(50, 15); std::cout << item2Ptr->getName() << "      "; gotoXY(68, 15); std::cout << "Heal +" << item2Ptr->getStat();
		}
		else
		{
			gotoXY(50, 15); std::cout << "Empty                      ";
		}
		//if not null
		if (item3Ptr != NULL)
		{
			gotoXY(50, 17); std::cout << item3Ptr->getName() << "      "; gotoXY(68, 17); std::cout << "Heal +" << item3Ptr->getStat();
		}
		else
		{
			gotoXY(50, 17); std::cout << "Empty                      ";
		}
		//if not null
		if (item4Ptr != NULL)
		{
			gotoXY(50, 19); std::cout << item4Ptr->getName() << "      "; gotoXY(68, 19); std::cout << "Heal +" << item4Ptr->getStat();
		}
		else
		{
			gotoXY(50, 19); std::cout << "Empty                      ";
		}

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && y != 21) //down button pressed but only if not at bottom
		{
			gotoXY(35, y); std::cout << "  ";
			y = y + 2;
			gotoXY(35, y); std::cout << "->";
			inventory_menu_item++;
			continue;
		}
		if (GetAsyncKeyState(VK_UP) && y != 13) //up button pressed but only if not at top
		{
			gotoXY(35, y); std::cout << "  ";
			y = y - 2;
			gotoXY(35, y); std::cout << "->";
			inventory_menu_item--;
			continue;
		}
		if (GetAsyncKeyState(VK_RETURN)) //enter key pressed
		{
			switch (inventory_menu_item)
			{
			case 0: //item1
			{
				if (item1Ptr != NULL) //if there is an item
				{
					//add HP
					currentHP = currentHP + item1Ptr->getStat();
					if (currentHP > maxHP)
					{
						gotoXY(37, 23); std::cout << "Healed for " << item1Ptr->getStat() + maxHP - currentHP << " points.               ";
						currentHP = maxHP;
						player.setHP(currentHP);
					}
					else
					{
						gotoXY(37, 23); std::cout << "Healed for " << item1Ptr->getStat() << " points.                    ";
						player.setHP(currentHP);
					}
					//remove item and shift other items
					item1Ptr = item2Ptr;
					item2Ptr = item3Ptr;
					item3Ptr = item4Ptr;
					item4Ptr = NULL;
				}
				else
				{
					gotoXY(37, 23); std::cout << "No item in slot 1.                           ";
				}
				break;
			}
			case 1: //item2
			{
				if (item2Ptr != NULL) //if there is an item
				{
					//add HP
					currentHP = currentHP + item2Ptr->getStat();
					if (currentHP > maxHP)
					{
						gotoXY(37, 23); std::cout << "Healed for " << item2Ptr->getStat() + maxHP - currentHP << " points.                    ";
						currentHP = maxHP;
						player.setHP(currentHP);
					}
					else
					{
						gotoXY(37, 23); std::cout << "Healed for " << item2Ptr->getStat() << " points.                    ";
						player.setHP(currentHP);
					}
					//remove item and shift other items
					item2Ptr = item3Ptr;
					item3Ptr = item4Ptr;
					item4Ptr = NULL;
				}
				else
				{
					gotoXY(37, 23); std::cout << "No item in slot 2.                        ";
				}
				break;
			}
			case 2: //item3
			{
				if (item3Ptr != NULL) //if there is an item
				{
					//add HP
					currentHP = currentHP + item3Ptr->getStat();
					if (currentHP > maxHP)
					{
						gotoXY(37, 23); std::cout << "Healed for " << item3Ptr->getStat() + maxHP - currentHP << " points.                  ";
						currentHP = maxHP;
						player.setHP(currentHP);
					}
					else
					{
						gotoXY(37, 23); std::cout << "Healed for " << item3Ptr->getStat() << " points.                 ";
						player.setHP(currentHP);
					}
					//remove item and shift other items
					item3Ptr = item4Ptr;
					item4Ptr = NULL;
				}
				else
				{
					gotoXY(37, 23); std::cout << "No item in slot 3.                          ";
				}
				break;
			}
			case 3: //item4
			{
				if (item4Ptr != NULL) //if there is an item
				{
					//add HP
					currentHP = currentHP + item4Ptr->getStat();
					if (currentHP > maxHP)
					{
						gotoXY(37, 23); std::cout << "Healed for " << item4Ptr->getStat() + maxHP - currentHP << " points.              ";
						currentHP = maxHP;
						player.setHP(currentHP);
					}
					else
					{
						gotoXY(37, 23); std::cout << "Healed for " << item4Ptr->getStat() << " points.                 ";
						player.setHP(currentHP);
					}
					//remove item and shift other items
					item4Ptr = NULL;
				}
				else
				{
					gotoXY(37, 23); std::cout << "No item in slot 4.                     ";
				}
				break;
			}
			case 4: //exit
			{
				gotoXY(37, 23); std::cout << "Exiting inventory.          ";
				inventory_menu = false;
				getchar();
				return;
			}
			} //close switch
		} //close if
	} while (inventory_menu);
	inventory_menu_item = 0;
	y = 16;

	while (1);
	return;
} 

void print_inventory()
{
	gotoXY(0, 5);
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "|||                           |         ____                    __                      |                           |||" << std::endl;
	std::cout << "|||   |||   |||   |||   |||   |        /  _ / __ _  _______ ___/ /____  ______ __       |   |||   |||   |||   |||   |||" << std::endl;
	std::cout << "|||      |||   |||   |||      |       _/ /_ / _ \\ |/ / -_) _ \\/ __/ _ \\/ __/ // /       |      |||   |||   |||      |||" << std::endl;
	std::cout << "|||   |||   |||   |||   |||   |      /___ /__//_/___/\\__/_//_/\\__/\\___/_/  \\_, /        |   |||   |||   |||   |||   |||" << std::endl;
	std::cout << "|||      |||   |||   |||      |                                          |__/ /         |      |||   |||   |||      |||" << std::endl;
	std::cout << "|||   |||   |||   |||   |||   |      Equipped Armor:                                    |   |||   |||   |||   |||   |||" << std::endl;
	std::cout << "|||---------------------------|                                                         |---------------------------|||" << std::endl;
	std::cout << "|||---------------------------|      Item Slot 1:                                       |---------------------------|||" << std::endl;
	std::cout << "|||---------------------------|                                                         |---------------------------|||" << std::endl;
	std::cout << "|||---------------------------|      Item Slot 2:                                       |---------------------------|||" << std::endl;
	std::cout << "|||---------------------------|                                                         |---------------------------|||" << std::endl;
	std::cout << "|||---------------------------|      Item Slot 3:                                       |---------------------------|||" << std::endl;
	std::cout << "|||   |||   |||   |||   |||   |                                                         |   |||   |||   |||   |||   |||" << std::endl;
	std::cout << "|||      |||   |||   |||      |      Item Slot 4:                                       |      |||   |||   |||      |||" << std::endl;
	std::cout << "|||   |||   |||   |||   |||   |                                                         |   |||   |||   |||   |||   |||" << std::endl;
	std::cout << "|||      |||   |||   |||      |      Exit                                               |      |||   |||   |||      |||" << std::endl;
	std::cout << "|||   |||   |||   |||   |||   |                                                         |   |||   |||   |||   |||   |||" << std::endl;
	std::cout << "|||                           |                                                         |                           |||" << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}


