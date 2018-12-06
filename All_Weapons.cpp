// Function defintions for All_Weapons, which holds all weapons used in the program.
#include "All_Weapons.h"
#include <random>

WeaponType::WeaponType() {}

// Returns a random weapon, test weapons notwithstanding.
Weapon WeaponType::getRandomWeapon()
{
	int randInt = rand() % numberOfWeapons + 1; // randomly chooses a weapon based on the number of weapons in the program. In this case, it's a number from 1 to 20.

	switch (randInt) // the break statements are just included for consistency and formatting.
	{
	// Laser Weapons
	case 1:
		return laser_burst_i;
		break;
	case 2:
		return laser_burst_ii;
		break;
	case 3:
		return laser_dual;
		break;
	case 4:
		return laser_hull_i;
		break;
	
	// Missle Weapons
	case 5:
		return missile_artemis;
		break;
	case 6:
		return missle_hermes;
		break;
	case 7:
		return missle_breach;
		break;
	case 8:
		return missle_swarm;
		break;

	// Bomb Weapons
	case 9:
		return bomb_small;
		break;
	case 10:
		return bomb_fire;
		break;
	case 11:
		return bomb_breach_i;
		break;
	case 12:
		return bomb_stun;
		break;
	case 13:
		return bomb_crystal_lock;
		break;

	// Shields
	case 14:
		return shield_basic;
		break;
	case 15:
		return shield_alpha;
		break;
	case 16:
		return shield_beta;
		break;
	case 17:
		return shield_gamma;
		break;
	case 18:
		return shield_omega;
		break;
	case 19:
		return shield_gambit;
		break;
	case 20:
		return shield_ultimate;
		break;
	
	// This shouldn't be reached, but just in case it is, a weapon is still returned.
	default:
		return laser_burst_i;
		break;
	}
}