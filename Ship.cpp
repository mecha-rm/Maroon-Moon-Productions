#include <iostream>
#include "Utilities.h"
#include "Ship.h"
#include "Weapon.h"
#include "CrewMember.h"
#include "All_Weapons.h"


// Weapon weapon(missile_test);
// CrewMember crewMember = CrewMember("human");

// constructors
// default constructor; the ship is named 'The Kestrel' by default
Ship::Ship() : Ship("The Kestrel") {}

// set the ship's name
Ship::Ship(std::string name) : shipName(name)
{
	// Based on Layout A of the default ship, the Kestrel Cruiser (https://ftl.fandom.com/wiki/The_Kestrel_Cruiser)
	// Layout A
	setHull(30);
	maxHull = hull; // getting the starting hull value, treating it as the maximum.
	setShield(2);
	setReactor(8);

	for (int i = 0; i < crewMembers; i++) // making three human crew members
	{
		addCrewMember("human", 'A');
	}
		

	weapons.push_back(All_Weapons().missile_artemis);
	weapons.push_back(All_Weapons().laser_burst_ii);

	setOxygen(1);
	setShield(2);
	setEngineLevel(2);
	setFuel(16);

}


/*
Ship::Ship(Ship & ship) : shipMapWidth(6), shipMapLength(15)
{
	*this = ship;
}
*/

//Setters 
void Ship::setHull(int hull) { this->hull = hull; }
void Ship::setShield(int shield) { this->shield = shield; }
void Ship::setReactor(int reactor) { this->reactor = reactor; }
void Ship::setEvade(int evade) { this->evade = evade; }
void Ship::setOxygen(int oxygen) { this->oxygen = oxygen; }
//void Ship::setCrewMembers(int crewMembers) { this->crewMembers = crewMembers; }
void Ship::setScrap(int scrap) { this->scrap = scrap; }
void Ship::setFTLDrive(int ftlDrive) { this->ftlDrive = ftlDrive; }
void Ship::setFuel(int fuel) { this->fuel = fuel; }
void Ship::setShieldLevel(int shieldLevel) { this->shieldLevel = shieldLevel; }
void Ship::setEngineLevel(int engineLevel) { this->engineLevel = engineLevel; }
void Ship::setOxygenLevel(int oxygenLevel) { this->oxygenLevel = oxygenLevel; }
void Ship::setWeaponControlLevel(int weaponControlLevel) { this->weaponControlLevel = weaponControlLevel; }
void Ship::setMedbayLevel(int medbayLevel) { this->medbayLevel = medbayLevel; }
void Ship::setPilotLevel(int pilotLevel) { this->pilotLevel = pilotLevel; }
void Ship::setSensorLevel(int sensorLevel) { this->sensorLevel = sensorLevel; }
void Ship::setDoorLevel(int doorLevel) { this->doorLevel = doorLevel; }
void Ship::setRooms(int rooms) { this->rooms = rooms; }
void Ship::setCrew(std::vector<CrewMember> crew) { this->crew = crew; }
void Ship::setSensor(bool sensor) { this->sensor = sensor; }

//Getters
std::string Ship::getName() { return shipName; }
int Ship::getHull() { return hull; }
int Ship::getShield() { return shield; }
int Ship::getReactor() { return reactor; }
int Ship::getEvade() { return evade; }
int Ship::getOxygen() { return oxygen; }
int Ship::getCrewMembers() { return crewMembers; }
int Ship::getScrap() { return scrap; }
int Ship::getFTLDrive() { return ftlDrive; }
int Ship::getFuel() { return fuel; }
int Ship::getShieldLevel() { return shieldLevel; }
int Ship::getEngineLevel() { return engineLevel; }
int Ship::getOxygenLevel() { return oxygenLevel; }
int Ship::getWeaponControlLevel() { return weaponControlLevel; }
int Ship::getMedbayLevel() { return medbayLevel; }
int Ship::getPilotLevel() { return pilotLevel; }
int Ship::getSensorLevel() { return sensorLevel; }
int Ship::getDoorLevel() { return doorLevel; }
int Ship::getRooms() { return rooms; }
bool Ship::getSensor() { return sensor; }

// gets a crew member at the provided index
CrewMember Ship::getCrewMember(unsigned int i) // returns the crew member at the provided index
{
	if (i > crew.size()) // if it would cause an out-of-bounds exception
	{
		return crew.at(i);
	}
	else
	{
		return CrewMember();
	}
}

std::vector<CrewMember> Ship::getCrew() { return crew; }

// adds a crew member; make sure all letters are lowercase
void Ship::addCrewMember(std::string species, char room)
{
	// Makes the species name lowercase for string checking.
	species = util::Utilities::toLower(species);

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

/**/
// returns all weapons
std::vector<Weapon> Ship::getWeapons() { return weapons; }

// add a weapon to the vector
void Ship::addWeapon(Weapon weapon) { weapons.push_back(weapon); }

void Ship::setWeapons(std::vector<Weapon> newWeapons) 
{ 
	weapons.clear();
	for (int i = 0; i < newWeapons.size(); i++)
	{
		weapons.push_back(newWeapons.at(i));
	}
}


// remove the last weapon in the vector
void Ship::removeWeapon() 
{ 
	if (!weapons.empty()) // if the vector isn't empty, the weapon at the back of the stack is removed.
		weapons.pop_back();
}


// remove a weapon
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
	for (int i = 0; i < tempVec.size(); i++)
	{
		weapons.push_back(tempVec.at(i));
	}
}


// applies damage to the shield before the health of the ship
void Ship::shieldToHealth(int damage) {
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

// Prints the ship
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

// Prints the stats of the ship
void Ship::printStats()
{	
	/*
	// prints the health (hull of the ship)
	std::string tempString(" ", 30);
	for (int i = 0; i < maxHull & i < hull; i++)
	{
		tempString.at(i) = '/';
	}

	std::cout << "HULL (HP) [" << tempString << "]" << std::endl;
	*/

	/*
	std::string tempStr = "";
	for (int i = 0; i < maxHull; i++)
		i < hull ? tempStr += "/" : tempStr += " ";
	
	std::cout << "HULL HP (" << hull << "/" << maxHull << ") [" << tempStr << "]" << std::endl;
	*/

	std::cout << getHealthBar() << std::endl;
	/*
	std::cout << "/HL: " << hull << std::endl;
	std::cout << "HULL (HP): [";
	for (int i = 1; i <= hull; i++)
	{
		std::cout << "/";
	}

	std::cout << "]" << std::endl;

	for (int i = 0; i < weapons.size(); i++)
		std::cout << weapons.at(i).toString() << std::endl;

	*/
}

// Gets a health bar for the ship.
std::string Ship::getHealthBar()
{
	std::string tempStr = "";
	for (int i = 0; i < maxHull; i++)
		i < hull ? tempStr += "/" : tempStr += " ";

	tempStr = "HULL HP (" + std::to_string(hull) + "/" + std::to_string(maxHull) + ") [" + tempStr + "]";
	return tempStr;
}
// Ship toString
std::string Ship::toString()
{
	std::string str = "";
	str += "Name: " + shipName + ", HULL(HP): " + std::to_string(getHull()) + ", Shield: " + std::to_string(getShield());
	return str;
}