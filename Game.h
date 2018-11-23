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
	
	bool gameLoop(); // game loop

private:
	void bufferColourTest(); // print colour options
	void bufferTypeTest(); // typing to the screen
	void bufferColourTypeTest(); // typing and printing colour options
	Ship pShip;

};

#endif

