#include <iostream>
#include "Ship.h"

// constructors
// default constructor; the ship is named 'The Kestrel' by default
Ship::Ship() : Ship("The Kestrel") {}

// set the ship's name
Ship::Ship(std::string name) : shipName(name)
{
	// Layout A
}

//Setters -------------------------------------------------------------------------------------------------------------------------------------------
void Ship::setHull(int hull) {
	this->hull = hull;
}

void Ship::setShield(int shield) {
	this->shield = shield;
}

void Ship::setEvade(int evade) {
	this->evade = evade;

}
void Ship::setOxygen(int oxygen) {
	this->oxygen = oxygen;

}
void Ship::setCrewMembers(int crewMembers) {
	this->crewMembers = crewMembers;

}

void Ship::setScrap(int scrap) {
	this->scrap = scrap;
}

void Ship::setFTLDrive(int ftlDrive) {
	this->ftlDrive = ftlDrive;
}

void Ship::setFuel(int fuel) {
	this->fuel = fuel;
}

void Ship::setShieldLevel(int shieldLevel) {
	this->shieldLevel = shieldLevel;
}

void Ship::setEngineLevel(int engineLevel) {
	this->engineLevel = engineLevel;

}
void Ship::setOxygenLevel(int oxygenLevel) {
	
	this->oxygenLevel = oxygenLevel;
}

void Ship::setWeaponControlLevel(int weaponControlLevel) {
	this->weaponControlLevel = weaponControlLevel;
}

void Ship::setMedbayLevel(int medbayLevel) {
	this->medbayLevel = medbayLevel;
}

void Ship::setPilotLevel(int pilotLevel) {
	this->pilotLevel = pilotLevel;
}

void Ship::setSensorLevel(int sensorLevel) {
	this->sensorLevel = sensorLevel;

}

void Ship::setDoorLevel(int doorLevel) {
	this->doorLevel = doorLevel;
}

void Ship::setRooms(int rooms) {
	this->rooms = rooms;
}

//Getters -------------------------------------------------------------------------------------------------------------------------------------------
int Ship::getHull() {

	return hull;
}
int Ship::getShield() {

	return shield;
}
int Ship::getEvade() {

	return evade;
}
int Ship::getOxygen() {

	return oxygen;
}
int Ship::getCrewMembers() {

	return crewMembers;
}
int Ship::getScrap() {

	return scrap;
}
int Ship::getFTLDrive() {

	return ftlDrive;
}
int Ship::getFuel() {

	return fuel;
}
int Ship::getShieldLevel() {

	return shieldLevel;
}
int Ship::getEngineLevel() {

	return engineLevel;
}
int Ship::getOxygenLevel() {

	return oxygenLevel;
}
int Ship::getWeaponControlLevel() {

	return weaponControlLevel;
}
int Ship::getMedbayLevel() {

	return medbayLevel;
}
int Ship::getPilotLevel() {

	return pilotLevel;
}
int Ship::getSensorLevel() {

	return sensorLevel;
}
int Ship::getDoorLevel() {

	return doorLevel;
}

int Ship::getRooms() {

	return rooms;
}
