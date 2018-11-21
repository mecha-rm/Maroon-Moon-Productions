// The class for the game loop
#include "Game.h"
#include "Utilities.h"

Game::Game()
{
}

bool Game::gameLoop()
{

	pShip.printShip(); // prints the ship
	std::cout << std::endl;
	pShip.printStats(); // prints the stats of the ship

	system("pause");
	// system("CLS"); // clear's the screen	
	return false;
}

