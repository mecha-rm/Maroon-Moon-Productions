// Header for the 'crew member' class; this is not used in the final game. 
// Rooms were originally going to have crew members that went around fixing systems and powering up weapons. They were going to have their own stats, be of different races, and be killable.
#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include "Room.h"
#include <string>
#include <windows.h>
#include <vector>

class CrewMember
{
public:
	CrewMember(); // consturctor
	// sets the species of the crew member, as well as the room they're in. Make sure that all letters are lowercase.
	CrewMember(std::string species, char room);

	// Setters
	void setHealth(int); // sets crew mmember health
	void setDamage(int); // sets damage done by crew member
	void setOxygen(bool); // whether the crew member has oxygen or not. The group member that made this was also thinking of using it as a kill switch, but that's ultimately irrelevant now.
	void setPosition(int); // the crew member's position
	void setCrewType(std::string); // job the crew member does
	void setID(int); // unique identification of the crew member.
	void setDestination(COORD); // crew member's destination
	void setDestination(int x, int y); // crew member's destination (used to create COORD)
	void setCurrent(COORD); // crew member's location
	void setCurrent(int x, int y); // crew member's location (creates COORD with x and y)

	// Getters
	int getHealth(); // gets crew member health
	int getDamage(); // gets crew member damage
	bool getOxygen(); // Gets whether the crew member has oxygen or not.
	std::string getSpecies(); // gets the race of the crew member
	int getPosition(); // gets crew member position
	std::string getCrewType(); // gets crew member's job
	int getID(); // unique identification of the crew member.
	COORD getDestination(); // gets the destination of the crew member
	COORD getCurrent(); // gets the current location of the crew member
	
	std::vector<COORD> nextMove; // vector used for planning out the route of the crew member to the next room.

private:
	std::string species; // the species of the crew member
	int health; // the amount of health the crew member has.
	int damage; // the amount of damage the crew member does.
	int ID; // the room the crew member is in. Origianlly we were going to use numbers, but we switched to letters (chars) for room identification elsewhere.
	COORD destination; // The Room Coordinate where the crewMember is going to.
	COORD current; //The room coordinate where the crewMember currently is.

	bool oxygen; // determines whether the crew member has oxygen or not
	int position; // the position of the crew member
	std::string crewType; // crew member's job
};

#endif