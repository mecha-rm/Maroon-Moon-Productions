// The class for the game loop
#include "Gameplay.h"
#include "Utilities.h"
// #include "Timer.h"
// #include "Sprite.h"

#include <iostream>
#include <random>
// #include <ctime>
#include <string>
// #include <ctype.h>
// #include <windows.h>
#include <sstream>


// Gameplay is playing by default
bool Gameplay::play = true;

Gameplay::Gameplay() { 
	// tw.ResizeScreenBuffers(twWidth, twHeight);
}

// Gameplay Loop
bool Gameplay::gameLoop()
{

	std::string input("");
	std::stringstream strStream; // gets strigns as streams
	int index = -1; // the selected index by the player.
	
	int eWeapon(0); // saves index of ship's chosen weapon
	bool noOptions(true); // sees if there's an available option.
	vector<Weapon *>availableWeapons; // used by the enemy to determine what weapons can be used.


	while (enemy.getHull() > 0 && pShip.getHull() > 0)
	{
		std::cout << "PLAYER\n******************************************************" << std::endl;
		pShip.printShip();
		std::cout << std::endl;
		pShip.printStats();


		std::cout << "\nENEMY\n******************************************************" << std::endl;
		enemy.printShip();
		std::cout << std::endl;
		enemy.printStats();

		// Fires off any weapons already charged
		for (int i = 0; i < pShip.weapons.size(); i++)
		{
			if (pShip.weapons.at(i).isCharged())
			{
				// This does direct damage to the hull, and needs to be changed.
				std::cout << "Weapon " << pShip.weapons.at(i).getName() << " has been fired! " << std::endl;
				enemy.setHull(enemy.getHull() - pShip.weapons.at(i).getHullDam());
				pShip.weapons.at(i).setCharge(0);
			}
			
		}

		// Fires off enenmy weapons that are charged
		for (int i = 0; i < enemy.weapons.size(); i++)
		{
			if (enemy.weapons.at(i).isCharged())
			{
				std::cout << "The enemy has used " << enemy.weapons.at(i).getName() << "!" << std::endl;
				// Once again, neesd to be changed.
				pShip.setHull(pShip.getHull() - enemy.weapons.at(i).getHullDam()); // damanging the player
				enemy.weapons.at(i).setCharge(0);
			}
			
		}

		// Checks to see if there's an input available
		for (int i = 0; i < pShip.weapons.size(); i++)
		{
			noOptions = pShip.weapons.at(i).isCharging(); // if a 'false' is returned, the weapon isn't charging.
			if (noOptions == false) // there are options, so break out of the program.
				break;
		}

		// Lists available options and asks for input
		if (!noOptions)
		{

			std::cout << std::endl;
			std::cout << "Select a weapon to use \n-----------------------------------------" << std::endl;

			std::cout << "X) SKIP" << std::endl;
			// prints the options
			for (int i = 0; i < pShip.weapons.size(); i++)
			{
				// If the weapon isn't being used, it's listed as an option.
				if (pShip.weapons.at(i).isAvailable())
				{
					std::cout << i + 1 << ") " << pShip.weapons.at(i).toString() << std::endl;
				}
				
			}
				

			do
			{
				index = -1;
				strStream.clear();
				std::cout << std::endl;

				std::cout << "Select a weapon via its number: ";
				std::getline(std::cin, input);

				strStream.str(input);
				strStream >> index; // index is currently offset by '1'. Make sure to do 'index - 1' when checking for validity.

				// Skipping the user's turn
				if (util::Utilities::equalsIgnoreCase(input, "X"))
				{
					std::cout << "Skipping Turn." << std::endl;
					break;
				}

				// If something went wrong
				if (strStream.bad() || index == -1)
				{
					std::cout << "Something went wrong. Try again." << std::endl;
					input = "";
					continue;
				}

				// If the option doesn't exist
				if (index <= 0 || index > pShip.weapons.size())
				{
					std::cout << "No weapon exists with that identification number. Go again." << std::endl;
					input = "";
					continue;
				}
				// Weapon is already charging, or otherwise unavailable
				else if (!pShip.weapons.at(index - 1).isAvailable())
				{
					std::cout << "That option is currently not available." << std::endl;
					input = "";
					continue;
				}

				// starts charging the weapon for use.
				std::cout << "Charging of Weapon #" << input << " (" << pShip.weapons.at(index - 1).getName() << ") has begun!" << std::endl;
				pShip.weapons.at(index - 1).increaseCharge(); // increases the charge by '1'.


			} while (input == "");
		}

		std::cout << std::endl;
		// charges weapons
		for (int i = 0; i < pShip.weapons.size(); i++)
		{
			// if the weapon is charging, it adds +1 to the charge
			if (pShip.weapons.at(i).isCharging())
			{
				std::cout << pShip.weapons.at(i).getName() << " is Charging. Progress: " << pShip.weapons.at(i).getCharge() << "/" << pShip.weapons.at(i).getChargeTime() << std::endl;
				pShip.weapons.at(i).increaseCharge();
			}
		}
		
		// Enemy Decisions
		// has the enemy pick a weapon to use if possible.
		for (int i = 0; i < enemy.weapons.size(); i++)
		{
			noOptions = enemy.weapons.at(i).isCharging(); // if a 'false' is returned, the weapon isn't charging.
			
			if (noOptions == false) // there are options, so it kepes track of possible options.
			{
				// gets a reference to the weapon.
				availableWeapons.push_back(&enemy.weapons.at(i));
				break;
			}
			// increases weapon charge if it's set to be charged.
			if (enemy.weapons.at(i).isCharging())
			{
				enemy.weapons.at(i).increaseCharge();
			}
		}

		// Chooses a random weapon if one is available.
		if (!availableWeapons.empty()) // sees if there are weapons to choose from
		{
			availableWeapons.at(rand() % availableWeapons.size())->increaseCharge(); // starts charging a random weapon.
			availableWeapons.clear(); // removes all weapons from the 'usable' weapons list.
		}

		strStream.clear(); // clearing the string stream
		std::system("pause"); // something else also uses 'system', so the reference needed to be specified.
		std::system("CLS");
	}


	return false;
}

Ship Gameplay::createShip(int type)
{
	Ship tempShip = Ship();

	return Ship();
}