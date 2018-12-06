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

	// prints the rules of the game in text; this was based on the original control scheme of our game, so it's outdated.
	void rules(int res);
	// Prints the rooms of both ships based on the passed value. If  a '<= 0' is passed, it prints the player's rooms. If a "> 0" value is passed, it prints the enemy's rooms.
	void printRooms(int);

	// goes onto the next battle.
	static void nextBattle();

	// Game Loop; the battling happens here.
	bool gameLoop(); // game loop
	
	// Returns whether or not the game is currently being played.
	static bool getPlay();
	// Sets whether or not the game is being played
	static void setPlay(bool play);

	// gets the round number
	static unsigned int getBattle();
	// sets the round number
	void setBattle(unsigned int battle);
	// gets the player data by returning the player's ship object
	static Ship * getPlayer();
	// gets the enemy data by returning the opponent's ship object
	static Ship * getEnemy();
	// If true, then the player has won; if false, then the player has lost.
	static bool getPlayerWins();

private:
	// is true if the player wins, is false if the player lost
	static bool playerWins;
	// sets the bool value of playerWins
	static void setPlayerWins(bool playerWins);
	// gives the user a list of rewards that they can choose from when going onto the next round.
	void powerUp();

	// creates a ship based on the number provided.
	Ship * createShip(int type);

	// Determines if the game is still being played
	static bool play;
	// Saves what round the player is on.
	static unsigned int battle;

	static Ship * pShip; // the player's ship object
	static Ship * enemy; // the opponent's ship object

	All_Weapons weapon = All_Weapons(); // an object that allows access to all weapons using the All_Weapons() class.
};

#endif

