#pragma once



class Player {
protected:
	std::string pilotName;
	std::string mechaName;
	std::string primaryWeapon;
	std::string sidearmWeapon;
	class Mecha;
	class Weapon;


public:
	void display_player_stats() {
		std::cout << "Pilot: " << pilotName << std::endl;
		std::cout << "Mecha: " << mechaName << std::endl;
		std::cout << "Primary Weapon: " << primaryWeapon << std::endl;
		std::cout << "Sidearm: " << sidearmWeapon << std::endl;
	}
	void set_name(std::string name)
	{
		pilotName = name;
	}
	std::string get_name()
	{
		return pilotName;
	}
	void set_mecha(std::string mecha)
	{
		mechaName = mecha;
	}
	std::string get_mecha()
	{
		return mechaName;
	}
	void set_primary(std::string primary)
	{
		primaryWeapon = primary;
	}
	std::string get_primary()
	{
		return primaryWeapon;
	}
	void set_sidearm(std::string sidearm)
	{
		sidearmWeapon = sidearm;
	}
	std::string get_sidearm()
	{
		return sidearmWeapon;
	}
	std::string name()
	{
		return pilotName;
	}
	std::string mecha()
	{
		return mechaName;
	}
	std::string primary()
	{
		return primaryWeapon;
	}
	std::string sidearm()
	{
		return sidearmWeapon;
	}

};

class Player1 : public Player {
public:
	//default constructor
	Player1() {}
	//constructor
	Player1(std::string name, std::string mecha, std::string primary, std::string sidearm) {
		pilotName = name;
		mechaName = mecha;
		primaryWeapon = primary;
		sidearmWeapon = sidearm;
	}
};

class Player2 : public Player {
public:
	//default constructor
	Player2() {}
	//constructor
	Player2(std::string name, std::string mecha, std::string primary, std::string sidearm) {
		pilotName = name;
		mechaName = mecha;
		primaryWeapon = primary;
		sidearmWeapon = sidearm;
	}
};