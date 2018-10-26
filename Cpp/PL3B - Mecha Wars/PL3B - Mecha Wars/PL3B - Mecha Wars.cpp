#include "mecha.h"
#include "mecha_subs.h"
#include "player.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>


int userInput(int input);
void print_win();
int main() {
	// whose turn is it?
	bool turn = 1; //used to toggle between player 1 (true) and player 2 (false) in several places in the game
	// attack toggle
	bool attack = 0;
	// is there a winner?
	bool winner = 0; //just used to see if the game is over or not
	// pointers for mechas for players 1 and 2
	Mecha *mechaPtr1 = NULL;
	Mecha *mechaPtr2 = NULL;
	// pointers for primary weapon and sidearm
	Weapon *primaryPtr1 = NULL;
	Weapon *sidearmPtr1 = NULL;
	Weapon *primaryPtr2 = NULL;
	Weapon *sidearmPtr2 = NULL;
	// Mecha initialization
	Wolf wolf;
	Tiger tiger;
	Bear bear;
	// Weapon initialization
	Rifle rifle;
	MachineGun machineGun;
	Shotgun shotgun;
	Sword sword;
	Pistol pistol;
	Club club;

	// Player initialization
	Player1 player1;
	Player2 player2;

	//initialize some variables for later
	int player1hp = 0;
	int player1power = 0;
	int player1maxPower = 0;
	int player1priDmg = 0;
	int player1priCst = 0;
	int player1sideDmg = 0;
	int player1sideCst = 0;
	int player2hp = 0;
	int player2power = 0;
	int player2maxPower = 0;
	int player2priDmg = 0;
	int player2priCst = 0;
	int player2sideDmg = 0;
	int player2sideCst = 0;
	int damage = 0;
	

	// Now we can do our main logic
	// This is where our game gets programmed
	// Have fun here 
	// Don't get stuck on requirments... just do it!

	//this is a 1v1 game where you start by selecting your mecha and take turns attacking your opponent utilizing your power (like action points)
	//game modes will be pvp mode for now, maybe arcade later, maybe survival mode
	//each mecha can equip 2 weapons

	//options menu

	int menuChoice = 0;
	std::cout << "Would you like to view mecha and weapon statistics or play the game?" << std::endl;
	std::cout << "Type your selection and press <Enter>." << std::endl;
	std::cout << "1 for Statistics.  2 for Game." << std::endl;
	do //do this....
	{
		menuChoice = userInput(menuChoice);
		if (!(menuChoice > 0 && menuChoice < 3)) //if selection is not 1 or 2
		{
			std::cout << "Invalid selection.  Try again." << std::endl;
		}
	} while (!(menuChoice > 0 && menuChoice < 3)); //....as long as the selection is invalid, otherwise resume
	switch (menuChoice)
	{
	case 1:
	{
		
		//print stats for mechas
		std::cout << "        ___   __                  __  " << std::endl;
		std::cout << "|\\  /| |     /  \\  |   |    /\\   /  \\ " << std::endl;
		std::cout << "| \\/ | |--  |      |---|   /__\\  `--. " << std::endl;
		std::cout << "|    | |___  \\__/  |   |  /    \\ \\__/ " << std::endl << std::endl;
		wolf.display_main_stats();
		print_wolf();
		tiger.display_main_stats();
		print_tiger();
		bear.display_main_stats();
		print_bear();
		//print stats for weapons
		std::cout << "        ___           __     __            __ " << std::endl;
		std::cout << "|    | |       /\\    |  \\   /  \\   |\\  |  /  \\ " << std::endl;
		std::cout << "| /\\ | |--    /__\\   |__/  |    |  | \\ |  `--. " << std::endl;
		std::cout << "|/  \\| |___  /    \\  |      \\__/   |  \\|  \\__/ " << std::endl << std::endl;
		rifle.display_weapon_stats();
		print_rifle();
		machineGun.display_weapon_stats();
		print_machineGun();
		shotgun.display_weapon_stats();
		print_shotgun();
		sword.display_weapon_stats();
		print_sword();
		pistol.display_weapon_stats();
		print_pistol();
		club.display_weapon_stats();
		print_club();
		
	}
	case 2:
	{
		//play the game
		std::cout << "Let's play!" << std::endl << std::endl;
		//then run the below stuff in here
		for (int i = 1; i < 3; i++) //start with 1, then do 2, then be done
		{
			//Player registry: enter pilot's name
			std::string userName;
			std::cout << "Welcome, Player " << i << ".  What is your name?  (Enter first name only.)" << std::endl;
			std::getline(std::cin, userName);
			if (turn)
			{
				player1.set_name(userName); //assign input to player1.name
			}
			else
			{
				player2.set_name(userName);
			}

			//pick your mecha
			int mechaChoice = 0;
			std::cout << "Select your Mecha.  Type your selection and press <Enter>." << std::endl;
			std::cout << "1 for Wolf.  2 for Tiger.  3 for Bear." << std::endl;
			do //do this...
			{
				mechaChoice = userInput(mechaChoice);
				if (!(mechaChoice > 0 && mechaChoice < 4))
				{
					std::cout << "Invalid selection.  Try again." << std::endl;
				}
			} while (!(mechaChoice > 0 && mechaChoice < 4)); //if selection is not 1, 2, or 3
			switch (mechaChoice)
			{
			case 1: //wolf is chosen
			{
				print_wolf();
				if (turn) //if it is player1's turn (turn is true) then they selected wolf
				{
					mechaPtr1 = (Wolf *)&wolf;
					player1.set_mecha("Wolf");
					player1hp = wolf.getHP();
					player1maxPower = wolf.getPower();
					player1power = player1maxPower;

				}
				else //if it is player2's turn (turn is false) then they selected wolf
				{
					mechaPtr2 = (Wolf *)&wolf;
					player2.set_mecha("Wolf");
					player2hp = wolf.getHP();
					player2maxPower = wolf.getPower();
					player2power = player2maxPower;
				}
			}
			break;
			case 2: //tiger is chosen
			{
				print_tiger();
				if (turn)
				{
					mechaPtr1 = (Tiger *)&tiger;
					player1.set_mecha("Tiger");
					player1hp = tiger.getHP();
					player1maxPower = tiger.getPower();
					player1power = player1maxPower;
				}
				else
				{
					mechaPtr2 = (Tiger *)&tiger;
					player2.set_mecha("Tiger");
					player2hp = tiger.getHP();
					player2maxPower = tiger.getPower();
					player2power = player2maxPower;
				}
			}
			break;
			case 3: //bear is chosen
			{
				print_bear();
				if (turn)
				{
					mechaPtr1 = (Bear *)&bear;
					player1.set_mecha("Bear");
					player1hp = bear.getHP();
					player1maxPower = bear.getPower();
					player1power = player1maxPower;
				}
				else
				{
					mechaPtr2 = (Bear *)&bear;
					player2.set_mecha("Bear");
					player2hp = bear.getHP();
					player2maxPower = bear.getPower();
					player2power = player2maxPower;
				}
			}
			break;
			}

			//pick your primary weapon
			int weaponChoice = 0;
			std::cout << "Select your primary weapon.  Type your selection and press <Enter>." << std::endl;
			std::cout << "1 for Rifle.  2 for Machine Gun.  3 for Shotgun." << std::endl;
			do //do this...
			{
				weaponChoice = userInput(weaponChoice);
				if (!(weaponChoice > 0 && weaponChoice < 4))
				{
					std::cout << "Invalid selection.  Try again." << std::endl;
				}
			} while (!(weaponChoice > 0 && weaponChoice < 4)); //if selection is not 1, 2, or 3
			switch (weaponChoice)
			{
			case 1: //rifle is chosen
			{
				print_rifle();
				if (turn)
				{
					primaryPtr1 = (Rifle *)&rifle;
					player1.set_primary("Rifle");
					player1priDmg = rifle.getDamage();
					player1priCst = rifle.getCost();
				}
				else
				{
					primaryPtr2 = (Rifle *)&rifle;
					player2.set_primary("Rifle");
					player2priDmg = rifle.getDamage();
					player2priCst = rifle.getCost();
				}
			}
			break;
			case 2: //machine gun is chosen
			{
				print_machineGun();
				if (turn)
				{
					primaryPtr1 = (MachineGun *)&machineGun;
					player1.set_primary("Machine Gun");
					player1priDmg = machineGun.getDamage();
					player1priCst = machineGun.getCost();
				}
				else
				{
					primaryPtr2 = (MachineGun *)&machineGun;
					player2.set_primary("Machine Gun");
					player2priDmg = machineGun.getDamage();
					player2priCst = machineGun.getCost();
				}
			}
			break;
			case 3: //shotgun is chosen
			{
				print_shotgun();
				if (turn)
				{
					primaryPtr1 = (Shotgun *)&shotgun;
					player1.set_primary("Shotgun");
					player1priDmg = shotgun.getDamage();
					player1priCst = shotgun.getCost();
				}
				else
				{
					primaryPtr2 = (Shotgun *)&shotgun;
					player2.set_primary("Shotgun");
					player2priDmg = shotgun.getDamage();
					player2priCst = shotgun.getCost();
				}
			}
			break;
			}

			//pick your sidearm
			int sidearmChoice = 0;
			std::cout << "Select your sidearm.  Type your selection and press <Enter>." << std::endl;
			std::cout << "1 for Sword.  2 for Pistol.  3 for Club." << std::endl;
			do //do this...
			{

				sidearmChoice = userInput(sidearmChoice);
				if (!(sidearmChoice > 0 && sidearmChoice < 4))
				{
					std::cout << "Invalid selection.  Try again." << std::endl;
				}
			} while (!(sidearmChoice > 0 && sidearmChoice < 4)); //if selection is not 1, 2, or 3
			switch (sidearmChoice)
			{
			case 1: //sword is chosen
			{
				print_sword();
				if (turn)
				{
					sidearmPtr1 = (Sword *)&sword;
					player1.set_sidearm("Sword");
					player1sideDmg = sword.getDamage();
					player1sideCst = sword.getCost();
					turn = 0; //changes the turn (player1 picks, then player2 picks, then back to player1 for battle start)
				}
				else
				{
					sidearmPtr2 = (Sword *)&sword;
					player2.set_sidearm("Sword");
					player2sideDmg = sword.getDamage();
					player2sideCst = sword.getCost();
				}
			}
			break;
			case 2: //pistol is chosen
			{
				print_pistol();
				if (turn)
				{
					sidearmPtr1 = (Pistol *)&pistol;
					player1.set_sidearm("Pistol");
					player1sideDmg = pistol.getDamage();
					player1sideCst = pistol.getCost();
					turn = 0;
				}
				else
				{
					sidearmPtr2 = (Pistol *)&pistol;
					player2.set_sidearm("Pistol");
					player2sideDmg = pistol.getDamage();
					player2sideCst = pistol.getCost();
				}
			}
			break;
			case 3: //club is chosen
			{
				print_club();
				if (turn)
				{
					primaryPtr1 = (Club *)&club;
					player1.set_sidearm("club");
					player1sideDmg = club.getDamage();
					player1sideCst = club.getCost();
					turn = 0;
				}
				else
				{
					primaryPtr2 = (Club *)&club;
					player2.set_sidearm("Club");
					player2sideDmg = club.getDamage();
					player2sideCst = club.getCost();
				}
			}
			break;
			}
		}
		//battle starts, player1's turn

		turn = 1; //make sure it's player1's turn to start the match

		while (!winner) //as long as there hasn't been a winner (default), keep fighting
		{
			//list remaining hit points and power, list target hit points
			if (turn) //player1's turn
			{
				attack = 0; //no attack happened yet
				std::cout << std::endl << "Get ready, " << player1.get_name() << ".  It's your turn." << std::endl;
				std::cout << "Your current HP: " << player1hp << std::endl;
				std::cout << "Your current Power: " << player1power << std::endl;
				std::cout << "Enemy's current HP: " << player2hp << std::endl;
				//do you want to attack or recharge power?
				int moveChoice = 0;
				std::cout << "What action do you want to take?  Type your selection and press <Enter>." << std::endl;
				std::cout << "1 for Attack with Primary Weapon.  2 for Attack with Sidearm.  3 for Recharge Power." << std::endl;
				do //do this...
				{
					moveChoice = userInput(moveChoice);
					if (!(moveChoice > 0 && moveChoice < 4))
					{
						std::cout << "Invalid selection.  Try again." << std::endl;
					}
				} while (!(moveChoice > 0 && moveChoice < 4)); //if selection is not 1, 2, or 3
				switch (moveChoice)
				{
				case 1: //attack with primary weapon
				{
					//do they have enough power?
					if (player1power - player1priCst >= 0) //yes
					{
						damage = ((rand() % 20 + 91)*player1priDmg) / 100; //can deal anywhere between 90% and 110% damage
						std::cout << std::endl << "Firing " << player1.get_primary() << ".\n" << damage << " damage dealt to enemy." << std::endl;
						player2hp = player2hp - damage;
						player1power = player1power - player1priCst;
						attack = 1; //attack happened
					}
					else
					{
						std::cout << std::endl << "WARNING!  You do not have enough power for that action.  Fire your other weapon or Recharge." << std::endl;
					}
				}
				break;
				case 2: //attack with sidearm
				{
					//do they have enough power?
					if (player1power - player1sideCst >= 0) //yes
					{
						damage = ((rand() % 20 + 91)*player1sideDmg) / 100;
						std::cout << std::endl << "Firing " << player1.get_sidearm() << ".\n" << damage << " damage dealt to enemy." << std::endl;
						player2hp = player2hp - damage;
						player1power = player1power - player1sideCst;
						attack = 1;
					}
					else
					{
						std::cout << std::endl << "WARNING!  You do not have enough power for that action.  Fire your other weapon or Recharge." << std::endl;
					}
				}
				break;
				case 3: //recharge
				{
					//recharge power to max
					std::cout << std::endl << "Recharging your power to maximum." << std::endl;
					player1power = player1maxPower;
					attack = 1;
				}
				break;
				}
				//check for winner
				if (player2hp <= 0) //is player2 dead?
				{
					std::cout << std::endl << "Congratulations, " << player1.get_name() << ".  " << player2.get_name() << "\'s " << player2.get_mecha() << " has been destroyed." << std::endl;
					print_win();
					winner = 1;
					break;
				}
				else //player2 is not dead so they get to take a turn
				{
					if (attack)
					{
						turn = 0;
					}
				}
			}
			if (!turn) //player2's turn
			{
				attack = 0;
				std::cout << std::endl << "Get ready, " << player2.get_name() << ".  It's your turn." << std::endl;
				std::cout << "Your current HP: " << player2hp << std::endl;
				std::cout << "Your current Power: " << player2power << std::endl;
				std::cout << "Enemy's current HP: " << player1hp << std::endl;
				//do you want to attack or recharge power?
				int moveChoice = 0;
				std::cout << "What action do you want to take?  Type your selection and press <Enter>." << std::endl;
				std::cout << "1 for Attack with Primary Weapon.  2 for Attack with Sidearm.  3 for Recharge Power." << std::endl;
				do //do this...
				{
					moveChoice = userInput(moveChoice);
					if (!(moveChoice > 0 && moveChoice < 4))
					{
						std::cout << "Invalid selection.  Try again." << std::endl;
					}
				} while (!(moveChoice > 0 && moveChoice < 4)); //if selection is not 1, 2, or 3
				switch (moveChoice)
				{
				case 1: //attack with primary weapon
				{
					//do they have enough power?
					if (player2power - player2priCst >= 0) //yes
					{
						damage = ((rand() % 20 + 91)*player2priDmg) / 100;
						std::cout << std::endl << "Firing " << player2.get_primary() << ".\n" << damage << " damage dealt to enemy." << std::endl;
						player1hp = player1hp - damage;
						player2power = player2power - player2priCst;
						attack = 1;
					}
					else
					{
						std::cout << std::endl << "WARNING!  You do not have enough power for that action.  Fire your other weapon or Recharge." << std::endl;
					}
				}
				break;
				case 2: //attack with sidearm
				{
					//do they have enough power?
					if (player2power - player2sideCst >= 0) //yes
					{
						damage = ((rand() % 20 + 91)*player2sideDmg) / 100;
						std::cout << std::endl << "Firing " << player2.get_sidearm() << ".\n" << damage << " damage dealt to enemy." << std::endl;
						player1hp = player1hp - damage;
						player2power = player2power - player2sideCst;1
						attack = 1;
					}
					else
					{
						std::cout << std::endl << "WARNING!  You do not have enough power for that action.  Fire your other weapon or Recharge." << std::endl;
					}
				}
				break;
				case 3: //recharge
				{
					//recharge power to max
					std::cout << std::endl << "Recharging your power to maximum." << std::endl;
					player2power = player2maxPower;
					attack = 1;
				}
				break;
				}
				//check for winner
				if (player1hp <= 0) //is player1 dead?
				{
					std::cout << std::endl << "Congratulations, " << player2.get_name() << ".  " << player1.get_name() << "\'s " << player1.get_mecha() << " has been destroyed." << std::endl << std::endl;
					print_win();
					winner = 1;
					break;
				}
				else //player1 is not dead so they get to take a turn
				{
					if (attack)
					{
						turn = 1;
					}
				}
			}
		} //game over

	}
	break;
	}




	getchar();
	getchar();

	return 0;

}






void print_win()
{
	std::cout << " \\\\    // ||  //-\\\\ TTTTTT  //-\\\\  TTTT\\\\ \\\\  // || " << std::endl;
	std::cout << "  \\\\  //  || ||       ||   ||   || ||  //  \\\\//  || " << std::endl;
	std::cout << "   \\\\//   || ||       ||   ||   || ||==     ||   || " << std::endl;
	std::cout << "    \\/    ||  \\\\-//   ||    \\\\-//  ||  \\\\   ||   ,, " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "                                                                      " << std::endl;




}








int userInput(int input)
{
	std::string userString;
	while (1)
	{
		std::getline(std::cin, userString);
		std::stringstream myStream(userString);
		if (myStream >> input)
		{
			break;
		}
		std::cout << "Invalid selection.  Try again." << std::endl;
	}
	return input;
}