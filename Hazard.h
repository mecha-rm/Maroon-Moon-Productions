#pragma once
#include <iostream>
#include "Ship.h"

class Hazard {
public:

	void giantStar();
	void nebula();
	void asteroidField();
	void pulsar();
	void antiShipBattery();
	void plasmaStorm();

	int getDamage();
	int getRandomRoom();
	void setDamage(int);
	void setRandomRoom(int);

private:

	int damage;
	int randomRoom;

};