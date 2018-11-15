#include <iostream>
#include "Weapon.h"

//Setters ------------------------------------------------------------------------------------------------------------
void Weapon::setDamage(int damage) {
	damage = Weapon::damage;
	
}
void Weapon::setHealth(int health) {
	health = Weapon::health;

}
void Weapon::setCooldown(int cooldown) {
	cooldown = Weapon::cooldown;

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