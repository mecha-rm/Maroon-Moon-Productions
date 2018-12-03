#pragma once
#include <iostream>
#include "Ship.h"

class Hazard {
public:

	std::string giantStarText = "Cap'n, we have begun to orbit a giant star. You need to put some distance between youself and the star before the hull gets too hot and results in dissaster! \n YOUR SHIP HAS CAUGHT ON FIRE!";
	std::string nebulaText = "Cap'n, something is up with our Sensor Sub System. Its gone offline and I'm not sure when it will come back online.";
	std::string asteroidFieldText = "Cap'n, we are flying into an unavoidable asteriod belt... Our hulls going to take some damage from this, but nothing we can't handle.";
	std::string pulsarText = "Cap'n, we are getting a ion pulse on the radar from a giant nebula. We need to embrace for impact, theres no avoiding this.";
	std::string antiShipBatteryText = "Cap'n, we are flying too close to a hostile planet, they are firing at the ship!";
	std::string ionStormText = "Cap'n, we are going through a Plasma Strom! Check to make sure all of our systems are still running smoothly.";
	std::string enemyShipText = "Cap'n! Theres an Hostile Ship approaching! Prepare for battle!";

	void giantStar();
	void nebula();
	void asteroidField();
	void pulsar();
	void antiShipBattery();
	void plasmaStorm();
	void enemyShip();

	int getDamage();
	int getRandomRoom();
	void setDamage(int);
	void setRandomRoom(int);

private:

	int damage;
	int randomRoom;

};