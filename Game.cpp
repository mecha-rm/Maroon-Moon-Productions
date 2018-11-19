// The class for the game loop
#include "Game.h"

Game::Game()
{
}

// converts a string to all lowercase
std::string Game::toLower(std::string str)
{
	std::string strL;
	strL.assign(str); // copies original string

	for (int i = 0; i < strL.length(); i++)
	{
		strL.at(i) = tolower(strL.at(i)); // converts each 'char' to its lowercase version if applicable
	}

	return strL;
}

// compares two strings to see if they're equal, ignoring any case differences
bool Game::equalsIgnoreCase(std::string str1, std::string str2)
{
	// making both strings lowercase
	str1 = toLower(str1);
	str2 = toLower(str2);
	return str1 == str2; // returning whether the two are equal
}

bool Game::gameLoop()
{
	
	system("pause");
	return false;
}

