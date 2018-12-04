#pragma once
#include <iostream>
#include "Ship.h"

class Hazard {
public:

	std::string giantStarText = "Cap'n, we have begun to orbit a giant star. The ship is getting hot! (2 Hull Damage)";
	std::string nebulaText = "Cap'n, something is up with our Sensor Sub System. Its gone offline and I'm not sure when it will come back online.";
	std::string asteroidFieldText = "Cap'n, we are flying into an unavoidable asteriod belt... Our hulls going to take some damage from this, but nothing we can't handle. (3 Hull Damage)";
	std::string pulsarText = "Cap'n, we are getting a ion pulse on the radar from a giant nebula. We need to embrace for impact, theres no avoiding this. (3 Hull Damage)";
	std::string antiShipBatteryText = "Cap'n, we are flying too close to a hostile planet, they are firing at the ship! (4 Hull Damage)";
	std::string ionStormText = "Cap'n, we are going through a Plasma Strom! Check to make sure all of our systems are still running smoothly. (3 Hull Damage)";
	std::string enemyShipText = "Cap'n! Theres an Hostile Ship approaching! Prepare for battle!";

	void giantStar(Ship);
	void nebula(Ship);
	void asteroidField(Ship);
	void pulsar(Ship);
	void antiShipBattery(Ship);
	void plasmaStorm(Ship);
	// void enemyShip(Ship);

	int getDamage();
	int getRandomRoom();
	void setDamage(int);
	void setRandomRoom(int);

private:

	int damage;
	int randomRoom;

};