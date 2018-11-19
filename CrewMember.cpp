#include "CrewMember.h"

CrewMember::CrewMember() : CrewMember("Human") {}

// sets the species of the crew member. Make sure that all letters are lowercase.
CrewMember::CrewMember(std::string species)
{	
	if (species == "human" || species == "h")
	{
		this->species = "human";
	}
	else
	{
		this->species = "human";
	}
}

// gets the species of the crew member
std::string CrewMember::getSpecies() { return species; }