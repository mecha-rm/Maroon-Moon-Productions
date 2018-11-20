#include <iostream>
#include <cstdlib>
#include "Hazard.h"
#include "Ship.h"

Ship playerShip; //the name can be changed to whatever the player wants it to be

void Hazard::giantStar() {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	playerShip.shieldToHealth(5);//applying damage to the ship

}
void Hazard::nebula() {

	//This hazard is supposed to negate the use of sensors on the ship, however im not sure 
	playerShip.setSensor(false);

}
void Hazard::asteroidField() {

	//This hazard deals either removes 1 layer of shield if the player has one or takes 1
	//damage off the hull's total hp
	playerShip.shieldToHealth(1);//applying damage to the ship
}
void Hazard::pulsar() {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	playerShip.shieldToHealth(5);//applying damage to the ship

}
void Hazard::antiShipBattery() {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	playerShip.shieldToHealth(5);//applying damage to the ship

}
void Hazard::plasmaStorm() {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	playerShip.shieldToHealth(5);//applying damage to the ship

}
//Setters 
void Hazard::setDamage(int damage){ this->damage = damage; }
void Hazard::setRandomRoom(int randomRoom){ this->randomRoom = randomRoom; }

//Getters 
int Hazard::getDamage() { return damage; }
int Hazard::getRandomRoom() { return randomRoom; }