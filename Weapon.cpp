#include <iostream>
#include "Weapon.h"

//Constructors
Weapon::Weapon(std::string name, std::string type, int chargeTime, int shots, int energy, int hullDam, int shieldDam) :
	name(name), type(type), chargeTime(chargeTime), shots(shots), energy(energy), hullDam(hullDam), shieldDam(shieldDam), crewDam(hullDam), sysDam(hullDam), chanceFire(0), chanceBreach(0), chanceStun(0) {
	charge = 0;
}
Weapon::Weapon(std::string name, std::string type, int chargeTime, int shots, int energy, int hullDam, int shieldDam, int crewDam, int sysDam, int chanceFire, int chanceBreach, int chanceStun) : 
	name(name), type(type), chargeTime(chargeTime), shots(shots), energy(energy), hullDam(hullDam), shieldDam(shieldDam), crewDam(crewDam), sysDam(sysDam), chanceFire(chanceFire), chanceBreach(chanceBreach), chanceStun(chanceStun) {
	charge = 0;
}

//Getters
std::string Weapon::getName() { return name; }
std::string Weapon::getType() { return type; }
int Weapon::getChargeTime() { return chargeTime; }
int Weapon::getShots() { return shots; }
int Weapon::getEnergy() { return energy; }
int Weapon::getHullDam() { return hullDam; }
int Weapon::getShieldDam() { return shieldDam; }
int Weapon::getCrewDam() { return crewDam; }
int Weapon::getSysDam() { return sysDam; }
int Weapon::getChanceFire() { return chanceFire; }
int Weapon::getChanceBreach() { return chanceBreach; }
int Weapon::getChanceStun() { return chanceStun; }
int Weapon::getCharge() { return charge; }

//Setters
void Weapon::setCharge(int charge) { this->charge = charge; }