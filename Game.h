// The class for the game loop
#ifndef GAME_H
#define GAME_H

#include "Ship.h";
#include "Weapon.h";
#include "Hazard.h";

#include <string>

class Game
{
public:
	Game();
	
	std::string toLower(std::string); // converts to lowercase
	bool equalsIgnoreCase(std::string, std::string); // sees if two strings are equal to each other, ignoring case differences
	bool gameLoop(); // game loop

private:

	Ship pShip;

};

#endif

