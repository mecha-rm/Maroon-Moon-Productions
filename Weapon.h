#pragma once
#include <iostream>
#include <string>

class Weapon {
public:
	//Constructors
	//Simple
	Weapon(std::string name, std::string type, int chargeTime, int shots, int energy, int hullDam, int shieldDam); //Just includes the necessities, uses hullDam for sysDam and crewDam
	//Full
	Weapon(std::string name, std::string type, int chargeTime, int shots, int energy, int hullDam, int shieldDam, int crewDam, int sysDam, int chanceFire, int chanceBreach, int chanceStun);

	//Getters
	std::string getName();
	std::string getType();
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
	int getRoomHit();
	std::string getDamageType();	

	void setDamageType(std::string);
	void setRoomHit(int);
	//Setters
	void setCharge(int charge);

private:
	std::string damageType;
	//Constants
	const std::string name; //Name of weapon
	const std::string type; //Weapon type. Defines ammo as well
	const unsigned int chargeTime; //How long it takes to charge
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
	int room;
};