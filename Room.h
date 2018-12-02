#pragma once

#include <string>

class Room {
public:
	Room(int amountOfCrewMemebers, std::string system, int oxygen);
	int getAmountOfCrewMembers();
	std::string getSystem();
	int getOxygen();

	void setAmountOfCrewMemebers(int);
	void setSystem(std::string);
	void setOxygen(int);


private:
	int amountOfCrewMembers;
	std::string system;
	int oxygen;

};