// The class for the game loop
#ifndef GAME_H
#define GAME_H

#include "Ship.h";
#include "Weapon.h";
#include "All_Weapons.h"
#include "Hazard.h";
#include "GameWindow.h"

#include <string>

class Game
{
public:
	Game();

	// Game Loop
	bool gameLoop(); // game loop
	Ship createShip(int type); // creates a ship based on the number provided.


	// creates the buffer for the user input, and initalizes timer
	void createTextWindow();
	// allows the user to type to the screen; if a 'true' boolean is returned, then the user has decided to enter in their input.
	bool typeToWindow(std::string &);

private:
	void windowColourTest(); // print colour options
	void windowTypeTest(); // typing to the screen
	void windowColourTypeTest(); // typing and printing colour options
	
	// Determines if the game is still being played
	static bool play;

	// Text Buffer Window Variables
	// Original: twWidth = 1600, twHeight = 800
	float twWidth = 1920; // text window length
	float twHeight = 1080; // text window height
	GameWindow tw; // university text window size; gets set in constructor
	HANDLE hIn;
	HANDLE hOut;
	INPUT_RECORD InRec;
	DWORD NumRead;

	Ship pShip;
	Ship enemy;

	All_Weapons weapon = All_Weapons();
};

#endif

