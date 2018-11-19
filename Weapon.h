#pragma once
#include <iostream>
#include <string>
using namespace std;

class Weapon {
public:
	// sets the weapon parameters
	Weapon(std::string, std::string, int, int, int);

	int getDamage();
	int getAmmo();
	int getCharge();
	int getChargeTime();
	std::string getDamageType();	
	int getRoomHit();

	void setDamage(int);
	void setAmmo(int);
	void setCharge(int);
	void setDamageType(std::string);
	void setRoomHit(int);

private:
	const std::string type;
	const std::string name;
	std::string damageType;

	// the amount of damage a weapon does
	int damage = 1;
	// the amount of ammunition a weapon has
	int ammo = -1;
	// the amount of charge the weapon currently has
	int charge = 0;
	const unsigned int chargeTime = 0; // the amount of time the weapon takes to charge
	int room;
};