#pragma once
#include <string>
#include <iostream>
using namespace std;

class Ship {
public:

	string shipName;

	int getHull();
	int getShield();
	int getEvade();
	int getOxygen();
	int getCrewMembers();
	int getScrap();
	int getFTLDrive();
	int getFuel();
	int getShieldLevel();
	int getEngineLevel();
	int getOxygenLevel();
	int getWeaponControlLevel();
	int getMedbayLevel();
	int getPilotLevel();
	int getSensorLevel();
	int getDoorLevel();
	int getRooms();

	void setHull(int);
	void setShield(int);
	void setEvade(int);
	void setOxygen(int);
	void setCrewMembers(int);
	void setScrap(int);
	void setFTLDrive(int);
	void setFuel(int);
	void setShieldLevel(int);
	void setEngineLevel(int);
	void setOxygenLevel(int);
	void setWeaponControlLevel(int);
	void setMedbayLevel(int);
	void setPilotLevel(int);
	void setSensorLevel(int);
	void setDoorLevel(int);
	void setRooms(int);

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
	int rooms;

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