#pragma once
#include <iostream>
#include <string>

class Weapon {
public:
	//Constructors
	//Simple
	Weapon(std::string name, std::string type, int CHARGETIME, int shots, int energy, int hullDam, int shieldDam); //Just includes the necessities, uses hullDam for sysDam and crewDam
	//Full
	Weapon(std::string name, std::string type, int CHARGETIME, int shots, int energy, int hullDam, int shieldDam, int crewDam, int sysDam, int chanceFire, int chanceBreach, int chanceStun);

	// Copy Constructor
	Weapon(Weapon*);

	//Getters
	std::string getName();
	std::string getType();
	// the time a weapon takes to charge
	int getChargeTime();
	int getShots();
	int getEnergy();
	int getHullDam();
	int getShieldDam();
	int getCrewDam();
	int getSysDam();
	int getChanceFire();
	int getChanceBreach();
	int getChanceStun();
	int getCharge();
	// int getRoomHit();
	std::string getDamageType();	
	int getRoomHit();

	//Setters
	void setCharge(int);
	void setRoomHit(int);
	void setDamageType(std::string);

	// tells the weapon to start charging. The weapon stops charging once it's fully chaged. A parameter exists to tell the program by how much to charge the weapon.
	void increaseCharge(unsigned int amount = 1);
	// returns 'true' if the weapon is available for a selection. It would return false if the weapon is charging, or doesn't exist.
	bool isAvailable();
	// checks to see if the wepaon is currently charging. If not, it's selectible as a weapon.
	bool isCharging();
	// returns 'true' if the weapon has been charged, and false if it has yet to be charged.
	bool isCharged();

	std::string toString();

private:
	//Constants
	const std::string name; //Name of weapon
	const std::string type; //Weapon type. Defines ammo as well
	const unsigned int CHARGETIME; //How long it takes to charge
	const int shots; //Shots per charge
	const unsigned int energy; //Energy drain required to use weapon
	//Damage types
	const int hullDam;
	const int shieldDam;
	const int crewDam;
	const int sysDam;
	//Effects - variable is 0-10, var * 5 = % of effect happening
		//Example: chanceFire = 3; 15% chance of a fire starting
	const int chanceFire;
	const int chanceBreach;
	const int chanceStun;
	//Variables
	int charge = 0; //Current charge
	int roomHit;
	std::string damageType;
};
