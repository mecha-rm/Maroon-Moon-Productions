#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include "Room.h"
#include <string>

class CrewMember
{
public:
	CrewMember();
	// sets the species of the crew member, as well as the room they're in. Make sure that all letters are lowercase.
	CrewMember(std::string, char);

	void setHealth(int);
	void setDamage(int);
	void setOxygen(bool);//I was thinking this could be used as like a kill switch, but if theres another way you guys want to do that I'm all ears
	void setPosition(int);//sets the room the crew member is in
	void setCrewType(std::string);

	int getHealth();
	int getDamage();
	bool getOxygen();
	std::string getSpecies();
	int getPosition();
	std::string getCrewType();
	
private:
	std::string species; // the species of the crew member
	int health;
	int damage;
	bool oxygen;
	int position;
	std::string crewType;
	// Room room = Room('A', 1, "pilot", 100); // causes error
};

#endif