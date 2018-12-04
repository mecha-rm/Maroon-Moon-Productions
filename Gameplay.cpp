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
unsigned int Gameplay::battle = 1;
bool Gameplay::playerWins = false;

// player ship and enemy ship
Ship * Gameplay::pShip = new Ship(); // inital values
Ship * Gameplay::enemy = new Ship(); // inital values

Gameplay::Gameplay() 
{
	pShip = createShip(0);
	enemy = createShip(battle);
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

// A '0' or less for the player's rooms, a '1' or more for the enemy's rooms
void Gameplay::printRooms(int object)
{
	if (object <= 0)
	{
		for (int i = 0; i < pShip->areas.size(); i++)
		{
			std::cout << pShip->areas.at(i)->toString() << std::endl;
		}
	}
	else if (object > 0)
	{
		for (int i = 0; i < enemy->areas.size(); i++)
		{
			std::cout << enemy->areas.at(i)->toString() << std::endl;
		}
	}
}

// Gives the user something between battles.
void Gameplay::powerUp()
{
	std::string input("");

	// gets three random weapons.
	Weapon w1 = All_Weapons().getRandomWeapon();
	Weapon w2 = All_Weapons().getRandomWeapon();
	Weapon w3 = All_Weapons().getRandomWeapon();
	// restoring hp
	int hpRestore = rand() % 16 + 5; // 5 to 20
	// inceasing maximum hp
	int hpIncrease = ceil((float)hpRestore / 2.0F); // increasing the maximum hp of the user.
	// rooms
	int rooms = rand() % pShip->areas.size(); // chooses how many rooms to give a shield to
	// A random integer.
	int randInt = 0;

	std::cout << "\nYou have won this round, and are going onto the next round! What would you like to take?" << std::endl;
	do
	{
		// Options
		std::cout << "Select an option using a cooresponding number: " << std::endl;
		std::cout << "1) " << w1.toString() << std::endl;
		std::cout << "2) " << w2.toString() << std::endl;
		std::cout << "3) " << w3.toString() << std::endl;
		std::cout << "4) Restore " << std::to_string(hpRestore) << " HP to the ship." << std::endl;
		std::cout << "5) Increase maximum health by " << std::to_string(hpIncrease) << " , and repair " << std::to_string(hpRestore) << " damage to your ship's hull." << std::endl;
		std::cout << "6) Put shields up in " << rooms << " random room(s)." << std::endl;
		std::cout << "7) I don't need anything." << std::endl;
		std::cout << "8) END GAME" << std::endl;

		std::cout << "\nOption: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		
		// Gives the user weapon 1.
		if (input == "1")
		{
			pShip->weapons.push_back(w1);
			std::cout << "Received " << w1.getName() << "." << std::endl;
		}
		// Gives the user weapon 2.
		else if (input == "2")
		{
			pShip->weapons.push_back(w2);
			std::cout << "Received " << w2.getName() << "." << std::endl;

		}
		// Givs the user weapon 3.
		else if (input == "3")
		{
			pShip->weapons.push_back(w3);
			std::cout << "Received " << w3.getName() << "." << std::endl;

		}
		// Restores health.
		else if (input == "4")
		{
			pShip->setHull(pShip->getHull() + hpRestore);
			std::cout << "Health restored by " << std::to_string(hpIncrease) << ". Your ship's health is now " << std::to_string(pShip->getHull()) << std::endl;
		}
		// Increases max health, and gives some health.
		else if (input == "5")
		{
			pShip->setMaxHull(pShip->getMaxHull() + hpIncrease); // increases the max hull
			pShip->setHull(pShip->getHull() + hpRestore); // restores the current hull
			std::cout << "Your ship's maximum health was raised to " << pShip->getMaxHull() << ", and your ship's current health is now " << pShip->getHull() << "!" << std::endl;
		}
		// Raises shields.
		else if (input == "6")
		{
			for (int i = 1; i <= rooms; i++)
			{
				randInt = rand() % pShip->areas.size();
				pShip->areas.at(randInt)->setShield(pShip->areas.at(randInt)->getShield() + pShip->getShield()); // gives a shield to the random room.
				std::cout << "A shield was raised in area " << std::string(1, pShip->areas.at(randInt)->getID()) << std::endl;
			}
			std::cout << std::endl;
		}
		// Gets nothing.
		else if (input == "7")
		{
			std::cout << "Alright. Let's go on to the next stage then!" << std::endl;
		}
		// Ends the game.
		else if (input == "8")
		{
			std::cout << "Okay. Ending game" << std::endl;
			exit(1);
		}
		else
		{
			std::cout << "Invalid Input. Try Again." << std::endl;
			std::cout << std::endl;
			input = "";
		}
	} while (input == "");
	
}

// Goes on to the next battle
void Gameplay::nextBattle()
{
	battle++;
	enemy = Gameplay().createShip((signed)battle); // setting the new enemy
	Gameplay().powerUp(); // gives the ship a powerup.
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

		std::cout << std::endl;
		std::cout << "PLAYER ROOMS\n--------------" << std::endl;
		printRooms(-1);

		std::cout << std::endl;
		std::cout << "ENEMY ROOMS\n--------------" << std::endl;
		printRooms(1);

		// Fires off any weapons already charged
		for (int i = 0; i < pShip->weapons.size(); i++)
		{
			if (pShip->weapons.at(i).isCharged())
			{
				// This does direct damage to the hull, and needs to be changed.
				// fires the weapon 'x' amount of times based on how many shots there are.
				for (int shot = 1; shot <= pShip->weapons.at(i).getShots(); shot++)
				{
					std::cout << std::endl;
					// Prints a different message based on what type of weapon it is.
					if (util::Utilities::equalsIgnoreCase(pShip->weapons.at(i).getType(), "shield"))
					{
						std::cout << "Barrier " << pShip->weapons.at(i).getName() << " has been activated! " << std::endl;
					}
					else
					{
						std::cout << "Weapon " << pShip->weapons.at(i).getName() << " has been fired! " << std::endl;
					}


					// If the weapon's accuracy is less than what the randomizer gets, the weapon misses.
					if (pShip->weapons.at(i).getAccuracy() < rand() % 10 + 1)
					{
						std::cout << "The " << pShip->weapons.at(i).getName() << " failed! " << std::endl;
						pShip->weapons.at(i).setCharge(0);
						continue;
					}

					
					// If the weapon is a shield
					if (util::Utilities::equalsIgnoreCase(pShip->weapons.at(i).getType(), "shield"))
					{
						randInt = rand() % pShip->areas.size(); // picks a random room
						pShip->areas.at(randInt)->setShield(pShip->areas.at(randInt)->getShield() + pShip->getShield()); // adds to the room's current shield.
						std::cout << "A shield was raised in room " << pShip->areas.at(randInt)->getID() << "! It now has a shield value of " << pShip->areas.at(randInt)->getShield() << std::endl;
						pShip->weapons.at(i).setCharge(0);

						continue; // goes back to the start of the loop, since it won't be using anything below.
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
								std::cout << std::to_string(pShip->weapons.at(i).getHullDam() * multiply) << " damage has been done to the hull!" << std::endl;
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

		// std::cout << std::endl;

		// Fires off enenmy weapons that are charged
		for (int i = 0; i < enemy->weapons.size(); i++)
		{
			if (enemy->weapons.at(i).isCharged())
			{
				for (int shot = 1; shot <= enemy->weapons.at(i).getShots(); shot++)
				{
					std::cout << "The enemy has used " << enemy->weapons.at(i).getName() << "!" << std::endl;
					
					randInt = rand() % pShip->areas.size(); // gets a random room

					if (util::Utilities::equalsIgnoreCase(enemy->weapons.at(i).getType(), "shield")) // the enemy used a shield.
					{
						randInt = rand() % enemy->areas.size(); // chooses a random room to raise the shield in.
						enemy->areas.at(randInt)->setShield(enemy->areas.at(randInt)->getShield() + enemy->getShield()); // adds to the enemy's shield.
						std::cout << "The enemy has risen a shield in Room " << std::string(1, enemy->areas.at(randInt)->getID()) << "! It now has a value of " << std::to_string(enemy->areas.at(randInt)->getShield()) << std::endl;
					}
					else if (pShip->areas.at(randInt)->getShield() > 0) // If a shield is up.
					{
						pShip->areas.at(randInt)->setShield(pShip->areas.at(randInt)->getShield() - enemy->weapons.at(i).getShieldDam()); // damanges the player's shield.
						std::cout << "It hit the shield in area " << std::string(1, pShip->areas.at(randInt)->getID()) << "! It now has a value of " << pShip->areas.at(randInt)->getShield() << ".";
					}
					else if (pShip->areas.at(randInt)->getShield() <= 0)
					{
						pShip->setHull(pShip->getHull() - enemy->weapons.at(i).getHullDam()); // damanging the player
						std::cout << "The enemy hit the hull of the ship for " << enemy->weapons.at(i).getHullDam() << " damage!" << std::endl;
					}
					

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

			std::cout << "X) Exit Game\n---------------------------" << std::endl;
			std::cout << "S) Skip Turn\n---------------------------" << std::endl;
			// prints the options
			for (int i = 0; i < pShip->weapons.size(); i++)
			{
				// If the weapon isn't being used, it's listed as an option.
				if (pShip->weapons.at(i).isAvailable())
				{
					std::cout << i + 1 << ") " << pShip->weapons.at(i).toString() << std::endl;
					std::cout << "---------------------------" << std::endl;
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

				pShip->weapons.at(index - 1).increaseCharge(); // increases the charge by '1'.
				// starts charging the weapon for use.
				std::cout << "Charging of Weapon #" << input << " (" << pShip->weapons.at(index - 1).getName() << ") has begun!" << std::endl;
				
				// If the weapon is a shield
				if (util::Utilities::equalsIgnoreCase(pShip->weapons.at(index - 1).getType(), "shield"))
				{
					pShip->weapons.at(index - 1).setTarget('A');
					continue;
				}
					

				// asking the user what room they want to target. Since the shield activates over a random room, those don't ask for the room to target.
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
			// randInt = rand() % availableWeapons.size(); // gets a random value
			// availableWeapons.at(randInt)->setTarget(pShip->areas.at(rand() % pShip->areas.size())->getID()); // chooses a random room to target.
			availableWeapons.at(rand() % availableWeapons.size())->increaseCharge(); // starts charging a random weapon.
			
			availableWeapons.clear(); // removes all weapons from the 'usable' weapons list.
		}

		strStream.clear(); // clearing the string stream
		
		if(pause)
			std::system("pause"); // something else also uses 'system', so the reference needed to be specified.
		std::system("CLS");
	
	}while (battleLoop == true && enemy->getHull() > 0 && pShip->getHull() > 0);

	// Returns 'true' if one of the ships are dead
	if (enemy->getHull() <= 0 || pShip->getHull() <= 0)
	{
		if (pShip->getHull() <= 0) // if the player has lost
		{
			setPlayerWins(false);
		}
		else if (enemy->getHull() <= 0) // the enemy has lost.
		{
			setPlayerWins(true);
		}
		return true; // the player won the fight.
	}
	// setPlayerWins(true);
	return false; // the player 
}

// Gets whether or not the game is being played.
bool Gameplay::getPlay() { return play; }

// Sets play to 'true' or 'false' based on what's provided.
void Gameplay::setPlay(bool playGame) { play = playGame; }

// Gets the battle number
unsigned int Gameplay::getBattle() { return battle; }

// Sets the battle number
void Gameplay::setBattle(unsigned int battle) { this->battle = battle; }

// Returns the player ship; there should only be one.
Ship * Gameplay::getPlayer() { return pShip; }

// Determines whether the player has o
bool Gameplay::getPlayerWins() { return playerWins; }

void Gameplay::setPlayerWins(bool pWins) { playerWins = pWins; }

// Returns the enemy ship; there should only be one.
Ship * Gameplay::getEnemy() { return enemy; }



// Creates a ship
Ship * Gameplay::createShip(int type)
{
	Ship * tempShip;


	switch (type)
	{
	// Returns the player ship
	case 0:
		// Based on Layout A of the Kestrel
		tempShip = new Ship("The Kestrel"); // the default ship is the player's ship
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Kestrel Labeled (with Doors).png");
			// Based on Layout A of the default ship, the Kestrel Cruiser (https://ftl.fandom.com/wiki/The_Kestrel_Cruiser)
		// Layout A
		tempShip->setMaxHull(40); // getting the maximum hull value
		tempShip->setHull(tempShip->getMaxHull());
		tempShip->setShield(2);
		// tempShip->setReactor(8);
		// tempShip->setOxygen(1);
		// tempShip->setEngineLevel(2);
		// tempShip->setFuel(16);

		// Adding all of the rooms for the Kestrel.
		for (int i = 0; i < 18; i++) // making 18 rooms, starting at 'A' and going to 'R'.
		{
			tempShip->areas.push_back(new Room(65 + i, 0, "NULL", 1));
		}

		tempShip->setRooms(tempShip->areas.size()); // getting the number of rooms

		tempShip->weapons.push_back(All_Weapons().missile_artemis); // starting missle
		tempShip->weapons.push_back(All_Weapons().shield_basic); // starting shield
		tempShip->weapons.push_back(All_Weapons().laser_burst_ii); // starting laser
		tempShip->weapons.push_back(All_Weapons().bomb_small); // starting laser

		break;
	// Enemy Ship 1
	case 1:
		tempShip = new Ship("Enemy Scout Type 1");
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Enemy-Scout Labeled.png"); // sets the image path of the ship
		tempShip->setShield(2);
		tempShip->setHull(15);
		tempShip->setMaxHull(tempShip->getHull()); // getting the starting hull value, treating it as the maximum.
		tempShip->setShield(1);
		// tempShip->setReactor(8);

		// tempShip->setOxygen(1);
		// tempShip->setEngineLevel(2);
		// tempShip->setFuel(16);

		// Adding all of the rooms for the ship (A to G)
		for (int i = 0; i < 6; i++) // making 16 rooms, starting at 'A' and ending at 'F'.
		{
			tempShip->areas.push_back(new Room(65 + i, 0, "NULL", 1));
		}
		/*
		// Adding all the crew members.
		for (int i = 0; i < tempShip->getCrewMembers(); i++) // making three human crew members
		{
			tempShip->addCrewMember("human", 'A');
		}
		*/

		// Giving the enemy ship weaons
		tempShip->weapons.push_back(All_Weapons().missile_artemis);
		tempShip->weapons.push_back(All_Weapons().laser_burst_i);
		tempShip->weapons.push_back(All_Weapons().shield_basic);


		break;

	case 2:
		tempShip = new Ship("Enemy Scout Type 2");
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Enemy-Scout T-02.png"); // sets the image path of the ship
		tempShip->setShield(2);
		tempShip->setMaxHull(20); // getting the maximum hull value
		tempShip->setHull(tempShip->getMaxHull());
		tempShip->setShield(1);

		for (int i = 0; i < 6; i++) // making 16 rooms, starting at 'A' and ending at 'F'.
		{
			tempShip->areas.push_back(new Room(65 + i, tempShip->getShield(), "NULL", 1));
		}

		
		tempShip->weapons.push_back(All_Weapons().missle_breach);
		tempShip->weapons.push_back(All_Weapons().laser_burst_ii);
		tempShip->weapons.push_back(All_Weapons().shield_alpha);
		break;

	case 3:
		tempShip = new Ship("Enemy Scout Type 3");
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Enemy-Scout T-03.png"); // sets the image path of the ship
		tempShip->setShield(1);
		tempShip->setMaxHull(25); // getting the maximum hull value
		tempShip->setHull(tempShip->getMaxHull());

		for (int i = 0; i < 6; i++) // making 16 rooms, starting at 'A' and ending at 'F'.
		{
			tempShip->areas.push_back(new Room(65 + i, rand() % 3, "NULL", 1));
		}


		tempShip->weapons.push_back(All_Weapons().missle_hermes);
		tempShip->weapons.push_back(All_Weapons().laser_dual);
		tempShip->weapons.push_back(All_Weapons().shield_beta);
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon()); // gives the ship one random weapon
		break;
	case 4:
		tempShip = new Ship("Enemy Scout Type 4");
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Enemy-Scout T-04.png"); // sets the image path of the ship
		tempShip->setShield(2);
		tempShip->setMaxHull(20); // getting the maximum hull value
		tempShip->setHull(tempShip->getMaxHull());

		for (int i = 0; i < 6; i++) // making 16 rooms, starting at 'A' and ending at 'F'.
		{
			tempShip->areas.push_back(new Room(65 + i, rand() % 3, "NULL", 1));
		}


		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon()); // gives the ship one random weapon
		break;

	case 5:
		tempShip = new Ship("Enemy Scout Type 5");
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Enemy-Scout T-05.png"); // sets the image path of the ship
		tempShip->setShield(3);
		tempShip->setMaxHull(10); // getting the maximum hull value
		tempShip->setHull(tempShip->getMaxHull());

		for (int i = 0; i < 6; i++) // making 16 rooms, starting at 'A' and ending at 'F'.
		{
			tempShip->areas.push_back(new Room(65 + i, rand() % 3 + 3, "NULL", 1));
		}


		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon()); // gives the ship one random weapon
		break;
	case 6:
		tempShip = new Ship("Enemy Scout Type 6");
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Enemy-Scout T-06.png"); // sets the image path of the ship
		tempShip->setShield(2);
		tempShip->setMaxHull(25); // getting the maximum hull value
		tempShip->setHull(tempShip->getMaxHull());

		for (int i = 0; i < 6; i++) // making 16 rooms, starting at 'A' and ending at 'F'.
		{
			tempShip->areas.push_back(new Room(65 + i, tempShip->getShield(), "NULL", 1));
		}


		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon()); // gives the ship one random weapon
		break;
	case 7:
		tempShip = new Ship("Enemy Scout Type 7");
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Enemy-Scout T-07.png"); // sets the image path of the ship
		tempShip->setShield(5);
		tempShip->setMaxHull(30); // getting the maximum hull value
		tempShip->setHull(tempShip->getMaxHull());

		for (int i = 0; i < 6; i++) // making 16 rooms, starting at 'A' and ending at 'F'.
		{
			tempShip->areas.push_back(new Room(65 + i, tempShip->getShield(), "NULL", 1));
		}

		tempShip->weapons.push_back(All_Weapons().laser_burst_i);
		tempShip->weapons.push_back(All_Weapons().shield_gambit);
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon()); // gives the ship one random weapon
		break;
	case 8:
		tempShip = new Ship("Enemy Scout Type 8");
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Enemy-Scout T-08.png"); // sets the image path of the ship
		tempShip->setShield(1);
		tempShip->setHull(25);
		tempShip->setMaxHull(tempShip->getHull()); // getting the starting hull value, treating it as the maximum.

		for (int i = 0; i < 6; i++) // making 16 rooms, starting at 'A' and ending at 'F'.
		{
			tempShip->areas.push_back(new Room(65 + i, tempShip->getShield(), "NULL", 1));
		}


		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon()); // gives the ship one random weapon
		break;
	case 9:
		tempShip = new Ship("Enemy Scout Type 9");
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Enemy-Scout T-09.png"); // sets the image path of the ship
		tempShip->setShield(3);
		tempShip->setMaxHull(20); // getting the maximum hull value
		tempShip->setHull(tempShip->getMaxHull());
		tempShip->setShield(1);

		for (int i = 0; i < 6; i++) // making 16 rooms, starting at 'A' and ending at 'F'.
		{
			tempShip->areas.push_back(new Room(65 + i, tempShip->getShield(), "NULL", 1));
		}

		tempShip->weapons.push_back(All_Weapons().laser_dual); // laser
		tempShip->weapons.push_back(All_Weapons().bomb_small); // laser
		tempShip->weapons.push_back(All_Weapons().shield_gambit);
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon()); // gives the ship one random weapon
		break;

	// The final boss; also serves as default.
	case 10:
	default:
		// Based on Layout A of the Kestrel
		tempShip = new Ship("Kestrel MKII"); // the default ship is the player's ship
		tempShip->setImagePath("images/ImgDmp/GDW3-FTL-Kestrel -Final Boss Labeled (with Doors) (Small).png");

		// Based on Layout A of the default ship, the Kestrel Cruiser (https://ftl.fandom.com/wiki/The_Kestrel_Cruiser)
		// Layout A
		tempShip->setMaxHull(45); // getting the maximum hull value
		tempShip->setHull(tempShip->getMaxHull());
		tempShip->setShield(3);
		tempShip->setReactor(8);

		// Adding all of the rooms for the Kestrel.
		for (int i = 0; i < 18; i++) // making 18 rooms, starting at 'A' and going to 'R'.
		{
			tempShip->areas.push_back(new Room(65 + i, 0, "NULL", 1));
		}

		tempShip->weapons.push_back(All_Weapons().laser_burst_ii); // laser
		tempShip->weapons.push_back(All_Weapons().missile_artemis); // missle
		tempShip->weapons.push_back(All_Weapons().shield_omega); // shield
		tempShip->weapons.push_back(All_Weapons().bomb_crystal_lock); // bomb

		// Gets 5 random weapons
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		tempShip->weapons.push_back(All_Weapons().getRandomWeapon());
		
		break;
	}

	return tempShip;
}