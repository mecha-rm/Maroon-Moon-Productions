#include <iostream>
#include "Weapon.h"

// Creates the weapon
Weapon::Weapon(std::string name, std::string type, int damage, int ammo, int chargeTime) : name(name), type(type), damage(damage), ammo(ammo), chargeTime(chargeTime) {}

int Weapon::getDamage() {

	return damage;
}

void Weapon::setDamage(int damage) {
	this->damage = damage;
}

int Weapon::getAmmo() {

	return ammo;
}

void Weapon::setAmmo(int health) {
	this->ammo = health;
}

int Weapon::getCharge() {
	return charge;
}

void Weapon::setCharge(int charge) {
	this->charge = charge;
}

int Weapon::getChargeTime() { return chargeTime; }

