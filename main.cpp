/*
Developers: Alexander Da Costa (100704694), Caleb Birnie (100699828), Carter Menary (100700587), Devin Fitzpatrick (100709082), Nathan Tuck (100708651), Roderick “R.J.” Montague (100701758)
Date: 11/18/2018
References:
	> TutorialsPoint.com/switch statements (https://www.tutorialspoint.com/cplusplus/cpp_switch_statement.htm), Cplusplus.com/tolower (http://www.cplusplus.com/reference/cctype/tolower/), FTL: Faster Than Light Wiki/Home (https://ftl.fandom.com/wiki/FTL:_Faster_Than_Light_Wiki)
*/

// Game Development Workshop - Project 3 | FTL: Faster Than Light
#include "Game.h"
#include "Utilities.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Controls.h"

#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <ctype.h>
#include <windows.h>


void rules(int); // the rules of the game

Game game; // the game object
bool menu = true;

// '1' for rules of 'FTL', '2' for rules of the program
void rules(int res)
{
	switch (res)
	{
	case 1: // rules of FTL
		std::cout << "RULES OF 'FTL: FASTER THAN LIGHT'\n**********************************\n" <<
			"* Welcome to FTL! You are the captain of a Federation starship on a very important mission. \n" << 
			"* The Federation is currently being torn apart by vicious Rebels. Your ship is carrying data\n" <<
			"  vital to the defense of the Federation. \n" <<
			"* You will be travelling through dangerous sectors of the galaxy with the Rebel fleet in hot\n" <<
			"* pursuit. Make it to the exit beacon of each sector before the Rebels can catch you. \n" <<
			"* Your ship, the Kestrel, is the focus of the typical game view."
			<< std::endl;
		break;
	case 2: // rules of the program
		std::cout << "RULES OF THE PROGRAM\n**********************************\n" << 
			"* The icons at the bottom left are your ship's primary systems. Systems use power from the  \n" <<
			"  reactor (the bar at the bottom). \n" <<
			"* The icons on the bottom right are your ship's subsystems. Unlike systems, they do not \n" <<
			"  require power from the reactor. \n" <<
			"* Hover your mouse over any system icon to get more information about the system. Each \n" <<
			"  system's corresponding room will light up. \n" << //Just change the font colour of the room identifier
			"* The Hull Meter, Shield Level, and current resources are in the top left. If your Hull \n" <<
			"  Meter is reduced to zero, your ship will explode. \n" <<
			"* Systems are unpowered when the boxes are white, and they are powered when they are green.\n" <<
			"* By default, power systems using the following keys: \n" <<
			"  A - Shields \tS - Engines \tF - Oxygen \n  D - Medbay \tW - Weapons \n" <<
			"* Depower systems by pressing Shift (depower modifier) and the power key you want to depower. \n" <<
			"* Select Crew Members by using F1 to F8, and select all Crew Members with Q \n" <<
			"* Crew Members can be set to stations using / and if they are moved, you can send everyone back \n" <<
			"  to their posts using Enter. They can also be moved to new rooms using E. \n" <<
			"* Time can be toggled to make things easier to process using Space. If you need to escape a node, \n" <<
			"  press J to make an FTL jump. " <<
			"* Many menus are available, including Upgrades (U), Inventory (I), Store (K) [if available], \n" <<
			"  Options (O), and the Pause Menu (Esc). \n" <<
			"* Control Doors using Z to open them, and X to close them. Use the Arrow Keys to select rooms. \n" <<
			"* For combat, use 1 to 4 to select a weapon, use V to toggle Autofire on the ship, and press \n" <<
			"  Tab to switch selection on your ship or the enemy's ship."
			<< std::endl;
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
			input = util::Utilities::toLower(input); // getting the input in all lowercase
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
	
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------

	std::cout << "Thank you for playing our game!" << std::endl;


	return 0;
}
