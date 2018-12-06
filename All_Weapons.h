// Stores pre-existing weapons that will be given to the ships. All weapons used in our game come from here.
#include "Weapon.h"

typedef struct WeaponType // the class can be referred to as 'WeaponType' or 'All_Weapons' (shown at the ending bracket)
{
public:
	WeaponType(); // constructor

	// returns a random weapon. Test weapons are not included.
	Weapon getRandomWeapon();

	// Constructor Setup - what these values mean will be explained in Weapon.h and Weapon.cpp.
	// Weapon(std::string name, std::string type, int CHARGETIME, int shots, int accuracy, int hullDam, int shieldDam, int crewDam, int sysDam, int chanceFire, int chanceBreach, int chanceStun);
	
	// The test weapons below were used as a basis for other weapons of the same type. They are not actually used by any of the ships.
	
	// Laser Weapons - tend to have have a high accuracy, but low damage.
	// Test Laser (Unused)
	const Weapon laser_test = Weapon("TEST_LASER", "Laser", 10, 3, 10, 10, 1, 0, 0, 1, 0, 0);
	// Bust Laser I
	const Weapon laser_burst_i = Weapon("Burst Laser I", "Laser", 6, 2, 10, 2, 0, 0, 0, 0, 0, 0);
	//Burst Laser II
	const Weapon laser_burst_ii = Weapon("Burst Laser II", "Laser", 12, 3, 10, 3, 1, 0, 0, 1, 0, 0);
	//Dual Lasers
	const Weapon laser_dual = Weapon("Dual Lasers", "Laser", 10, 2, 10, 1, 1, 0, 0, 1, 0, 0);
	//Hull Laser I
	const Weapon laser_hull_i = Weapon("Hull Laser I", "Laser", 14, 2, 9, 50, 1, 1, 1, 0, 2, 0);

	// Missiles - tend to have a high damage rate and accuracy, but take a while to charge.
	// Test Missle (Unused)
	const Weapon missile_test = Weapon("TEST_MISSILE", "Missile", 12, 1, 10, 2, 5, 20, 10, 2, 8, 0);
	//Artemis
	Weapon missile_artemis = Weapon("Artemis", "Missile", 11, 1, 9, 2, 5, 0, 0, 1, 8, 0);
	//Hermes
	const Weapon missle_hermes = Weapon("Hermes", "Missle", 14, 1, 10, 3, 3, 3, 3, 3, 9, 1);
	//Breach
	const Weapon missle_breach = Weapon("Breach", "Missle", 22, 1, 10, 4, 4, 4, 4, 3, 8, 1);
	//Swarm
	const Weapon missle_swarm = Weapon("Swarm", "Missle", 17, 3, 10, 2, 2, 2, 2, 1, 5, 1);


	//Bomb Weapons - have higher chances of causing special effects, but do little damage without them. Furthermore, no bomb is a guaranteed hit.
	//Test Bomb (Unused)
	const Weapon bomb_test = Weapon("TEST_BOMB", "Bomb", 15, 1, 9, 10, 5, 20, 10, 2, 2, 0);
	//Small Bomb
	// const Weapon bomb_small = Weapon("Small Bomb", "Bomb", 10, 1, 9, )
	const Weapon bomb_small = Weapon("Small Bomb", "Bomb", 10, 1, 8, 4, 5, 20, 2, 1, 0, 0);
	// FIre Bomb	
	const Weapon bomb_fire = Weapon("Fire Bomb", "Bomb", 15, 1, 7, 5, 2, 20, 2, 9, 0, 0);
	// Breach Bomb I
	const Weapon bomb_breach_i = Weapon("Breach Bomb I", "Bomb", 9, 1, 7, 1, 1, 20, 1, 0, 9, 0);
	// Stun Bomb
	const Weapon bomb_stun = Weapon("Stun Bomb", "Bomb", 13, 1, 7, 5, 2, 20, 20, 0, 0, 9);
	// Cyrstal Lock Bomb
	const Weapon bomb_crystal_lock = Weapon("Crystal Lock Bomb", "Bomb", 15, 1, 10, 0, 40, 0, 0, 0, 10, 10);


	// Shields: takes the shield value of a ship and gives it to a room, protecting said room from damage until the shield is destroyed. What rooms get what shields is usually decided randomly elsewhere.
	// Shield Test (Unused)
	const Weapon shield_test = Weapon("SHIELD_TEST", "Shield", 3, 1, 10, 0, 0, 0, 0, 0, 0, 0);
	// Shield Basic
	const Weapon shield_basic = Weapon("Shield Basic", "Shield", 5, 1, 10, 0, 0, 0, 0, 0, 0, 0);
	// Shield Alpha
	const Weapon shield_alpha = Weapon("Shield Alpha", "Shield", 5, 3, 9, 0, 0, 0, 0, 0, 0, 0);
	// Shield Beta
	const Weapon shield_beta = Weapon("Shield Beta", "Shield", 10, 8, 9, 0, 0, 0, 0, 0, 0, 0);
	// Shield Gamma
	const Weapon shield_gamma = Weapon("Shield Gamma", "Shield", 13, 12, 7, 0, 0, 0, 0, 0, 0, 0);
	// Shield Omega
	const Weapon shield_omega = Weapon("Shield Omega", "Shield", 16, 16, 5, 0, 0, 0, 0, 0, 0, 0);
	// Shield Gambit - This shield has a '1' in 10 chance of covering a room, but rolls 3 times per room.
	const Weapon shield_gambit = Weapon("Shield Gambit", "Shield", 20, 36, 1, 0, 0, 0, 0, 0, 0, 0);
	// Shield Ultimate
	const Weapon shield_ultimate = Weapon("Shield Ultimate", "Shield", 40, 26, 10, 0, 0, 0, 0, 0, 0, 0);

private:
	
	// The number of weapons. The 'test' weapons are not counted in this since they go unused.
	int numberOfWeapons = 20;

} All_Weapons;
