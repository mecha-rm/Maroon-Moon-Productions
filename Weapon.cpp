#include <iostream>
#include "Weapon.h"

// Creates the weapon
Weapon::Weapon(std::string name, std::string type, int damage, int ammo, int chargeTime) : name(name), type(type), damage(damage), ammo(ammo), chargeTime(chargeTime) {}


//Setters
void Weapon::setDamage(int damage) { this->damage = damage; }
void Weapon::setAmmo(int ammo) { this->ammo = ammo; }
void Weapon::setCharge(int charge) { this->charge = charge; }

//Getters
int Weapon::getDamage() { return damage; }
int Weapon::getAmmo() {	return ammo; }
int Weapon::getCharge() { return charge; }
int Weapon::getChargeTime() { return chargeTime; }

