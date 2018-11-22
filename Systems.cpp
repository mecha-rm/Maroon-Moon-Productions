#include <iostream>
#include "Systems.h"
#include "Room.h"

Room room;

//Getters
std::string Systems::getName() { return name };
std::string Systems::getType() { return type; }
bool Systems::getBuff() { return buff; }
int Systems::getMaxPower() { return maxPower; }
int Systems::getCost() { return cost; }
int Systems::getHealth() { return health; }

//Setters
void Systems::setName(std::string name) { this->name = name; }
void Systems::setType(std::string type) { this->type = type; }
void Systems::setBuff(bool bonus) { this->buff = bonus; }
void Systems::setMaxPower(int maxPower) { this->maxPower = maxPower; }
void Systems::setCost(int cost) { this->cost = cost; }
void Systems::setHealth(int health) { 
	if (this->health > 100) health = 100;//doesnt allow the health to go above 100%
	this->health = health; 
}


void Systems::repair() {

	if (room.getAmountOfCrewMembers() > 0 && getHealth() < 100) {
		setHealth(getHealth() + 25);//gains a quarter of the system's health back every turn
	}
	else if (room.getAmountOfCrewMembers() > 0 && getHealth() == 100) {
		buff = true;
	}

}
