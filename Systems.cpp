// Used for the system that a room contains. This was unused in the final game.
#include <iostream>
#include "Systems.h"

//Getters
std::string Systems::getName() { return name; } // the name of the system
std::string Systems::getType() { return type; } // main system or subsystem
bool Systems::getBuff() { return buff; } // whether or nnot a buff is being applied
int Systems::getMaxPower() { return maxPower; } // the system's maximum power
int Systems::getCost() { return cost; } // the cost of the system
int Systems::getHealth() { return health; } // the system's heatlh

//Setters
void Systems::setName(std::string name) { this->name = name; }
void Systems::setType(std::string type) { this->type = type; }
void Systems::setBuff(bool bonus) { this->buff = bonus; }
void Systems::setMaxPower(int maxPower) { this->maxPower = maxPower; }
void Systems::setCost(int cost) { this->cost = cost; }
void Systems::setHealth(int health) { 
	if (this->health > 100) health = 100; //doesnt allow the health to go above 100%
	this->health = health; 
}

// Repairs the system
void Systems::repair() {

	if (room.getAmountOfCrewMembers() > 0 && getHealth() < 100) {
		setHealth(getHealth() + 25); // gains a quarter of the system's health back every turn
	}
	else if (room.getAmountOfCrewMembers() > 0 && getHealth() == 100) {
		buff = true;
	}

}
