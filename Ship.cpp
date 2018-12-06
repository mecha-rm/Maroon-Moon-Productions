// Class used for creating ship objects
#include <iostream>
#include <windows.h>

#include "Utilities.h"
#include "Ship.h"
#include "Weapon.h"
#include "CrewMember.h"
#include "All_Weapons.h"

// constructors
// default constructor; the ship is named 'Ship" by default
Ship::Ship() : Ship("Ship") {}

// set the ship's name; other value initalization in Gameplay::createShip()
Ship::Ship(std::string name) : shipName(name) {}

//Setters 
void Ship::setImagePath(std::string imagePath) { this->imagePath = imagePath; } // the image path for the ship

void Ship::setHull(int hull)  // the ship's hull (hp)
{
	// For the hull would be put above its max, it is set to its max value. If not, its set to the value provided.
	(hull > maxHull) ? this->hull = maxHull : this->hull = hull;
}

void Ship::setMaxHull(int maxHull) { this->maxHull = maxHull; } // max health
void Ship::setShield(int shield) { this->shield = shield; } // ship's shield
void Ship::setShieldMax(int shieldMax) { this->shieldMax = shieldMax; } // maximum amount a shield can cover a room for (UNUSED)
void Ship::setReactor(int reactor) { this->reactor = reactor; } // powers weapons (UNUSED)
void Ship::setEvade(int evade) { this->evade = evade; } // ship's evasion stats (UNUSED)
void Ship::setOxygen(int oxygen) { this->oxygen = oxygen; } // ship's oxygen levels (UNUSED)
void Ship::setScrap(int scrap) { this->scrap = scrap; } // ship's amount of scrap (currency) (UNUSED)
void Ship::setFTLDrive(int ftlDrive) { this->ftlDrive = ftlDrive; } // the ship's drive used for transportation (UNUSED)
void Ship::setFuel(int fuel) { this->fuel = fuel; } // the ship's amount of fuel (UNUSED)

void Ship::setShieldLevel(int shieldLevel) { this->shieldLevel = shieldLevel; } // the level of the ship's shield (UNUSED)
void Ship::setEngineLevel(int engineLevel) { this->engineLevel = engineLevel; } // the ship's engine levels (UNUSED)
void Ship::setOxygenLevel(int oxygenLevel) { this->oxygenLevel = oxygenLevel; } // the ship's oxygen level (UNUSED)
void Ship::setWeaponControlLevel(int weaponControlLevel) { this->weaponControlLevel = weaponControlLevel; } // the weapon control system (UNUSED)
void Ship::setMedbayLevel(int medbayLevel) { this->medbayLevel = medbayLevel; } // the medbay level of the ship
void Ship::setPilotLevel(int pilotLevel) { this->pilotLevel = pilotLevel; } // the level of the piloting system (UNUSED) (UNUSED)
void Ship::setSensorLevel(int sensorLevel) { this->sensorLevel = sensorLevel; } // the sensors of the ship (UNUSED)
void Ship::setDoorLevel(int doorLevel) { this->doorLevel = doorLevel; } // the door level of the ship (UNUSED)
void Ship::setRooms(int rooms) { this->rooms = rooms; } // the amount of rooms a ship has
void Ship::setCrew(std::vector<CrewMember> crew) { this->crew = crew; } // the crew of the ship (UNUSED)
void Ship::setSensor(bool sensor) { this->sensor = sensor; } // the sensors on the ship (UNUSED)

//Getters; see setters or Ship.h for description
std::string Ship::getName() { return shipName; }
std::string Ship::getImagePath() { return imagePath; }
int Ship::getHull() { return hull; }

int Ship::getMaxHull() { return maxHull; }
int Ship::getShield() { return shield; }
int Ship::getShieldMax() { return shieldMax; } // (UNUSED)
int Ship::getReactor() { return reactor; } // (UNUSED)
int Ship::getEvade() { return evade; } // (UNUSED)
int Ship::getOxygen() { return oxygen; } // (UNUSED)
int Ship::getCrewMembers() { return crewMembers; } // (UNUSED)
int Ship::getScrap() { return scrap; } // (UNUSED)
int Ship::getFTLDrive() { return ftlDrive; } // (UNUSED)
int Ship::getFuel() { return fuel; } // (UNUSED)
int Ship::getShieldLevel() { return shieldLevel; } // (UNUSED)
int Ship::getEngineLevel() { return engineLevel; } // (UNUSED)
int Ship::getOxygenLevel() { return oxygenLevel; } // (UNUSED)
int Ship::getWeaponControlLevel() { return weaponControlLevel; } // (UNUSED)
int Ship::getMedbayLevel() { return medbayLevel; } // (UNUSED)
int Ship::getPilotLevel() { return pilotLevel; } // (UNUSED)
int Ship::getSensorLevel() { return sensorLevel; } // (UNUSED)
int Ship::getDoorLevel() { return doorLevel; } // (UNUSED)
int Ship::getRooms() { return rooms; }
bool Ship::getSensor() { return sensor; } // (UNUSED)

