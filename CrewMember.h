#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <string>

class CrewMember
{
public:
	CrewMember();
	// sets the species of the crew member. Make sure that all letters are lowercase.
	CrewMember(std::string);

	void setHealth(int);
	void setDamage(int);
	void setOxygen(bool);//I was thinking this could be used as like a kill switch, but if theres another way you guys want to do that I'm all ears

	int getHealth();
	int getDamage();
	bool getOxygen();
	std::string getSpecies();

private:
	std::string species; // the species of the crew member
	int health;
	int damage;
	bool oxygen;

};

#endif