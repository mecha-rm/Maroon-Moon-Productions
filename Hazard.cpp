#include <iostream>
#include <cstdlib>
#include "Hazard.h"
#include "Ship.h"

void Hazard::giantStar() {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	setDamage(5);

}
void Hazard::nebula() {

	//This hazard is supposed to negate the use of sensors on the ship, however im not sure 
	//how sensors are going to work so this stays blank for now

}
void Hazard::asteroidField() {

	//This hazard deals either removes 1 layer of shield if the player has one or takes 1
	//damage off the hull's total hp

	// if (shield > 0) {
	//	shield--;

	//}
	//else {
	//	hull--;
	//}

}
void Hazard::pulsar() {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	setDamage(5);

}
void Hazard::antiShipBattery() {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	setDamage(5);

}
void Hazard::plasmaStorm() {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	setDamage(5);
}
//Setters ------------------------------------------------------------------------------------------------------------------
void Hazard::setDamage(int damage){
	damage = Hazard::damage;

}
void Hazard::setRandomRoom(int randomRoom){
	randomRoom = Hazard::randomRoom;

}
//Getters ------------------------------------------------------------------------------------------------------------------
int Hazard::getDamage() {

	return damage;
}
int Hazard::getRandomRoom() {

	return randomRoom;
}