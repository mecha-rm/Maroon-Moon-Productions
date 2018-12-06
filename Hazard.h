// Stores information on different hazards that can occur. This was not used in the final game.
#pragma once
#include <iostream>
#include "Ship.h"

class Hazard {
public:
	// Hazard Text
	std::string giantStarText = "Cap'n, we have begun to orbit a giant star. The ship is getting hot! (2 Hull Damage)";
	std::string nebulaText = "Cap'n, something is up with our Sensor Sub System. Its gone offline and I'm not sure when it will come back online.";
	std::string asteroidFieldText = "Cap'n, we are flying into an unavoidable asteriod belt... Our hulls going to take some damage from this, but nothing we can't handle. (3 Hull Damage)";
	std::string pulsarText = "Cap'n, we are getting a ion pulse on the radar from a giant nebula. We need to embrace for impact, theres no avoiding this. (3 Hull Damage)";
	std::string antiShipBatteryText = "Cap'n, we are flying too close to a hostile planet, they are firing at the ship! (4 Hull Damage)";
	std::string ionStormText = "Cap'n, we are going through a Plasma Strom! Check to make sure all of our systems are still running smoothly. (3 Hull Damage)";
	std::string enemyShipText = "Cap'n! Theres an Hostile Ship approaching! Prepare for battle!";

	// The diffrent hazards that exist in FTL: Faster Than Light
	void giantStar(Ship); // causes solar flares that start fires
	void nebula(Ship); // disrupt's the ship's sensors
	void asteroidField(Ship); // occasionally has asteroids run into the ship to do damage to it or its shield.
	void pulsar(Ship); // causes shield damage, and damage to one other system
	void antiShipBattery(Ship); // randomly fires three shield-piercing shots. They hit random rooms, and always cause hull breaches.
	void plasmaStorm(Ship); // causes the reactor to run at half efficiency
	// void enemyShip(Ship); // an unused function for creating an enemy ship

	int getDamage(); // gets the damage the hazard does
	int getRandomRoom(); // gets the random room generated for thehazard
	void setDamage(int); // sets the damage a hazard does
	void setRandomRoom(int); // sets the random room of the hazard

private:

	int damage; // the amount of damage the hazard does
	int randomRoom; // the room the hazard targets

};