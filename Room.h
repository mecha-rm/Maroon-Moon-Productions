#pragma once
#include "CrewMember.h"
#include <string>
#include <vector>

class Room {
public:
	Room(char ID, int amountOfCrewMemebers, std::string system, int oxygen);
	int getAmountOfCrewMembers();
	std::string getSystem();
	int getOxygen();

	// void setAmountOfCrewMemebers(int);
	void setSystem(std::string);
	void setOxygen(int);
	// void addCrewMember(CrewMember * member); // adds a crew member to the room
	// void removeCrewMember(unsigned int index); // removes a crew member from the room

private:
	char ID; // the ID letter of the room
	int amountOfCrewMembers = 0; // the amount of cew members in this room
	std::string system; // the system in this room
	int oxygen; // the room's oxygen level.

	// Doesn't work for some reason.
	// std::vector<CrewMember*> crew; // the amount of people in the room.

	// shield health
	// int room = 100; // room health
};