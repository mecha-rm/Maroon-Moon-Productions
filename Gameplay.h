// The class for the game loop
#ifndef GAME_H
#define GAME_H

#include "Ship.h";
#include "Weapon.h";
#include "All_Weapons.h"
#include "Hazard.h";

#include <string>

class Gameplay
{
public:
	Gameplay();

	// prints the rules of the game
	void rules(int res);

	// Game Loop
	bool gameLoop(); // game loop
	
	// gets the player data
	static Ship * getPlayer();
	// gets the enemy data
	static Ship * getEnemy();

private:
	Ship * createShip(int type); // creates a ship based on the number provided.

	// Determines if the game is still being played
	static bool play;

	static Ship * pShip;
	static Ship * enemy;

	All_Weapons weapon = All_Weapons();
};

#endif

