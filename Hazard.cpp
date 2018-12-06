// Stores information on different hazards that can occur. This was not used in the final game.
#include <iostream>
#include <cstdlib>
#include "Hazard.h"
#include "Ship.h"

Ship playerShip; // the name can be changed to whatever the player wants it to be

// causes solar flares that start fires
void Hazard::giantStar(Ship playerShip) {

	int room = rand() % 17 + 1;
	setRandomRoom(room);
	playerShip.shieldToHealth(2); // applying damage to the ship

}

// disrupt's the ship's sensors
void Hazard::nebula(Ship playerShip) {

	//This hazard is supposed to negate the use of sensors on the ship
	playerShip.setSensor(false);

}

// occasionally has asteroids run into the ship to do damage to it or its shield.
void Hazard::asteroidField(Ship playerShip) {

	//This hazard deals either removes 1 layer of shield if the player has one or takes 1
	//damage off the hull's total hp
	playerShip.shieldToHealth(3);//applying damage to the ship
}

// causes shield damage, and damage to one other system
void Hazard::pulsar(Ship playerShip) {
	// Incomplete; one idea was that your accuracy would decrease slightly from being caught in this storm.
}

// randomly fires three shield-piercing shots. They hit random rooms, and always cause hull breaches.
void Hazard::antiShipBattery(Ship playerShip) {

	int room = rand() % playerShip.areas.size();
	setRandomRoom(room);
	playerShip.shieldToHealth(4);//applying damage to the ship

}

// causes the reactor to run at half efficiency
void Hazard::plasmaStorm(Ship playerShip) {

	int room = rand() % playerShip.areas.size();
	setRandomRoom(room);
	playerShip.shieldToHealth(3);//applying damage to the ship

}
/*void Hazard::enemyShip() { Ship enemyShip = Ship("Enemy Ship"); }*/

//Setters 
void Hazard::setDamage(int damage) { this->damage = damage; } // damage of the hazard
void Hazard::setRandomRoom(int randomRoom) { this->randomRoom = randomRoom; } // room the hazard effects

//Getters 
int Hazard::getDamage() { return damage; } // damage of the hazard
int Hazard::getRandomRoom() { return randomRoom; } // room the hazard effects