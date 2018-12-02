#include "CrewMember.h"

CrewMember::CrewMember() : CrewMember("Human") {}

// sets the species of the crew member. Make sure that all letters are lowercase.
CrewMember::CrewMember(std::string species) : species(species) {}

//Setters
void CrewMember::setHealth(int health) { this->health = health; }
void CrewMember::setDamage(int damage) { this->damage = damage; }
void CrewMember::setOxygen(bool oxygen) { this->oxygen = oxygen; }
void CrewMember::setPosition(int position) { this->position = position; }
void CrewMember::setCrewType(std::string crewType) { this->crewType = crewType; }
void CrewMember::setID(int ID) { this->ID = ID; }
void CrewMember::setDestination(COORD destination) { this->destination = destination; }
void CrewMember::setDestination(int x, int y) { destination.X = x; destination.Y = y; }
void CrewMember::setCurrent(COORD current) { this->current = current; }
void CrewMember::setCurrent(int x, int y) { current.X = x, current.Y = y; }

//Getters
std::string CrewMember::getSpecies() { return species; }
int CrewMember::getHealth() { return health; }
int CrewMember::getDamage() { return damage; }
bool CrewMember::getOxygen() { return oxygen; }
int CrewMember::getPosition() { return position; }
std::string CrewMember::getCrewType() { return crewType; }
int CrewMember::getID() { return ID; }
COORD CrewMember::getDestination() { return destination; }
COORD CrewMember::getCurrent() { return current; }



