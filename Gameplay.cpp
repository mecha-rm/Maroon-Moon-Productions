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
// player ship and enemy ship
Ship * Gameplay::pShip = new Ship(); // inital values
Ship * Gameplay::enemy = new Ship(); // inital values

Gameplay::Gameplay() 
{
	pShip = createShip(0);
	enemy = createShip(1);
}

void Gameplay::rules(int res)
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

// Gameplay Loop
bool Gameplay::gameLoop()
{

	std::string input("");
	std::stringstream strStream; // gets strigns as streams
	int index = -1; // the selected index by the player.
	
	int eIndex; // an index relating to the enemy.

	bool noOptions(true); // sees if there's an available option.
	vector<Weapon *>availableWeapons; // used by the enemy to determine what weapons can be used.
	
	int randInt; // a random integer
	int multiply = 1; // multiplies the damage done under certian conditions

	bool pause = false; // toggle for system("pause") at the end of the loop.
	bool textShip = false; // prints the ships out in text.
	bool battleLoop = false; // if true, the text window loops the battle here, rather than going back for graphical upates.

	do
	{
		// tells the game to print the ship stats out in text.
		if (textShip)
		{
			std::cout << "PLAYER\n******************************************************" << std::endl;
			pShip->printShip();
			std::cout << std::endl;
			pShip->printStats();


			std::cout << "\nENEMY\n******************************************************" << std::endl;
			enemy->printShip();
			std::cout << std::endl;
			enemy->printStats();
		}

		// Fires off any weapons already charged
		for (int i = 0; i < pShip->weapons.size(); i++)
		{
			if (pShip->weapons.at(i).isCharged())
			{
				// This does direct damage to the hull, and needs to be changed.
				// fires the weapon 'x' amount of times based on how many shots there are.
				for (int shot = 1; shot <= pShip->weapons.at(i).getShots(); shot++)
				{
					std::cout << "Weapon " << pShip->weapons.at(i).getName() << " has been fired! " << std::endl;

					// If the weapon's accuracy is less than what the randomizer gets, the weapon misses.
					if (pShip->weapons.at(i).getAccuracy() < rand() % 10 + 1)
					{
						std::cout << "The " << pShip->weapons.at(i).getName() << " missed! " << std::endl;
						pShip->weapons.at(i).setCharge(0);
						continue;
					}

					randInt = rand() % 10 + 1; // generated a random number for seeing if a certain chance event happens.
					// Causes extra damage if true
					if (pShip->weapons.at(i).getChanceFire() >= randInt)
					{
						std::cout << "A brief fire was started! The damage was increased!" << std::endl;
						multiply = 2;
					}
					// Causes the shield to be destroyed in that area.
					if (pShip->weapons.at(i).getChanceBreach() >= randInt)
					{
						for (int j = 0; j < enemy->areas.size(); j++)
						{
							// If the target has been found
							if (pShip->weapons.at(i).getTarget() == enemy->areas.at(j)->getID())
							{
								enemy->areas.at(j)->setShield(0);
								std::cout << "The shield in area " << enemy->areas.at(j)->getID() << " of the enemy's ship has been breached! It's gone!" << std::endl;
								break;
							}
						
						}

					}
					// Causes one of the enemy's weapons to lose its charge.
					if (pShip->weapons.at(i).getChanceStun() >= randInt)
					{
						std::cout << "A power surge has occurred!";
						randInt = rand() % enemy->weapons.size(); // chooses a random weapon
						enemy->weapons.at(randInt).setCharge(0);
						std::cout << "The enemy's " << enemy->weapons.at(randInt).getName() << " lost its charge!" << std::endl;

					}

					for (int j = 0;  j < enemy->areas.size(); j++)
					{
						// If the target has been found
						if (pShip->weapons.at(i).getTarget() == enemy->areas.at(j)->getID())
						{
							// Damaging the shield.
							if (enemy->areas.at(j)->getShield() > 0)
							{
								enemy->areas.at(j)->setShield(enemy->areas.at(j)->getShield() - pShip->weapons.at(i).getShieldDam());
								
								std::cout << "Your attack was blocked by a shield! You did " << pShip->weapons.at(i).getShieldDam() << " damage to it!" << std::endl;
								if (enemy->areas.at(j)->getShield() <= 0)
								{
									std::cout << "The shield was destroyed!" << std::endl;
								}
							
							}
							// Damaging the hull
							else if (enemy->areas.at(j)->getShield() <= 0)
							{
								enemy->setHull(enemy->getHull() - pShip->weapons.at(i).getHullDam() * multiply);
								std::cout << std::to_string(pShip->weapons.at(i).getHullDam() * multiply) << " damage has been done to te hull!" << std::endl;
							}

							break;
						}
					}
					
					
					pShip->weapons.at(i).setCharge(0); // setting the charge of the weapon to zero.
					multiply = 1;
				}
				
			}
			std::cout << std::endl;
			
		}

		std::cout << std::endl;

		// Fires off enenmy weapons that are charged
		for (int i = 0; i < enemy->weapons.size(); i++)
		{
			if (enemy->weapons.at(i).isCharged())
			{
				for (int shot = 1; shot <= enemy->weapons.at(i).getShots(); shot++)
				{
					std::cout << "The enemy has used " << enemy->weapons.at(i).getName() << "!" << std::endl;
					pShip->setHull(pShip->getHull() - enemy->weapons.at(i).getHullDam()); // damanging the player
					enemy->weapons.at(i).setCharge(0);

					/*
					for (int j = 0; j < enemy->areas.size(); j++)
					{
						pShip->setHull(pShip->getHull() - enemy->weapons.at(i).getHullDam()); // damanging the player
						enemy->weapons.at(i).setCharge(0);

					}
					*/
				}
				

				
			}
			
		}

		// Checks to see if there's an input available
		for (int i = 0; i < pShip->weapons.size(); i++)
		{
			noOptions = pShip->weapons.at(i).isCharging(); // if a 'false' is returned, the weapon isn't charging.
			if (noOptions == false) // there are options, so break out of the program.
				break;
		}

		// Lists available options and asks for input
		if (!noOptions)
		{

			std::cout << std::endl;
			std::cout << "Select a weapon to use \n-----------------------------------------" << std::endl;

			std::cout << "X) Exit Game" << std::endl;
			std::cout << "S) Skip Turn" << std::endl;
			// prints the options
			for (int i = 0; i < pShip->weapons.size(); i++)
			{
				// If the weapon isn't being used, it's listed as an option.
				if (pShip->weapons.at(i).isAvailable())
				{
					std::cout << i + 1 << ") " << pShip->weapons.at(i).toString() << std::endl;
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

				if (util::Utilities::equalsIgnoreCase(input, "X"))
				{
					std::cout << "Ending the game." << std::endl;
					exit(1);
					break;
				}

				// Skipping the user's turn
				if (util::Utilities::equalsIgnoreCase(input, "S"))
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
				if (index <= 0 || index > pShip->weapons.size())
				{
					std::cout << "No weapon exists with that identification number. Go again." << std::endl;
					input = "";
					continue;
				}
				// Weapon is already charging, or otherwise unavailable
				else if (!pShip->weapons.at(index - 1).isAvailable())
				{
					std::cout << "That option is currently not available." << std::endl;
					input = "";
					continue;
				}

				// starts charging the weapon for use.
				std::cout << "Charging of Weapon #" << input << " (" << pShip->weapons.at(index - 1).getName() << ") has begun!" << std::endl;
				pShip->weapons.at(index - 1).increaseCharge(); // increases the charge by '1'.
				// asking the user what room they want to target
				do
				{
					// Asking the user to target a room.
					std::cout << "\nSelect a room to target: " << std::endl;
					for (int i = 0; i < enemy->areas.size(); i++)
					{
						std::cout << enemy->areas.at(i)->getID();
						if (i != enemy->areas.size() - 1)
							std::cout << ", ";
					}
					std::cout << std::endl;

					std::cout << "Room: ";
					std::getline(std::cin, input);
					
					input = util::Utilities::toUpper(input); // making the input all uppercase.
					pShip->weapons.at(index - 1).setTarget('0');

					for (int i = 0; i < enemy->areas.size(); i++)
					{
						// If the user's input is a valid room that they can target.
						// if (input == std::to_string(enemy->areas.at(i)->getID()))
						if (input[0] == enemy->areas.at(i)->getID())
						{
							pShip->weapons.at(index - 1).setTarget(enemy->areas.at(i)->getID());
							std::cout << "Target Aquired: Room " << pShip->weapons.at(index - 1).getTarget() << "!" << std::endl;
							input = "exit"; // tells the progrma to exit the loop because a valid index has been found
							break;
						}
					}

					// If the room selection failed.
					if (input != "exit")
						std::cout << "That is not a valid room choice." << std::endl;

				} while (input != "exit");

			} while (input == "");
		}

		std::cout << std::endl;
		// charges weapons
		for (int i = 0; i < pShip->weapons.size(); i++)
		{
			// if the weapon is charging, it adds +1 to the charge
			if (pShip->weapons.at(i).isCharging())
			{
				std::cout << pShip->weapons.at(i).getName() << " is Charging. Progress: " << pShip->weapons.at(i).getCharge() << "/" << pShip->weapons.at(i).getChargeTime() << std::endl;
				pShip->weapons.at(i).increaseCharge();
			}
		}
		
		// Enemy Decisions
		// has the enemy pick a weapon to use if possible.
		for (int i = 0; i < enemy->weapons.size(); i++)
		{
			noOptions = enemy->weapons.at(i).isCharging(); // if a 'false' is returned, the weapon isn't charging.
			
			if (noOptions == false) // there are options, so it kepes track of possible options.
			{
				// gets a reference to the weapon.
				availableWeapons.push_back(&enemy->weapons.at(i));
				break;
			}
			// increases weapon charge if it's set to be charged.
			if (enemy->weapons.at(i).isCharging())
			{
				enemy->weapons.at(i).increaseCharge();
			}
		}

		// Chooses a random weapon if one is available.
		if (!availableWeapons.empty()) // sees if there are weapons to choose from
		{
			availableWeapons.at(rand() % availableWeapons.size())->increaseCharge(); // starts charging a random weapon.
			availableWeapons.clear(); // removes all weapons from the 'usable' weapons list.
		}

		strStream.clear(); // clearing the string stream
		
		if(pause)
			std::system("pause"); // something else also uses 'system', so the reference needed to be specified.
		std::system("CLS");
	
	}while (battleLoop == true && enemy->getHull() > 0 && pShip->getHull() > 0);
	
	return false;
}

Ship * Gameplay::createShip(int type)
{
	Ship * tempShip;

	
	switch(type)
	{
		// Returns the player ship
	case 1:
		tempShip = new Ship("Enemy Scout");
		tempShip->setShield(2);
		tempShip->setHull(15);
		tempShip->setMaxHull(tempShip->getHull()); // getting the starting hull value, treating it as the maximum.
		tempShip->setShield(2);
		tempShip->setReactor(8);

		// Adding all of the rooms for the ship (A to F)
		for (int i = 0; i < 7; i++) // making 16 rooms, starting at 'A'.
		{
			tempShip->areas.push_back(new Room(65 + i, 3, "NULL", 1));
		}

		// Adding all the crew members.
		for (int i = 0; i < tempShip->getCrewMembers(); i++) // making three human crew members
		{
			tempShip->addCrewMember("human", 'A');
		}


		tempShip->weapons.push_back(All_Weapons().missile_artemis);
		tempShip->weapons.push_back(All_Weapons().laser_burst_ii);

		tempShip->setOxygen(1);
		tempShip->setShield(2);
		tempShip->setEngineLevel(2);
		tempShip->setFuel(16);
		
		break;

	case 2:
		tempShip = new Ship();
		break;

	// Player Ship
	default:
		// Based on Layout A of the Kestrel
		tempShip = new Ship("The Kestrel"); // the default ship is the player's ship
			// Based on Layout A of the default ship, the Kestrel Cruiser (https://ftl.fandom.com/wiki/The_Kestrel_Cruiser)
		// Layout A
		tempShip->setHull(30);
		tempShip->setMaxHull(tempShip->getHull()); // getting the starting hull value, treating it as the maximum.
		tempShip->setShield(2);
		tempShip->setReactor(8);
		
		// Adding all of the rooms for the Kestrel.
		for (int i = 0; i < 17; i++) // making 16 rooms, starting at 'A' and going to 'P'.
		{
			tempShip->areas.push_back(new Room(65 + i, 0, "NULL", 1));
		}

		// Adding all the crew members.
		for (int i = 0; i < tempShip->getCrewMembers(); i++) // making three human crew members
		{
			tempShip->addCrewMember("human", 'A');
		}


		tempShip->weapons.push_back(All_Weapons().missile_artemis);
		tempShip->weapons.push_back(All_Weapons().laser_burst_ii);

		tempShip->setOxygen(1);
		tempShip->setShield(2);
		tempShip->setEngineLevel(2);
		tempShip->setFuel(16);

		break;
	}

	return tempShip;
}

// Returns the player ship; there should only be one.
Ship * Gameplay::getPlayer() { return pShip; }

// Returns the enemy ship; there should only be one.
Ship * Gameplay::getEnemy() { return enemy; }