// gets a crew member at the provided index
CrewMember Ship::getCrewMember(unsigned int i) // returns the crew member at the provided index
{
	if (i > crew.size()) // if it would cause an out-of-bounds exception
	{
		return crew.at(i);
	}
	else
	{
		return CrewMember(); // returns a default crew member otherwise.
	}
}

std::vector<CrewMember> Ship::getCrew() { return crew; } // (UNUSED)

// adds a crew member; make sure all letters are lowercase (UNUSED)
void Ship::addCrewMember(std::string species, char room)
{
	// Makes the species name lowercase for string checking.
	species = util::Utilities::toLower(species);
	
	// This was originally setup to add differnet crew members based on what species was given. However, it only adds 'humans', since that's all we made by the project's end.
	// Making a human crew member
	if (species == "human" || species == "h")
	{
		crew.push_back(CrewMember("Human", room));

	}
	else
	{
		crew.push_back(CrewMember("Human", room));
	}
	
	
	crewMembers++;
}

/*
// removes a crew member at the provided index
bool Ship::removeCrewMember(unsigned int index)
{
	// returns 'false' if the index is invalid, or if there are no crew members
	if (crew.empty() == false && index < crew.size())
	{
		crew.erase(crew.begin() + index);
		return true;
	}
	else
	{
		return false;
	}
}
*/

// returns a weapon at a given index.
Weapon Ship::getWeapon(unsigned int index)
{
	// Checks to see if the index is valid.
	if (index >= weapons.size() || weapons.empty())
	{
		return weapons.at(index);
	}
}

// returns all weapons in a vector
std::vector<Weapon> Ship::getWeapons() { return weapons; }

// add a weapon to the vector
void Ship::addWeapon(Weapon weapon) { weapons.push_back(weapon); }

// sets the weapons on the ship 
void Ship::setWeapons(std::vector<Weapon> newWeapons) 
{ 
	weapons.clear();
	for (int i = 0; i < newWeapons.size(); i++)
	{
		weapons.push_back(newWeapons.at(i));
	}
}

// remove the last weapon in the weapon vector
void Ship::removeWeapon() 
{ 
	if (!weapons.empty()) // if the vector isn't empty, the weapon at the back of the stack is removed.
		weapons.pop_back();
}

// remove a weapon with a provided index
void Ship::removeWeapon(unsigned int index)
{
	// using vector.erase() caused an error, so while this is less efficient, it's the best we could do in our time frame.
	std::vector<Weapon> tempVec;

	// puts the weapons into the tempVec.
	for (int i = 0; i < weapons.size(); i++)
	{
		// If it's the index to be deleted, this weapon is skipped.
		if (i != index)
			tempVec.push_back(weapons.at(i));
	}
	
	weapons.clear();
	for (int i = 0; i < tempVec.size(); i++) // puts all of the weapons back onto the now cleared weapons stack, without the weapon that the user wanted to remove.
	{
		weapons.push_back(tempVec.at(i));
	}
}

// applies damage to the shield before the health of the ship; this is incomplete and unused.
void Ship::shieldToHealth(int damage) {
	// Commented out because it may have not been complete.
	/*
	for (int count = damage; count > 0; count--) {

		if (weapon.getDamageType() == "missile") {//is the weapon(initalized above) is a laser
			if (getHull() > 0) {				//could change it to Physical/NonPhysical damage instead of names of weapons
				setHull(getHull() - 1);
			}
		}
		if (weapon.getDamageType() == "laser") {
			if (getShield() > 0) {
				setShield(getShield() - 1);
			}
			else {
				setHull(getHull() - 1);

				if (weapon.getRoomHit() == crewMember.getPosition()) {//crewMember is a crewMemeber object i made above
					crewMember.setHealth(crewMember.getHealth() - 1);//this just means that when the hull takes damage at a room that has a crew member in it the crew member will take the same amount of damage.
				}													 //if we change all out ints to floats we can get like a ratio of 1 hull damage to 0.2 crew member damage.
			}
		}
	}
	*/
}


//---- Below is used for mapping
// Matches a room with the provided string if possible. If it finds a match, the index in arr2 is returned. (UNUSED)
string Ship::roomType(string str) {

	const int length = 1;
	string arr1[length] = { "e" };
	string arr2[length] = { " " };

	for (int x = 0; x < length; x++) {
		if (str == arr1[x]) {
			return arr2[x];
		}
	}

	return "ERR: no match";
}

