// The class for the game loop
#ifndef GAME_H
#define GAME_H

#include "Ship.h";
#include "Weapon.h";
#include "All_Weapons.h"
#include "Hazard.h";
// #include "GameWindow.h"

#include <string>

class Gameplay
{
public:
	Gameplay();

	// Game Loop
	bool gameLoop(); // game loop
	Ship createShip(int type); // creates a ship based on the number provided.

private:
	
	// Determines if the game is still being played
	static bool play;

	Ship pShip;
	Ship enemy;

	All_Weapons weapon = All_Weapons();
};

#endif

