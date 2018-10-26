#pragma once
#include <string>
#include <iostream>
// TODO: You will need to inherit your mecha from the class Mecha first... be sure to override the functions if you need to.



// Base Classes
class Mecha {
protected:
	std::string mechaName;
	std::string variant;
	std::string type;
	int hitPoints;				// indicates total health remaining
	int power;					// indicates power per turn... this value should never be modified after it's set. action points

public:
	// Default constructor... subclass should handle construction
	Mecha() {}
	// You will want to either override this function to add weapon and specific stats... or just utilize it as is and create a new method inside your sub mecha
	/*
	Mecha(std::string name, std::string vt, std::string tp, int hp, int pwr) {
		mechaName = name;
		variant = vt;
		type = tp;
		hitPoints = hp;
		power = pwr;
	}
	*/

	virtual void display_main_stats() {
		std::cout << "Model: " << mechaName << std::endl;
		std::cout << "Variant: " << variant << std::endl;
		std::cout << "Type: " << type << std::endl;
		std::cout << "Hit Points: " << hitPoints << std::endl;
		std::cout << "Power: " << power << std::endl;
		std::cout << std::endl;
	}

	/*
	Use this method if you want to determine how much damage your mecha takes
	This can be either really simple (just amount of damage enemy mech does to you...
	Or you can go in on this and do damage types and such.
	*/
	virtual int computeDamageReceived(int damagePts) {
		//set mecha hp to temp variable
		//subtract damage taken from temp variable
		//put temp variable back into mecha hp (change hp)
		
		//int hp = Mecha.hitPoints - damagePts;

		return 0;
	}
	// Bare minimum... use this to see if your mech is dead yet
	virtual int getHP() {
		return hitPoints;
	}
	virtual int getPower() {
		return power;
	}


	friend class Player;
};