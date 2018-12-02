#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include "Room.h"
#include <string>
#include <windows.h>
#include <vector>

class CrewMember
{
public:
	CrewMember();
	// sets the species of the crew member. Make sure that all letters are lowercase.
	CrewMember(std::string);

	void setHealth(int);
	void setDamage(int);
	void setOxygen(bool);//I was thinking this could be used as like a kill switch, but if theres another way you guys want to do that I'm all ears
	void setPosition(int);//sets the room the crew member is in
	void setCrewType(std::string);
	void setID(int);
	void setDestination(COORD);
	void setDestination(int x, int y);
	void setCurrent(COORD);
	void setCurrent(int x, int y);

	int getHealth();
	int getDamage();
	bool getOxygen();
	std::string getSpecies();
	int getPosition();
	std::string getCrewType();
	int getID();
	COORD getDestination();
	COORD getCurrent();
	
	std::vector<COORD> nextMove;

private:
	std::string species; // the species of the crew member
	int health;
	int damage;
	int ID;
	COORD destination; // The Room Coordinate where the crewMember is going to
	COORD current; //The room coordinate where the crewMember currently is
	
	bool oxygen;
	int position;
	std::string crewType;
	Room room = Room(1, "pilot", 100); // causes error
};

#endif