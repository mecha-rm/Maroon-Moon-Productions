#include <iostream>
#include "Weapon.h"

//Setters ------------------------------------------------------------------------------------------------------------
void Weapon::setDamage(int damage) {
	this->damage = damage;
}

void Weapon::setHealth(int health) {
	this->health = health;
}

void Weapon::setCooldown(int cooldown) {
	this->cooldown = cooldown;
}

//Getters ------------------------------------------------------------------------------------------------------------
int Weapon::getDamage() {

	return damage;
}
int Weapon::getHealth() {

	return health;
}
int Weapon::getCooldown() {

	return cooldown;
}