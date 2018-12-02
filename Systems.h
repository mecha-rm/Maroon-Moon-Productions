#pragma once
#include "Room.h"


class Systems {

	Systems(std::string type, bool bonus, int maxPower, int health);

public:
	std::string getName();
	std::string getType();//main system or subsystem
	bool getBuff();
	int getMaxPower();
	int getCost();
	int getHealth();

	void setName(std::string);
	void setType(std::string);
	void setBuff(bool);
	void setMaxPower(int);
	void setCost(int);
	void setHealth(int);

	void repair();

private:
	std::string name;
	std::string type;
	bool buff;
	int maxPower;
	int cost;
	int health;

	Room room = Room(1, "pilot", 100);

};