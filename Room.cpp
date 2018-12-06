// Used for rooms on a ship.
#include <iostream>
#include "Room.h"

// constructor
// Room::Room(char ID, int amountOfCrewMemebers, std::string system, int oxygen) : ID(ID), amountOfCrewMembers(amountOfCrewMembers), system(system), oxygen(oxygen) {}
Room::Room(char ID, int shield, std::string system, int oxygen) : ID(ID), shield(shield), system(system), oxygen(oxygen) {}

//Getters
char Room::getID() { return ID; } // returns the ID letter of the room

// Unused Functions
int Room::getAmountOfCrewMembers() { return amountOfCrewMembers; } // returns the amount of crew members (unused)
std::string Room::getSystem() { return system; } // gets the room's system (unused)
int Room::getOxygen() { return oxygen; } // gets the oxygen level (unused)
int Room::getShield() { return shield; }  // gets the shielding amount (unused)

//Setters
void Room::setAmountOfCrewMemebers(int amountOfCrewMembers) { this->amountOfCrewMembers = amountOfCrewMembers; } // sets the amount of crew members in the room (unused)
void Room::setSystem(std::string system) { this->system = system; } // sets the shield over the room
void Room::setOxygen(int oxygen) { this->oxygen = oxygen; } // sets the oxygen level (unused)

// Sets the shielding amount of the room
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

// Returns the room as a string, saying its ID letter and shielding amount.
std::string Room::toString()
{
	std::string tempStr = "";
	tempStr = "ID: " + std::string(1, ID) + " | Shield: " + std::to_string(shield);
	return tempStr;
}