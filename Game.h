// The class for the game loop
#ifndef GAME_H
#define GAME_H

#include "Ship.h";
#include "Weapon.h";
#include "Hazard.h";

class Game
{
public:
	Game();
	
	bool gameLoop();

private:

	Ship pShip;

};

#endif

