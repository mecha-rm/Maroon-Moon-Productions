#pragma once
#include <iostream>
#include <string>
using namespace std;

class Weapon {
public:

	int getDamage();
	int getHealth();
	int getCooldown();

	void setDamage(int);
	void setHealth(int);
	void setCooldown(int);

private:

	int damage;
	int health;
	int cooldown;

};