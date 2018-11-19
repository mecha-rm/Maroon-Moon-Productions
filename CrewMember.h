#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <string>

class CrewMember
{
public:
	CrewMember();
	// sets the species of the crew member. Make sure that all letters are lowercase.
	CrewMember(std::string);

	std::string getSpecies();

private:
	std::string species; // the species of the crew member
};

#endif