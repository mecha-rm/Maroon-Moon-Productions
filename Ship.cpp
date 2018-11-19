#include <iostream>
#include "Ship.h"


// constructors
// default constructor; the ship is named 'The Kestrel' by default
Ship::Ship() : Ship("The Kestrel") {}

// set the ship's name
Ship::Ship(std::string name) : shipName(name)
{
	// Based on Layout A of the default ship, the Kestrel Cruiser (https://ftl.fandom.com/wiki/The_Kestrel_Cruiser)
	// Layout A
	setHull(30);
	setShield(2);
	setReactor(8);

	for (int i = 0; i < crewMembers; i++) // making three human crew members
		addCrewMember("human");

	setOxygen(1);
	setShield(2);
	setEngineLevel(2);
	setFuel(16);

}

//Setters 
void Ship::setHull(int hull) { this->hull = hull; }
void Ship::setShield(int shield) { this->shield = shield; }
void Ship::setReactor(int reactor) { this->reactor = reactor; }
void Ship::setEvade(int evade) { this->evade = evade; }
void Ship::setOxygen(int oxygen) { this->oxygen = oxygen; }
//void Ship::setCrewMembers(int crewMembers) { this->crewMembers = crewMembers; }
void Ship::setScrap(int scrap) { this->scrap = scrap; }
void Ship::setFTLDrive(int ftlDrive) { this->ftlDrive = ftlDrive; }
void Ship::setFuel(int fuel) { this->fuel = fuel; }
void Ship::setShieldLevel(int shieldLevel) { this->shieldLevel = shieldLevel; }
void Ship::setEngineLevel(int engineLevel) { this->engineLevel = engineLevel; }
void Ship::setOxygenLevel(int oxygenLevel) { this->oxygenLevel = oxygenLevel; }
void Ship::setWeaponControlLevel(int weaponControlLevel) { this->weaponControlLevel = weaponControlLevel; }
void Ship::setMedbayLevel(int medbayLevel) { this->medbayLevel = medbayLevel; }
void Ship::setPilotLevel(int pilotLevel) { this->pilotLevel = pilotLevel; }
void Ship::setSensorLevel(int sensorLevel) { this->sensorLevel = sensorLevel; }
void Ship::setDoorLevel(int doorLevel) { this->doorLevel = doorLevel; }
void Ship::setRooms(int rooms) { this->rooms = rooms; }
void Ship::setCrew(std::vector<CrewMember> crew) { this->crew = crew; }
void Ship::setSensor(bool sensor) { this->sensor = sensor; }

//Getters
int Ship::getHull() { return hull; }
int Ship::getShield() { return shield; }
int Ship::getReactor() { return reactor; }
int Ship::getEvade() { return evade; }
int Ship::getOxygen() { return oxygen; }
int Ship::getCrewMembers() { return crewMembers; }
int Ship::getScrap() { return scrap; }
int Ship::getFTLDrive() { return ftlDrive; }
int Ship::getFuel() { return fuel; }
int Ship::getShieldLevel() { return shieldLevel; }
int Ship::getEngineLevel() { return engineLevel; }
int Ship::getOxygenLevel() { return oxygenLevel; }
int Ship::getWeaponControlLevel() { return weaponControlLevel; }
int Ship::getMedbayLevel() { return medbayLevel; }
int Ship::getPilotLevel() { return pilotLevel; }
int Ship::getSensorLevel() { return sensorLevel; }
int Ship::getDoorLevel() { return doorLevel; }
int Ship::getRooms() { return rooms; }
bool Ship::getSensor() { return sensor; }

std::vector<CrewMember> Ship::getCrew() { return crew; }

// adds a crew member; make sure all letters are lowercase
void Ship::addCrewMember(std::string species)
{
	if (species == "human" || species == "h")
	{
		crew.push_back(CrewMember("Human"));
	}
	else
	{
		crew.push_back(CrewMember("Human"));
	}
	
	crewMembers++;
}

// applies damage to the shield before the health of the ship
void Ship::shieldToHealth(int damage) {

	for (int count = damage; count > getShield(); count--) {

		if (getShield() > 0) {
			setShield(getShield() - 1);
		}
		else {
			setHull(getHull() - 1);
		}
	}
}

// removes a crew member at the provided index
bool Ship::removeCrewMember(unsigned int i)
{
	// returns 'false' if the index is invalid, or if there are no crew members
	if (crew.empty() == false && i < crew.size())
	{
		crew.erase(crew.begin() + i);
		return true;
	}
	else
	{
		return false;
	}
}

// gets a crew member at the provided index
CrewMember Ship::getCrewMember(unsigned int i) // returns the crew member at the provided index
{
	if (i > crew.size()) // if it would cause an out-of-bounds exception
	{
		return crew.at(i);
	}
	else
	{
		return CrewMember();
	}
}