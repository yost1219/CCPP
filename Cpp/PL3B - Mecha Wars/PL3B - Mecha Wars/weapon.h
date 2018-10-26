#pragma once
#include <string>
#include <iostream>

/*
This one is already built for you... feel free to add to it.
Utilize the damage in either a method (pref in mecha_sub) or main() to determine how muchh damage you do on an enemy mech
Ensure power is being subtracted by cost after every action. Prevent action if power is too low for action (this can be done via method (pref in mecha sub)  or main()
*/




class Weapon {
protected:
	std::string weaponName;
	std::string weaponType;
	int damage;					// How much damage this weapon does per use
	int cost;					// Cost to use weapon one time, subtract from current power

public:
	Weapon() {}
	std::string getName() //name of weapon
	{
		return weaponName;
	}
	std::string getType() //type of weapon (primary or sidearm)
	{
		return weaponType;
	}
	int getDamage() //damage dealt
	{
		return damage;
	}
	int getCost() //cost to fire
	{
		return cost;
	}
	//return weapon stats
	void display_weapon_stats() {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Type: " << weaponType << std::endl;
		std::cout << "Average Damage: " << damage << std::endl;
		std::cout << "Cost: " << cost << std::endl;
		std::cout << std::endl;
	}

	friend class Player;

};

class Rifle : public Weapon {
public:
	//constructor
	Rifle() {
		weaponName = "Rifle";
		weaponType = "Primary";
		damage = 200;
		cost = 10;
	}
};

class MachineGun : public Weapon {
public:
	//constructor
	MachineGun() {
		weaponName = "Machine Gun";
		weaponType = "Primary";
		damage = 190; 
		cost = 9;
	}
};

class Shotgun : public Weapon {
public:
	//constructor
	Shotgun() {
		weaponName = "Shotgun";
		weaponType = "Primary";
		damage = 170;
		cost = 8;
	}
};

class Sword : public Weapon {
public:
	//constructor
	Sword() {
		weaponName = "Sword";
		weaponType = "Sidearm";
		damage = 80;
		cost = 5;
	}
};

class Pistol : public Weapon {
public:
	//constructor
	Pistol() {
		weaponName = "Pistol";
		weaponType = "Sidearm";
		damage = 70;
		cost = 4;
	}
};

class Club : public Weapon {
public:
	//constructor
	Club() {
		weaponName = "Club";
		weaponType = "Sidearm";
		damage = 50;
		cost = 3;
	}
};


void print_rifle()
{
	std::cout << "  _________________,_____________________________________, " << std::endl;
	std::cout << " |       _____        ____________,-----------------|____| " << std::endl;
	std::cout << " |______/     / ,)---'         /  \\                        " << std::endl;
	std::cout << "             /_/              /    \\                       " << std::endl << std::endl;
}

void print_machineGun()
{
	std::cout << "  _________________,___________________, " << std::endl;
	std::cout << " |  ______   _______|||____,-----------' " << std::endl;
	std::cout << " |_/     / ,)---'   |||                  " << std::endl;
	std::cout << "        /_/        ///                   " << std::endl << std::endl;
}

void print_shotgun()
{
	std::cout << "  _________________,_____________, " << std::endl;
	std::cout << " |  ______   ________|||||||-----' " << std::endl;
	std::cout << " |_/     / ,)---'                  " << std::endl;
	std::cout << "        /_/                        " << std::endl << std::endl;
}

void print_sword()
{
	std::cout << "     _____||__________________________________ " << std::endl;
	std::cout << "   (|_|_|_||_________________________________/ " << std::endl;
	std::cout << "          ||                                   " << std::endl << std::endl;
}

void print_pistol() 
{
	std::cout << "  ,___________, " << std::endl;
	std::cout << "  |_     _____| " << std::endl;
	std::cout << "    /  ,)       " << std::endl;
	std::cout << "   /__/         " << std::endl << std::endl;
}

void print_club()
{
	std::cout << "     _____||___________________________  " << std::endl;
	std::cout << "   (|_|_|_||___________________________) " << std::endl;
	std::cout << "          ||                             " << std::endl << std::endl;
}