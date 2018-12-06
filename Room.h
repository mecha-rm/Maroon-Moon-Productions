// Used for rooms on a ship.
#pragma once
#include "CrewMember.h"
#include <string>
#include <vector>

class Room {
public:
	Room(char ID, int shield, std::string system, int oxygen); // constructor
	
	// Gets the ID letter of the room. This is used to discern rooms from one another.
	char getID();
	// Gets the amount of crew members in the room; goes unused.
	int getAmountOfCrewMembers();
	// Gets the system in the room; goes unused.
	std::string getSystem();
	// Room's oxygen level (unused)
	int getOxygen();
	// Room's current shield amount.
	int getShield();

	// Sets the amount of crew members in the room; goes unused.
	void setAmountOfCrewMemebers(int);
	// Sets the system in the room (unused).
	void setSystem(std::string);
	// Sets the oxygen level (unused).
	void setOxygen(int);
	// Sets the sheilding amount of the room.
	void setShield(int);
	
	// toString() function
	std::string toString();

private:
	char ID; // the ID letter of the room
	int shield = 0; // the shield covering this room
	int amountOfCrewMembers = 0; // the amount of crew members in this room (unused)
	std::string system; // the system in this room (unused)
	int oxygen; // the room's oxygen level (unused)
};