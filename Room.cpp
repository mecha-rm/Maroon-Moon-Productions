#include <iostream>
#include "Room.h"
#include "CrewMember.h"

//Getters
int Room::getAmountOfCrewMembers() { return amountOfCrewMembers; }
std::string Room::getSystem() { return system; }
int Room::getOxygen() { return oxygen; }

//Setters
void Room::setAmountOfCrewMemebers(int amountOfCrewMembers) { this->amountOfCrewMembers = amountOfCrewMembers; }
void Room::setSystem(std::string system) { this->system = system; }
void Room::setOxygen(int oxygen) { this->oxygen = oxygen; }
