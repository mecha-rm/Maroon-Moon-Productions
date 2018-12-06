// The class for weapons used by the ships
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
std::string Weapon::getName() { return name; } // weapon's name
std::string Weapon::getType() { return type; } // weapon's type
int Weapon::getChargeTime() { return CHARGETIME; } // maximum amount of time it takes for a weapon to charge
int Weapon::getShots() { return shots; } // amount of shots per charge
char Weapon::getTarget() { return target; } // the target of the wepaon
int Weapon::getAccuracy() { return accuracy; } // the accuracy of the weapon
int Weapon::getHullDam() { return hullDam; } // hull damage 
int Weapon::getShieldDam() { return shieldDam; } // shield damage
int Weapon::getCrewDam() { return crewDam; } // crew damage (unused)
int Weapon::getSysDam() { return sysDam; } // system damage (unused)
int Weapon::getChanceFire() { return chanceFire; } // extra damage chance
int Weapon::getChanceBreach() { return chanceBreach; } // shield destruction chance
int Weapon::getChanceStun() { return chanceStun; } // electrical surge chance; this will cause a weapon of the opponent's to lose power.
int Weapon::getCharge() { return charge; } // the current charge of the weapon
int Weapon::getRoomHit() { return roomHit; } // the room the weapon will hit (unused)
std::string Weapon::getDamageType() { return damageType; } // the damage type of the weapon (unused)

//Setters
void Weapon::setTarget(char target) { this->target = target; } // target of the weapon
void Weapon::setAccuracy(int accuracy) { this->accuracy = accuracy; } // weapon's accuracy
void Weapon::setCharge(int charge) { this->charge = charge; } // weapon's current charge
void Weapon::setRoomHit(int roomHit) { this->roomHit = roomHit; } // room the weapon will hit (unused)
void Weapon::setDamageType(std::string damageType) { this->damageType = damageType; } // the damage type of the weapon (unused)

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

// toString() - prints stats of the ship
std::string Weapon::toString()
{
	std::string str;
	str = "Weapon - Type: " + getType() + ", Name: " + getName() + " | Success Rate: " + std::to_string(getAccuracy()) + "/10 , Charge Time: " + std::to_string(getChargeTime()) + " | ";
	str += " Hull Damage: " + std::to_string(getHullDam()) + ", Shield Damage: " + std::to_string(getShieldDam()) + " | ";
	str += "Fire Chance: " + std::to_string(getChanceFire()) + " /10, Breach Chance: " + std::to_string(getChanceBreach()) + "/10, Stun Chance: " + std::to_string(getChanceStun()) + "/10";
	
	return str;
}
