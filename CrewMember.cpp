#include "CrewMember.h"

CrewMember::CrewMember() : CrewMember("Human") {}

// sets the species of the crew member. Make sure that all letters are lowercase.
CrewMember::CrewMember(std::string species) : species(species) {}

//Setters
void CrewMember::setHealth(int health) { this->health = health; }
void CrewMember::setDamage(int damage) { this->damage = damage; }
void CrewMember::setOxygen(bool oxygen) { this->oxygen = oxygen; }

//Getters
std::string CrewMember::getSpecies() { return species; }
int CrewMember::getHealth() { return health; }
int CrewMember::getDamage() { return damage; }
bool CrewMember::getOxygen() { return oxygen; }


