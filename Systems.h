// Used for the system that a room contains. This was unused in the final game.
#pragma once
#include "Room.h"

class Systems {

	Systems(std::string type, bool bonus, int maxPower, int health); // constructor

public:
	std::string getName(); // the name of the system
	std::string getType(); // main system or subsystem
	bool getBuff(); // the buffs applied by the system
	int getMaxPower(); // the maximum power of the system
	int getCost(); // the cost of the system
	int getHealth(); // the health of the system

	void setName(std::string); // system name
	void setType(std::string); // main vs. subsystem
	void setBuff(bool); // the system's buff
	void setMaxPower(int); // the system's maximum power
	void setCost(int); // the system's cost
	void setHealth(int); // the system's health
	void repair(); // repairs the system

private:
	std::string name; // the system's name
	std::string type; // main system or subsystem
	bool buff; // whether or not hte buff is applied 
	int maxPower; // the maximum power of the system
	int cost; // the price of the system
	int health; // the health of the system

	Room room = Room('A', 3, "pilot", 100); // the room the system is in.

};