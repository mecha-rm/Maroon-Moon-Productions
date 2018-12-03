#include <iostream>
#include "Weapon.h"

//Constructors
Weapon::Weapon(std::string name, std::string type, int CHARGETIME, int shots, int accuracy, int hullDam, int shieldDam) :
	name(name), type(type), CHARGETIME(CHARGETIME), shots(shots), accuracy(accuracy), hullDam(hullDam), shieldDam(shieldDam), crewDam(hullDam), sysDam(hullDam), chanceFire(0), chanceBreach(0), chanceStun(0) {
	charge = 0;
}
Weapon::Weapon(std::string name, std::string type, int CHARGETIME, int shots, int accuracy, int hullDam, int shieldDam, int crewDam, int sysDam, int chanceFire, int chanceBreach, int chanceStun) :
	name(name), type(type), CHARGETIME(CHARGETIME), shots(shots), accuracy(accuracy), hullDam(hullDam), shieldDam(shieldDam), crewDam(crewDam), sysDam(sysDam), chanceFire(chanceFire), chanceBreach(chanceBreach), chanceStun(chanceStun) {
	charge = 0;
}

Weapon::Weapon(Weapon * weapon) : Weapon(weapon->name, weapon->type, weapon->CHARGETIME, weapon->shots, weapon->accuracy, weapon->hullDam, weapon->shieldDam, weapon->crewDam, weapon->sysDam, weapon->chanceFire, weapon->chanceBreach, weapon->chanceStun) {}

//Getters
std::string Weapon::getName() { return name; }
std::string Weapon::getType() { return type; }
int Weapon::getChargeTime() { return CHARGETIME; }
int Weapon::getShots() { return shots; }
char Weapon::getTarget() { return target; }
int Weapon::getAccuracy() { return accuracy; }
int Weapon::getHullDam() { return hullDam; }
int Weapon::getShieldDam() { return shieldDam; }
int Weapon::getCrewDam() { return crewDam; }
int Weapon::getSysDam() { return sysDam; }
int Weapon::getChanceFire() { return chanceFire; }
int Weapon::getChanceBreach() { return chanceBreach; }
int Weapon::getChanceStun() { return chanceStun; }
int Weapon::getCharge() { return charge; }
int Weapon::getRoomHit() { return roomHit; }
std::string Weapon::getDamageType() { return damageType; }

//Setters
void Weapon::setTarget(char target) { this->target = target; }
void Weapon::setAccuracy(int accuracy) { this->accuracy = accuracy; }
void Weapon::setCharge(int charge) { this->charge = charge; }
void Weapon::setRoomHit(int roomHit) { this->roomHit = roomHit; }
void Weapon::setDamageType(std::string damageType) { this->damageType = damageType; }

// charges the weapon by the provided amount; '1' by default
void Weapon::increaseCharge(unsigned int amount)
{
	charge += amount;
	// If the 'charge' is greater than the CHARGETIME, the 'charge' is set to the charge time
	if (charge > CHARGETIME)
		charge = CHARGETIME;
}

// checks to see if anything's happening with this weapon
bool Weapon::isAvailable() { return charge == 0; }

// checks to see if the weapon is charging.
bool Weapon::isCharging() { return (charge != 0 && charge < CHARGETIME); }

// returns 'true' if the weapon is charged, false otherwise.
bool Weapon::isCharged() { return (charge >= CHARGETIME); }

// toString()
std::string Weapon::toString()
{
	std::string str;
	str = "Weapon - Type: " + getType() + ", " + getName() + " | Accuray: " + std::to_string(getAccuracy()) + "/10 , Charge Time: " + std::to_string(getChargeTime()) + ", Current Charge: " + std::to_string(charge) + " | ";
	str += " Hull Damage: " + std::to_string(getHullDam()) + " , Shield Damage: " + std::to_string(getShieldDam()) + " , " + std::to_string(getSysDam());
	
	return str;
}
