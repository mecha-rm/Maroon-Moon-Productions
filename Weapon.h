// The class for weapons used by the ships
#pragma once
#include <iostream>
#include <string>

class Weapon {
public:
	//Constructors
	//Simple
	Weapon(std::string name, std::string type, int CHARGETIME, int shots, int accuracy, int hullDam, int shieldDam); //Just includes the necessities, uses hullDam for sysDam and crewDam
	//Full
	Weapon(std::string name, std::string type, int CHARGETIME, int shots, int accuracy, int hullDam, int shieldDam, int crewDam, int sysDam, int chanceFire, int chanceBreach, int chanceStun);

	// Copy Constructor
	Weapon(Weapon*);

	//Getters; see variable list below for what each of these mean.
	std::string getName();
	std::string getType();
	int getChargeTime(); // the time a weapon takes to charge. This gets the time it takes for a weapon to charge.
	int getShots();
	char getTarget(); // the room being targeted
	int getAccuracy();
	int getHullDam();
	int getShieldDam();
	int getCrewDam(); // unused
	int getSysDam(); // unused
	int getChanceFire();
	int getChanceBreach();
	int getChanceStun();
	int getCharge();
	// int getRoomHit();
	std::string getDamageType(); // unused	
	int getRoomHit(); // unused

	//Setters; see variable list below for what each of these mean.
	void setTarget(char target);
	void setAccuracy(int);
	void setCharge(int);
	void setRoomHit(int); // unused	
	void setDamageType(std::string); // unused	
	

	// tells the weapon to start charging. The weapon stops charging once it's fully chaged. A parameter exists to tell the program by how much to charge the weapon.
	void increaseCharge(unsigned int amount = 1);
	// returns 'true' if the weapon is available for a selection. It would return false if the weapon is charging, or doesn't exist.
	bool isAvailable();
	// checks to see if the wepaon is currently charging. If not, it's selectible as a weapon.
	bool isCharging();
	// returns 'true' if the weapon has been charged, and false if it has yet to be charged.
	bool isCharged();

	std::string toString(); // prints the stats of the weapon

private:
	char target = '0'; // the target room. If 'char' is anything other than a letter, it targets the ship itself.

	//Constants
	const std::string name; // Name of weapon
	const std::string type; // Weapon type. Defines ammo as well
	const unsigned int CHARGETIME; // How long it takes to charge
	const int shots; // the amount of shots a weapon gets per change
	unsigned int accuracy; // the accurary of the weapon (out of 10)
	//Damage types
	const int hullDam; // damage to the hull
	const int shieldDam; // damage to the shield
	const int crewDam; // damage to the crew (unused)
	const int sysDam; // damage to the system (unused)
	
	// Chances of random events are out of 10
	const int chanceFire; // chance of causing extra damage
	const int chanceBreach; // chance of piercing a shield
	const int chanceStun; // chance of cutting power to a weapon
	
	// Other
	int charge = 0; // current charge
	int roomHit; // the room hit by the weapon (unused)
	std::string damageType; // the damage type of the weapon (unused)
};