// moves the crew member from one space to another. (UNUSED)
void Ship::crewMove() {
	for (int x = 0; x < crew.size(); x++) {

		if (!crew[x].nextMove.empty()) {
			flipMap[crew[x].getCurrent().Y][crew[x].getCurrent().X] = flipMap[crew[x].getCurrent().Y][crew[x].getCurrent().X].substr(0, 4) + "e";
			crew[x].setCurrent(crew[x].getCurrent().X + crew[x].nextMove.back().X, crew[x].getCurrent().Y + crew[x].nextMove.back().Y);
			crew[x].nextMove.pop_back();
			flipMap[crew[x].getCurrent().Y][crew[x].getCurrent().X] = flipMap[crew[x].getCurrent().Y][crew[x].getCurrent().X].substr(0, 4) + "c";
		}
	}
}

// has the crew member look and see if a path is a viable option. (UNUSED)
bool Ship::pathfind(int num) {

	for (int x = 0; x < shipMapWidth; x++) {
		for (int y = 0; y < shipMapLength; y++) {
			dynamicMap[x][y] = true;
		}
	}

	return pathfindRec(0, crew[num].getCurrent().X, crew[num].getCurrent().Y, 0);
}

// Uses the array that sets up the walls, doors, etc. for the ship to help the crew member know where they can and can't go. (UNUSED)
bool Ship::pathfindRec(int num, int x, int y, int level) {
	if (crew[num].getDestination().X != x || crew[num].getDestination().Y != y) {
		if (flipMap[y][x] != "empty" && flipMap[y][x] != "block") {

			if (x >= 0 && dynamicMap[y][x - 1] && flipMap[y][x - 1] != "empty" && flipMap[y][x - 1] != "block") {
				if ((flipMap[y][x].substr(0, 1) == "n" || flipMap[y][x].substr(0, 1) == "o" || flipMap[y][x].substr(0, 1) == "d")) {
					dynamicMap[y][x] = false;
					if (pathfindRec(num, x - 1, y, level + 1)) {
						COORD c; c.X = -1; c.Y = 0;
						crew[num].nextMove.push_back(c);
						return true;
					}
					else dynamicMap[y][x] = true;
				}
			}
			if (y < shipMapWidth && dynamicMap[y + 1][x] && flipMap[y + 1][x] != "empty" && flipMap[y + 1][x] != "block") {
				if ((flipMap[y][x].substr(1, 1) == "n" || flipMap[y][x].substr(1, 1) == "o" || flipMap[y][x].substr(1, 1) == "d")) {
					dynamicMap[y][x] = false;
					if (pathfindRec(num, x, y + 1, level + 1)) {
						COORD c; c.X = 0; c.Y = 1;
						crew[num].nextMove.push_back(c);
						return true;
					}
					else dynamicMap[y][x] = true;

				}
			}
			if (x < shipMapLength && dynamicMap[y][x + 1] && flipMap[y][x + 1] != "empty" && flipMap[y][x + 1] != "block") {
				if ((flipMap[y][x].substr(2, 1) == "n" || flipMap[y][x].substr(2, 1) == "o" || flipMap[y][x].substr(2, 1) == "d")) {
					dynamicMap[y][x] = false;
					if (pathfindRec(num, x + 1, y, level + 1)) {
						COORD c; c.X = 1; c.Y = 0;
						crew[num].nextMove.push_back(c);
						return true;
					}
					else dynamicMap[y][x] = true;
				}
			}
			if (y >= 0 && dynamicMap[y - 1][x] && flipMap[y - 1][x] != "empty" && flipMap[y - 1][x] != "block") {
				if ((flipMap[y][x].substr(3, 1) == "n" || flipMap[y][x].substr(3, 1) == "o" || flipMap[y][x].substr(3, 1) == "d")) {
					dynamicMap[y][x] = false;
					if (pathfindRec(num, x, y - 1, level + 1)) {
						COORD c; c.X = 0; c.Y = -1;
						crew[num].nextMove.push_back(c);
						return true;
					}
				}
			}
		}
	}
	else return true;

	return false;
}

