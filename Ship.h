#pragma once
#include "CrewMember.h"

#include <string>
#include <iostream>
#include <vector>
#include "Weapon.h"

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
	std::vector<CrewMember> getCrew();
	std::vector<Weapon> getWeapon();

	// setters
	void setHull(int);
	void setShield(int);
	void setReactor(int);
	void setEvade(int);
	void setOxygen(int);
	// void setCrewMembers(int); // shouldn't be changed since it changes when the player adds 
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
	void setCrew(std::vector<CrewMember>);
	void setWeapon(std::vector<Weapon>);

	// Other

	// adds a crew member. By default, a human is added.
	// MAKE SURE THE STRING IS IN ALL LOWERCASE
	void addCrewMember(std::string); // adds a crew member
	// removes a specific crew member; returns 'true' if successful
	bool removeCrewMember(unsigned int);
	// returns the crew member at the given index
	CrewMember getCrewMember(unsigned int);

	// Model these after the addCrewMember, removeCrewMber and getCrewMember Functions
	// adds a weapon to the list
	Weapon addWeapon();
	// removes a weapon
	bool removeWeapon(unsigned int);
	// returns a weapon at the provided index
	Weapon getWeapon(unsigned int);

	const string shipName; // the ship's name
private:

	//resources
	int hull = 0; // the ship's physical health
	int shield = 0; // the ship's shield's health
	int reactor = 0; // the ship's reactor
	int evade = 0;
	int oxygen = 0;
	int crewMembers = 0;
	int scrap = 0;
	int ftlDrive = 0;
	int fuel = 0;
	int rooms = 0;

	//systems
	int shieldLevel = 0;
	int engineLevel = 0;
	int oxygenLevel = 0;
	int weaponControlLevel = 0;
	int medbayLevel = 0;

	//subsystems
	int pilotLevel = 0;
	int sensorLevel = 0;
	int doorLevel = 0;

	//reactor
	int reactorPower = 0;
	// crew members
	std::vector<CrewMember> crew; // crew member vector
	std::vector<Weapon> weapons; // vector used for weapon storage
};