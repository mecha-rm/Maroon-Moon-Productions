#include "CrewMember.h"

CrewMember::CrewMember() : CrewMember("Human") {}

// sets the species of the crew member. Make sure that all letters are lowercase.
CrewMember::CrewMember(std::string species) : species(species)
{	
}

// gets the species of the crew member
std::string CrewMember::getSpecies() { return species; }