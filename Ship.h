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
	bool getSensor();

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
	void setSensor(bool);

	// Other
	
	//If the player has a shield the damage must be done to the shield first and then the health, this takes care fo that
	void shieldToHealth(int);
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

	// saves the type of the room
	string roomType(string);
	// prints a map of the ship
	void printShip();
	// prints the stats of the ship
	void printStats();

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
	bool sensor = false; 

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


	//The Map of the Ship
	//Eventually this should become an external to the class which is inputted into the class rather than initialized within it.
	const int shipMapWidth = 6;
	const int shipMapLength = 15;

	/*The Map System!
		
		Each string within this 2D array represents a grid space of the ship. each string is a five-character array that represents the walls surrounding the grid space, and 
		what is within the grid space.

		The formatting is as follows [to the left, above, to the right, below, room type].

		For example, an empty space with a door above it, a wall below it, and nothing to either side would be "ndnwe".
		Conversely, a string that is "wwdne" would be an empty room with a wall to the left and above, nothing to the right, and a door below.

		Wall Characters:
			n - nothing
			w - a wall
			d - a door
			o - an open door

		Room Characters:
			e - empty
			*add more as room types become available

		Additional Cases:
			"empty" - this produces a space with nothing in it.
			"block" - this produces a solid ship part that is not a room.
	*/

	string shipMap[6][15]= {{"empty","empty","empty","empty","empty","empty","wdnwe","ndwde","empty","empty","empty","empty","empty","empty","empty"},
							{"empty","wwnwe","nwdde","dwnwe","nwwde","block","wwnne","nddne","dwnne","nwwne","empty","empty","empty","empty","empty"},
							{"dwdne","dwnne","ndwne","block","wdnne","nwdne","dnnwe","nnwwe","wnnde","nndwe","dwnwe","nwdwe","dwnne","nwwne","wwwne"},
							{"dndwe","dnnwe","nndwe","block","wnnde","nndwe","dwnne","nwwne","wdnne","nwdne","dwnwe","nwdwe","dnnwe","nndwe","dnwwe"},
							{"empty","wwnwe","nddwe","dwnwe","ndwwe","block","wnnwe","nndde","dnnwe","nnwwe","empty","empty","empty","empty","empty"},
							{"empty","empty","empty","empty","empty","empty","wwnde","ndwde","empty","empty","empty","empty","empty","empty","empty"} };

	
};