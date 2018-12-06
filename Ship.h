// Class used for creating ship objects
#pragma once
#include "CrewMember.h"
#include "Weapon.h"
#include "Room.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Ship {
public:
	Ship();
	Ship(std::string name); // setting the ship's name

	// getters
	std::string getName(); // the ship's name
	std::string getImagePath(); // the ship's image path
	int getHull(); // the ship's current health
	int getMaxHull(); // the ship's highest possible health
	int getShield(); // the ship's base shielding amount per room
	int getShieldMax(); // the ship's highest shielding amount (UNUSED)
	int getReactor(); // the ship's reactor; this would've been used to power weapons (UNUSED)
	int getEvade(); // ship's evasion stat (UNUSED)
	int getOxygen(); // ship's oxygen level (UNUSED)
	int getCrewMembers(); // gets the crew members a ship has (UNUSED)
	int getScrap(); // gets the amount of scrap the ship has. 'Scrap' is the currency of FTL (UNUSED)
	int getFTLDrive(); // gets the value of the drive used by the ship to travel from area to area (UNUSED)
	int getFuel(); // the ship's amount of fuel for travelling (UNUSED)
	int getShieldLevel(); // the shield's shield level. Originally, there were going to be different tiers of ships (UNUSED)
	int getEngineLevel(); // the ship's engine level; this would've assisted speed and evasion stats (UNUSED)
	int getOxygenLevel(); // the level of the ship's oxygen, which would've been upgradable (UNUSED)
	int getWeaponControlLevel(); // (?) (UNUSED)
	int getMedbayLevel();// the level of the ship's medical facility (UNUSED)
	int getPilotLevel(); // the current level of the ship's pilot (UNUSED)
	int getSensorLevel(); // the level of the ship's sensors, which are used for perception (UNUSED)
	int getDoorLevel(); // the quality of the ship's doors (UNUSED)
	int getRooms(); // the amount of rooms a ship has
	bool getSensor(); // whether the sensors of a ship are working (UNUSED)

	// setters for the values explained above.
	void setImagePath(std::string imagePath);
	void setHull(int); // the current health of the ship
	void setMaxHull(int); // the maximum health of the ship
	void setShield(int); // the shielding a ship has
	void setShieldMax(int); // (UNUSED)
	void setReactor(int); // (UNUSED)
	void setEvade(int); // (UNUSED)
	void setOxygen(int); // (UNUSED)
	void setScrap(int); // (UNUSED)
	void setFTLDrive(int); // (UNUSED)
	void setFuel(int); // (UNUSED)
	void setShieldLevel(int); // (UNUSED)
	void setEngineLevel(int); // (UNUSED)
	void setOxygenLevel(int); // (UNUSED)
	void setWeaponControlLevel(int); // (UNUSED)
	void setMedbayLevel(int); // (UNUSED)
	void setPilotLevel(int); // (UNUSED)
	void setSensorLevel(int);// (UNUSED)
	void setDoorLevel(int); // (UNUSED)
	void setRooms(int); // the amount of rooms a ship has.
	void setCrew(std::vector<CrewMember>);
	void setSensor(bool); // (UNUSED)

	// Other
	//If the player has a shield. The damage must be done to the shield first and then to the ship's hull. This was the original way we were going to do that. (UNUSED)
	void shieldToHealth(int);
	// adds a crew member. By default, a human is added.
	void addCrewMember(std::string species, char room); // adds a crew member
	// returns the crew member at the given index
	CrewMember getCrewMember(unsigned int index);

	// Gets the whole crew as a vector
	std::vector<CrewMember> getCrew();
	// returns a weapon at the provided index. If there is no weapon there, a 'TEST WEAPON' is provided.
	Weapon getWeapon(unsigned int index);
	// returns all weapons
	std::vector<Weapon> getWeapons();
	// adds a weapon to the list
	void addWeapon(Weapon);
	// sets a new vector of weapons
	void setWeapons(std::vector<Weapon> newWeapons);
	// removes the last lesson in the vector.
	void removeWeapon();
	// removes a weapon at a given index.
	void removeWeapon(unsigned int index);

	// saves the type of the room (UNUSED)
	string roomType(string);
	// makes a crew member move (x) amount of spaces if they're already moving (UNUSED)
	void crewMove();
	// Has the crew member find their path (UNUSED).
	bool pathfind(int num);
	// Used for setting up the pathways a crew member can go on (UNUSED).
	bool pathfindRec(int, int, int, int);

	// prints a map of the ship
	void printShip();
	// prints the stats of the ship
	void printStats();
	// gets a health bar of the ship.
	std::string getHealthBar();
	// prints data about the ship
	std::string toString();

	const string shipName; // the ship's name
	std::vector<CrewMember> crew; // crew member vector
	std::vector<Weapon> weapons; // vector used for weapon storage
	std::vector<Room *> areas; // the rooms of the ship

