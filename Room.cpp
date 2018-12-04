#include <iostream>
#include "Room.h"

// constructor
// Room::Room(char ID, int amountOfCrewMemebers, std::string system, int oxygen) : ID(ID), amountOfCrewMembers(amountOfCrewMembers), system(system), oxygen(oxygen) {}
Room::Room(char ID, int shield, std::string system, int oxygen) : ID(ID), shield(shield), system(system), oxygen(oxygen) {}

//Getters

char Room::getID() { return ID; }
// Returns the amount of people in the room.
int Room::getAmountOfCrewMembers() 
{ 
	return amountOfCrewMembers;
	// return crew.size(); 
}


std::string Room::getSystem() { return system; }
int Room::getOxygen() { return oxygen; }
int Room::getShield() { return shield; }

//Setters
void Room::setAmountOfCrewMemebers(int amountOfCrewMembers) { this->amountOfCrewMembers = amountOfCrewMembers; }
void Room::setSystem(std::string system) { this->system = system; } // sets the shield over the room
void Room::setOxygen(int oxygen) { this->oxygen = oxygen; }
void Room::setShield(int shield) 
{ 
	if (shield < this->shield) // making the shield equal to 'zero' if it would be brought below zero.
	{
		this->shield = 0;
	}
	else
	{
		this->shield = shield;
	}
}

// Returns the room as a string.
std::string Room::toString()
{
	std::string tempStr = "";
	tempStr = "ID: " + std::string(1, ID) + " | Shield: " + std::to_string(shield);
	return tempStr;
}

/*
// adds a crew member pointer
void Room::addCrewMember(CrewMember * member) { crew.push_back(member); }

// removes a crew member at the given index
void Room::removeCrewMember(unsigned int index)
{
	// If the index is out of range, a 'false' is returned
	if (index >= crew.size())
	{
		return;
	}

	crew.erase(crew.begin() + index);
}
*/