#include <iostream>
#include <cstdlib>
#include "Hazard.h"
#include "Ship.h"

Ship playerShip; //the name can be changed to whatever the player wants it to be

void Hazard::giantStar(Ship playerShip) {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	playerShip.setHull(playerShip.getHull() - 2);//applying damage to the ship

}
void Hazard::nebula(Ship playerShip) {

	//This hazard is supposed to negate the use of sensors on the ship, however im not sure 
	playerShip.setSensor(false);

}
void Hazard::asteroidField(Ship playerShip) {

	//This hazard deals either removes 1 layer of shield if the player has one or takes 1
	//damage off the hull's total hp
	playerShip.setHull(playerShip.getHull() - 3);//applying damage to the ship
}
void Hazard::pulsar(Ship playerShip) {

	//i read over the pulsar stuff that happens in the real game...
	//i think we should just say that if you are hit with the pulsar event in your next battle your chance of missing attacks increases by a percent

}
void Hazard::antiShipBattery(Ship playerShip) {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	playerShip.setHull(playerShip.getHull() - 4);//applying damage to the ship

}
void Hazard::plasmaStorm(Ship playerShip) {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	playerShip.setHull(playerShip.getHull() - 3);//applying damage to the ship

}
/*void Hazard::enemyShip() {

	Ship enemyShip = Ship("Enemy Ship");

}*/
//Setters 
void Hazard::setDamage(int damage) { this->damage = damage; }
void Hazard::setRandomRoom(int randomRoom) { this->randomRoom = randomRoom; }

//Getters 
int Hazard::getDamage() { return damage; }
int Hazard::getRandomRoom() { return randomRoom; }