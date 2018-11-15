#pragma once
#include <string>
#include <iostream>
using namespace std;

class Ship {
public:

	string shipName;

private:

	//resources
	int hull;
	int shield;
	int evade;
	int oxygen;
	int crewMembers;
	int scrap;
	int ftlDrive;
	int fuel;

	//systems
	int shieldLevel;
	int engineLevel;
	int oxygenLevel;
	int weaponControlLevel;
	int medbayLevel;

	//subsystems
	int pilotLevel;
	int sensorLevel;
	int doorLevel;

	//reactor
	int reactorPower;

};