private:
	std::string imagePath; // the file path of the image representing the object

	// resources
	int hull = 0; // the ship's physical health
	int maxHull = 30; // the ship's maximum health
	int shield = 0; // the ship's shield's health
	int shieldMax = 0; // the maximum protection the shield gives the user (UNUSED).
	int reactor = 0; // the ship's reactor used for powering weapons (UNUSED)
	int evade = 0; // the ship's evasion stat (UNUSED)
	int oxygen = 0; // the oxygen levels of the ship (UNUSED)
	int crewMembers = 0; // the number of crew members on the ship (UNUSED)
	int scrap = 0; // the amount of FTL currency the ship has (UNUSED)
	int ftlDrive = 0; // the drive used for jumping from sector to sector (UNUSED)
	int fuel = 0; // the ship's fuel (UNUSED)
	int rooms = 0; // the number of rooms (UNUSED)
	bool sensor = false; // the ship's sensors for finding other ships (UNUSED)

	// systems
	int shieldLevel = 0; // the level of the ship's shield (UNUSED)
	int engineLevel = 0; // the level of the ship's engine (UNUSED)
	int oxygenLevel = 0; // the level of the ship's oxygen (UNUSED)
	int weaponControlLevel = 0; // the level of control the crew members have over their weapons(?) (UNUSED)
	int medbayLevel = 0; // the level of the ship's medical pay (UNUSED)

	//subsystems
	int pilotLevel = 0; // the ship's piloting systems (UNUSED)
	int sensorLevel = 0; // the ship's sensor levels (UNUSED)
	int doorLevel = 0; // the ship's door levels (UNUSED)

	// reactor
	int reactorPower = 0; // the max amount of power the reactor has(?) (UNUSED)

	//The Map of the Ship - this was originally going to be used to print out a ship in text(UNUSED)
	const int shipMapWidth = 6; // The width of the array (UNUSED)
	const int shipMapLength = 15; // The length of the array (UNUSED)

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

	string shipMap[6][15] = { {"empty","empty","empty","empty","empty","empty","wdnwe","ndwde","empty","empty","empty","empty","empty","empty","empty"},
						{"empty","wwnwe","nwdde","dwnwe","nwwde","block","wwnne","nddne","dwnne","nwwne","empty","empty","empty","empty","empty"},
						{"dwdne","dwnne","ndwne","block","wdnne","nwdne","dnnwe","nnwwe","wnnde","nndwe","dwnwe","nwdwe","dwnne","nwwne","wwwne"},
						{"dndwe","dnnwe","nndwe","block","wnnde","nndwe","dwnne","nwwne","wdnne","nwdne","dwnwe","nwdwe","dnnwe","nndwe","dnwwe"},
						{"empty","wwnwe","nddwe","dwnwe","ndwwe","block","wnnwe","nndde","dnnwe","nnwwe","empty","empty","empty","empty","empty"},
						{"empty","empty","empty","empty","empty","empty","wwnde","ndwde","empty","empty","empty","empty","empty","empty","empty"} };

	string flipMap[6][15] = { {"empty","empty","empty","empty","empty","empty","wwndc","ndwde","empty","empty","empty","empty","empty","empty","empty"},
								{"empty","wwnwe","nddwe","dwnwe","ndwwe","block","wnnwe","nndde","dnnwe","nnwwe","empty","empty","empty","empty","empty"},
								{"dndwe","dnnwe","nndwe","block","wnnde","nndwe","dwnne","nwwne","wdnne","nwdne","dwnwe","nwdwe","dnnwe","nndwe","dnwwe"},
								{"dwdne","dwnne","ndwne","block","wdnne","nwdne","dnnwe","nnwwe","wnnde","nndwe","dwnwe","nwdwe","dwnne","nwwne","wwwne"},
								{"empty","wwnwe","nwdde","dwnwe","nwwde","block","wwnne","nddne","dwnne","nwwne","empty","empty","empty","empty","empty"},
								{"empty","empty","empty","empty","empty","empty","wdnwe","ndwde","empty","empty","empty","empty","empty","empty","empty"}, };

	bool dynamicMap[6][15];
	
};