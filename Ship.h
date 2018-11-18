#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Ship {
public:
	Ship();
	Ship(std::string); // setting the ship's name

	// getters
	int getHull();
	int getShield();
	int getReactor();
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

	// setters
	void setHull(int);
	void setShield(int);
	void setReactor(int);
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

	const string shipName; // the ship's name

private:

	//resources
	int hull; // the ship's physical health
	int shield; // the ship's shield's health
	int reactor; // the ship's reactor
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

	// crew members
	

};