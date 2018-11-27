//Initializes all weapons
#include "Weapon.h"

typedef struct WeaponType
{
public:
	WeaponType();

	//Laser Weapons - Infinite ammo, spend one shot on a layer of shields
	
	// Weapon(std::string name, std::string type, int chargeTime, int shots, int energy, int hullDam, int shieldDam, int crewDam, int sysDam, int chanceFire, int chanceBreach, int chanceStun);
	//Test Laser
	
	const Weapon laser_test = Weapon("TEST_LASER", "Laser", 10, 3, 2, 1, 1, 0, 0, 1, 0, 0);
	//Burst Laser II
	const Weapon laser_burst_ii = Weapon("Burst Laser II", "Laser", 12, 3, 2, 1, 1, 0, 0, 1, 0, 0);
	//Dual Lasers
	const Weapon laser_dual = Weapon("Dual Lasers", "Laser", 10, 2, 1, 1, 1, 0, 0, 1, 0, 0);

	//Missile Weapons - Require Missiles as ammo, ignore shields
		//Test Missile
	const Weapon missile_test = Weapon("TEST_MISSILE", "Missile", 12, 1, 2, 2, 0, 20, 10, 2, 2, 0);
	//Artemis
	const Weapon missile_artemis = Weapon("Artemis", "Missile", 11, 1, 1, 1, 0, 0, 0, 1, 1, 0);

	//Bomb Weapons - Requires Missiles as ammo, ignore shields and hull
		//Test Bomb
	const Weapon bomb_test = Weapon("TEST_BOMB", "Bomb", 15, 1, 1, 10, 0, 30, 10, 2, 2, 0);
	//Small Bomb
	const Weapon bomb_small = Weapon("Small Bomb", "Bomb", 13, 1, 1, 0, 0, 30, 2, 1, 0, 0);
	
} All_Weapons;