// Prints the ship in text form (UNUSED)
void Ship::printShip() {
	int count = 5;

	for (int x = 0; x < shipMapWidth; x++) {
		for (int z = 0; z < count; z++) {
			for (int y = 0; y < shipMapLength; y++) {
				if (shipMap[x][y] == "empty") {
					cout << "         ";
				}
				else if (shipMap[x][y] == "block") {
					cout << "[][]|[][]";
				}
				else {
					if (z == 0) {

						if (shipMap[x][y].substr(1, 1) == "d") {
							std::cout << "|--#-#--|";
						}
						else if (shipMap[x][y].substr(1, 1) == "o") {
							std::cout << "|--# #--|";
						}
						else if (shipMap[x][y].substr(1, 1) == "w") {
							std::cout << "|-------|";
						}
						else if (shipMap[x][y].substr(1, 1) == "n") {
							std::cout << "|       |";
						}

					}
					else if (z == 1 || z == 3) { //-----------------------------------------------------------------------------------------------------------------------------

						if ((shipMap[x][y].substr(0, 1) == "d" || shipMap[x][y].substr(0, 1) == "o") && (shipMap[x][y].substr(2, 1) == "d" || shipMap[x][y].substr(2, 1) == "o")) {
							std::cout << "#       #";
						}
						else if ((shipMap[x][y].substr(0, 1) == "d" || shipMap[x][y].substr(0, 1) == "o") && shipMap[x][y].substr(2, 1) == "w") {
							std::cout << "#       |";
						}
						else if ((shipMap[x][y].substr(0, 1) == "d" || shipMap[x][y].substr(0, 1) == "o") && shipMap[x][y].substr(2, 1) == "n") {
							std::cout << "#        ";
						}

						else if ((shipMap[x][y].substr(0, 1) == "w" && shipMap[x][y].substr(2, 1) == "d") || shipMap[x][y].substr(2, 1) == "o") {
							std::cout << "|       #";
						}
						else if (shipMap[x][y].substr(0, 1) == "w" && shipMap[x][y].substr(2, 1) == "w") {
							std::cout << "|       |";
						}
						else if (shipMap[x][y].substr(0, 1) == "w" && shipMap[x][y].substr(2, 1) == "n") {
							std::cout << "|        ";
						}

						else if ((shipMap[x][y].substr(0, 1) == "n" && shipMap[x][y].substr(2, 1) == "d") || shipMap[x][y].substr(2, 1) == "o") {
							std::cout << "        #";
						}
						else if (shipMap[x][y].substr(0, 1) == "n" && shipMap[x][y].substr(2, 1) == "w") {
							std::cout << "        |";
						}
						else if (shipMap[x][y].substr(0, 1) == "n" && shipMap[x][y].substr(2, 1) == "n") {
							std::cout << "         ";
						}

					}//----------------------------------------------------------------------------------------------------------------------------------------------------------
					else if (z == 2) {

						string s = shipMap[x][y].substr(4, 1);
						string temp = " ";
						if ((shipMap[x][y].substr(0, 1) == "d" || shipMap[x][y].substr(0, 1) == "w") && (shipMap[x][y].substr(2, 1) == "d" || shipMap[x][y].substr(2, 1) == "w")) {
							temp = "|   " + roomType(s) + "   |";
						}
						else if ((shipMap[x][y].substr(0, 1) == "d" || shipMap[x][y].substr(0, 1) == "w") && (shipMap[x][y].substr(2, 1) == "o" || shipMap[x][y].substr(2, 1) == "n")) {
							temp = "|   " + roomType(s) + "    ";
						}
						else if ((shipMap[x][y].substr(0, 1) == "o" || shipMap[x][y].substr(0, 1) == "n") && (shipMap[x][y].substr(2, 1) == "d" || shipMap[x][y].substr(2, 1) == "w")) {
							temp = "    " + roomType(s) + "   |";
						}
						else if ((shipMap[x][y].substr(0, 1) == "o" || shipMap[x][y].substr(0, 1) == "n") && (shipMap[x][y].substr(2, 1) == "o" || shipMap[x][y].substr(2, 1) == "n")) {
							temp = "    " + roomType(s) + "    ";
						}


						printf("%s", temp.c_str());
					}//-----------------------------------------------------------------------------------------------------------------------------------------------------------
					else if (z == count - 1) {
						if (shipMap[x][y].substr(3, 1) == "d") {
							std::cout << "|--#-#--|";
						}
						else if (shipMap[x][y].substr(3, 1) == "o") {
							std::cout << "|--# #--|";
						}
						else if (shipMap[x][y].substr(3, 1) == "w") {
							std::cout << "|-------|";
						}
						else if (shipMap[x][y].substr(3, 1) == "n") {
							std::cout << "|       |";
						}
					}
				}
			}

			cout << endl;
		}
	}
}

// Prints the health of the ship in a health bar format. (UNUSED)
void Ship::printStats() { std::cout << getHealthBar() << std::endl; }

// Gets a health bar for the ship.
std::string Ship::getHealthBar()
{
	std::string tempStr = "";
	for (int i = 0; i < maxHull; i++)
		i < hull ? tempStr += "/" : tempStr += " "; // prints a '/' for hit points, and a blank space for used up hit points

	tempStr = "(" + std::to_string(hull) + "/" + std::to_string(maxHull) + ") [" + tempStr + "]"; // adds a boarder around the health bar, as well as brackets to show the specific number of health.
	return tempStr;
}
// Ship toString - prints the name, hull of the ship, and its shield
std::string Ship::toString()
{
	std::string str = "";
	str += "Name: " + shipName + ", HULL(HP): " + std::to_string(getHull()) + ", Shield: " + std::to_string(getShield());
	return str;
}