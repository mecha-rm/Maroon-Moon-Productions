#include <iostream>
#include "Room.h"

// constructor
// Room::Room(char ID, int amountOfCrewMemebers, std::string system, int oxygen) : ID(ID), amountOfCrewMembers(amountOfCrewMembers), system(system), oxygen(oxygen) {}
Room::Room(char ID, int amountOfCrewMemebers, std::string system, int oxygen) : ID(ID), system(system), oxygen(oxygen) {}

//Getters
// Returns the amount of people in the room.
int Room::getAmountOfCrewMembers() 
{ 
	return amountOfCrewMembers;
	// return crew.size(); 
}

std::string Room::getSystem() { return system; }
int Room::getOxygen() { return oxygen; }

//Setters
// void Room::setAmountOfCrewMemebers(int amountOfCrewMembers) { this->amountOfCrewMembers = amountOfCrewMembers; }
void Room::setSystem(std::string system) { this->system = system; }
void Room::setOxygen(int oxygen) { this->oxygen = oxygen; }

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