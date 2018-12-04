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
	// '0' - print player rooms, '1' - print 
	void printRooms(int);

	// goes onto the next battle
	static void nextBattle();
	// returns the image of the enmey.
	// static std::string getEnemyImage();

	// Game Loop
	bool gameLoop(); // game loop
	
	// Returns whether or not the game is currently being played.
	static bool getPlay();

	// Sets whether or not the game is being played
	static void setPlay(bool play);

	// gets the fight number
	static unsigned int getBattle();
	// sets the fight number
	void setBattle(unsigned int battle);
	// gets the player data
	static Ship * getPlayer();
	// gets the enemy data
	static Ship * getEnemy();

	static bool getPlayerWins(); // gets the winner of the game

private:
	static bool playerWins; // is true if the player wins, is false if the player lost
	static void setPlayerWins(bool playerWins);
	// gifts the user something of their choice.
	void powerUp();

	Ship * createShip(int type); // creates a ship based on the number provided.

	// Determines if the game is still being played
	static bool play;
	static unsigned int battle;

	static Ship * pShip;
	static Ship * enemy;

	All_Weapons weapon = All_Weapons();
};

#endif

