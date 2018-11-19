/*
Developers: Alexander Da Costa (100704694), Caleb Birnie (100699828), Carter Menary (100700587), Devin Fitzpatrick (100709082), Nathan Tuck (100708651), Roderick “R.J.” Montague (100701758)
Date: 11/16/2018
References:
	> TutorialsPoint.com/switch statements (https://www.tutorialspoint.com/cplusplus/cpp_switch_statement.htm), Cplusplus.com/tolower (http://www.cplusplus.com/reference/cctype/tolower/), FTL: Faster Than Light Wiki/Home (https://ftl.fandom.com/wiki/FTL:_Faster_Than_Light_Wiki)
*/

// Game Development Workshop - Project 3 | FTL: Faster Than Light
#include "Game.h"

#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <ctype.h>

void rules(int); // the rules of the game

Game game; // the game object

// '1' for rules of 'FTL', '2' for rules of the program
void rules(int res)
{
	switch (res)
	{
	case 1: // rules of FTL
		std::cout << "RULES OF 'FTL: FASTER THAN LIGHT'\n**********************************" << std::endl;
		break;
	case 2: // rules of the program
		std::cout << "RULES OF THE PROGRAM\n**********************************" << std::endl;
		break;
	default:
		std::cout << "There is nothing corresponding to that value" << std::endl;
		break;
	}
}

int main() // main function
{
	srand(time(0)); // seeding the randomizer

	std::string input(""); // gets user input
	bool success; // determines whether the game was won or not.

	std::cout << "Game Development Workshop I - Project 3 by Maroon Moon Productions." << std::endl;
	std::cout << "GAME: FTL: Faster Than Light" << std::endl;
	std::cout << "*This program is based off 'FTL: Faster Than Light', which is owned by Subset Games. This is by no means meant to infringe on the original property, and exists only for non-profit, educational purposes.*" << std::endl;
	std::cout << "************************************************" << std::endl;

	std::cout << "\nWelcome, user, to a text-based version of 'FTL: Faster Than Light'." << std::endl;
	
	do { // asking user whether they need to the rules to be explained.
		std::cout << "How much do you know about the program and the game it's based off of? Select an option using a corresponding number." << std::endl;

		std::cout << "\n1) I know the rules of FTL, and how this program works." << std::endl;
		std::cout << "2) I know the rules of FTL, but not how this program differs from it." << std::endl;
		std::cout << "3) I know how this program works, but I need a referesher on how FTL works." << std::endl;
		std::cout << "4) I know not how FTL works, nor how this program works." << std::endl;

		std::cout << "\nChoice: ";
		std::getline(std::cin, input);
		
		std::cout << std::endl;
		if (input == "1") // they know the rules and how the program works
		{
			std::cout << "\nAlright! I won't go over the rules then." << std::endl;
		}
		else if (input == "2") // they know how FTL works, but not how the program works
		{
			std::cout << "\nOkay, I'll go over the workings of the program then." << std::endl;
			rules(2);
		}
		else if (input == "3") // they know how the program works, but not how FTL works
		{
			std::cout << "\nOkay, I'll give you a refresher on how 'FTL: Faster Than Light' functions." << std::endl;
			rules(1);
		}
		else if (input == "4") // they don't know FTL, or how this program works
		{
			std::cout << "\nAlright! I'll give you a quick explanation of how FTL works, and how this program works." << std::endl;
			rules(1);
			std::cout << std::endl;
			rules(2);
		}
		else
		{
			std::cout << "Invalid Input. Go again." << std::endl;
			input = "";
		}
		std::cout << std::endl;

	} while (input == "");

	input = "";
	do // game loop
	{
		std::cout << "\nNow that the rules are out of the way, are you ready proceed? When you are, press any key (except the power button) to start." << std::endl;
		system("pause");
		std::cout << std::endl;

		success = game.gameLoop(); // gmae loop

		if (success) // starts the game. If a 'true' is returned, the player won. If a 'false' is returned, the player lost.
		{
			std::cout << "\nCongratulations! You have won the game!" << std::endl;
		}
		else
		{
			std::cout << "\nGame Over. You have lost the game." << std::endl;
		}

		do // asking the user if they want to play again
		{
			std::cout << "Do you wish to play again? Enter '1' for yes, and '2' for no." << std::endl;
			std::cout << "Choice: ";
			
			getline(std::cin, input);
			input = game.toLower(input); // getting the input in all lowercase
			std::cout << std::endl;

			if (input == "yes" || input == "y" || input == "1") // play again
			{
				std::cout << "Okay, starting up a new game!" << std::endl;
			}

			else if (input == "no" || input == "n" || input == "2") // do not play again
			{
				std::cout << "Okay, ending the game!" << std::endl;
				input = "exit";
			}
			else // invalid
			{
				std::cout << "Input Invalid. Try Again.\n" << std::endl;
				input = "";
			}

		} while (input == "");

		std::cout << std::endl;

	} while (input != "exit");
	
	std::cout << "Thank you for playing our game!" << std::endl;
	system("pause");
	return 0;
}
