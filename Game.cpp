// The class for the game loop
#include "Game.h"
#include "Utilities.h"

Game::Game()
{
}

bool Game::gameLoop()
{

	pShip.printShip();
	system("pause");
	return false;
}

