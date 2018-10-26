#pragma once
#include "weapon.h"


// WARNING
/*
There is an example subclass included... delete it if you want to try it without reference
Please note, this is a bare bones subclass. It only includes enough to get you started
*/



//Mecha(std::string name, std::string vt, std::string tp, int hp, int pwr)

//Mecha("Wolf", "Mk. I", "Small", 1200, 25);
class Wolf : public Mecha {
private:
	Weapon primaryWeapon;
	Weapon sidearmWeapon;
public:
	//default constructor
	Wolf() { 
		mechaName = "Wolf";
		variant = "Mk. I";
		type = "Small";
		hitPoints = 800;
		power = 26;
	}
	/*
	//constructor
	Wolf(std::string name, std::string var, int hp = 1200, int pwr = 25) {
		mechaName = name;
		variant = var;
		type = "Small";
		hitPoints = hp;
		power = pwr;
	}
	
	// Below sets weapons, take weapon object
	void set_primary_weapon(Weapon wp) {
		primaryWeapon = wp;
	}
	void set_sidearm_weapon(Weapon wp) {
		sidearmWeapon = wp;
	}

	bool setHP(int hp) {
		// NEXT units can only have 2000 health
		if (hp <= 2000) {
			hitPoints = hp;
			return true;
		}
		return false;
	}
	*/
	virtual void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		std::cout << "Primary Weapon:" << std::endl;
		primaryWeapon.display_weapon_stats();
		std::cout << "Sidearm:" << std::endl;
		sidearmWeapon.display_weapon_stats();
		std::cout << "\n\n";
	}
};


//Mecha("Tiger", "Mk. I", "Medium", 1500, 22);
class Tiger : public Mecha {
private:
	Weapon primaryWeapon;
	Weapon sidearmWeapon;
public:
	//default constructor
	Tiger() {
		mechaName = "Tiger";
		variant = "Mk. I";
		type = "Medium";
		hitPoints = 1000;
		power = 21;
	}
	/*
	//constructor
	Tiger(std::string name, std::string var, int hp = 1500, int pwr = 22) {
		mechaName = name;
		variant = var;
		type = "Medium";
		hitPoints = hp;
		power = pwr;
	}
	*/
	// Below sets weapons, take weapon object
	void set_primary_weapon(Weapon wp) {
		primaryWeapon = wp;
	}
	void set_sidearm_weapon(Weapon wp) {
		sidearmWeapon = wp;
	}

	bool setHP(int hp) {
		// NEXT units can only have 2000 health
		if (hp <= 2000) {
			hitPoints = hp;
			return true;
		}
		return false;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		std::cout << "Primary Weapon:" << std::endl;
		primaryWeapon.display_weapon_stats();
		std::cout << "Sidearm:" << std::endl;
		sidearmWeapon.display_weapon_stats();
		std::cout << "\n\n";
	}
};


//Mecha("Bear", "Mk. I", "Heavy", 2000, 16);
class Bear : public Mecha {
private:
	Weapon primaryWeapon;
	Weapon sidearmWeapon;
public:
	//default constructor
	Bear() {
		mechaName = "Bear";
		variant = "Mk. I";
		type = "Heavy";
		hitPoints = 1300;
		power = 16;
	}
	/*
	//constructor
	Bear(std::string name, std::string var, int hp = 2000, int pwr = 16) {
		mechaName = name;
		variant = var;
		type = "Heavy";
		hitPoints = hp;
		power = pwr;
	}
	*/
	// Below sets weapons, take weapon object
	void set_primary_weapon(Weapon wp) {
		primaryWeapon = wp;
	}
	void set_sidearm_weapon(Weapon wp) {
		sidearmWeapon = wp;
	}

	bool setHP(int hp) {
		// NEXT units can only have 2000 health
		if (hp <= 2000) {
			hitPoints = hp;
			return true;
		}
		return false;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		std::cout << "Primary Weapon:" << std::endl;
		primaryWeapon.display_weapon_stats();
		std::cout << "Sidearm:" << std::endl;
		sidearmWeapon.display_weapon_stats();
		std::cout << "\n\n";
	}
};

void print_wolf()
{
	std::cout << " |\\---/|  " << std::endl;
	std::cout << " | . . |  " << std::endl;
	std::cout << "  \\   /   " << std::endl;
	std::cout << "   \\_/    " << std::endl << std::endl;
}

void print_tiger()
{
	std::cout << " /'-----'\\  " << std::endl;
	std::cout << "|  .   .  |  " << std::endl;
	std::cout << " \\_ ___ _/   " << std::endl;
	std::cout << "   ',_,'    " << std::endl << std::endl;
}

void print_bear()
{
	std::cout << " /'-----'\\  " << std::endl;
	std::cout << "|  .   .  |  " << std::endl;
	std::cout << "|   |_|   |  " << std::endl;
	std::cout << " \\__'_'__/    " << std::endl << std::endl;
}