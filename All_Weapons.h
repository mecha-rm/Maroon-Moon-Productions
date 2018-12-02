//Initializes all weapons
#include "Weapon.h"

typedef struct WeaponType
{
public:
	WeaponType();


	//Laser Weapons - Infinite ammo, spend one shot on a layer of shields
	
	// Weapon(std::string name, std::string type, int CHARGETIME, int shots, int energy, int hullDam, int shieldDam, int crewDam, int sysDam, int chanceFire, int chanceBreach, int chanceStun);
	//Test Laser
	
	const Weapon laser_test = Weapon("TEST_LASER", "Laser", 10, 3, 2, 1, 1, 0, 0, 1, 0, 0);
	// Bust Laser I
	const Weapon laser_burst_i = Weapon("Burst Laser I", "Laser", 6, 2, 1, 2, 0, 0, 0, 0, 0, 0);
	//Burst Laser II
	const Weapon laser_burst_ii = Weapon("Burst Laser II", "Laser", 12, 3, 2, 1, 1, 0, 0, 1, 0, 0);
	//Dual Lasers
	const Weapon laser_dual = Weapon("Dual Lasers", "Laser", 10, 2, 1, 1, 1, 0, 0, 1, 0, 0);
	//Hull Laser I
	const Weapon laser_hull_i = Weapon("Hull Laser I", "Laser", 14, 2, 2, 50, 1, 1, 1, 0, 2, 0);


	//Missile Weapons - Require Missiles as ammo, ignore shields
		//Test Missile
	const Weapon missile_test = Weapon("TEST_MISSILE", "Missile", 12, 1, 2, 2, 0, 20, 10, 2, 2, 0);
	//Artemis
	const Weapon missile_artemis = Weapon("Artemis", "Missile", 11, 1, 1, 1, 0, 0, 0, 1, 1, 0);
	//Hermes
	const Weapon missle_hermes = Weapon("Hermes", "Missle", 14, 1, 3, 3, 3, 3, 3, 3, 2, 1);
	//Breach
	const Weapon missle_breach = Weapon("Breach", "Missle", 22, 1, 3, 4, 4, 4, 4, 3, 8, 1);
	//Swarm
	const Weapon missle_swarm = Weapon("Swarm", "Missle", 17, 2, 2, 2, 2, 2, 2, 1, 3, 1);


	//Bomb Weapons - Requires Missiles as ammo, ignore shields and hull
		//Test Bomb
	const Weapon bomb_test = Weapon("TEST_BOMB", "Bomb", 15, 1, 1, 10, 0, 30, 10, 2, 2, 0);
	//Small Bomb
	const Weapon bomb_small = Weapon("Small Bomb", "Bomb", 13, 1, 1, 0, 0, 30, 2, 1, 0, 0);
	// Fire Bomb
	const Weapon bomb_fire = Weapon("Fire Bomb", "Bomb", 15, 1, 2, 0, 0, 30, 2, 9, 0, 0);
	// Breach Bomb I
	const Weapon bomb_breach_i = Weapon("Breach Bomb I", "Bomb", 9, 1, 1, 0, 0, 30, 1, 0, 10, 0);
	// Cyrstal Lock Bomb
	const Weapon bomb_crystal_lock = Weapon("Crystal Lock Bomb", "Bomb", 15, 1, 1, 0, 40, 0, 0, 0, 10, 10);

} All_Weapons;
