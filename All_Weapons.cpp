//Initializes all weapons

#include "Weapon.h"

	//Laser Weapons - Infinite ammo, spend one shot on a layer of shields
//Test Laser
Weapon laser_test = Weapon("TEST_LASER", "Laser", 10, 3, 2, 1, 1, 0, 0, 1, 0, 0);
//Basic Laser
Weapon laser_basic = Weapon("Basic Laser", "Laser", 10, 1, 1, 1, 1, 0, 0, 1, 0, 0);
//Dual Lasers
Weapon laser_dual = Weapon("Dual Lasers", "Laser", 10, 2, 1, 1, 1, 0, 0, 1, 0, 0);
//Burst Laser I
Weapon laser_burst_i = Weapon("Burst Laser I", "Laser", 11, 2, 2, 1, 1, 0, 0, 1, 0, 0);
//Burst Laser II
Weapon laser_burst_ii = Weapon("Burst Laser II", "Laser", 12, 3, 2, 1, 1, 0, 0, 1, 0, 0);
//Burst Laser III
Weapon laser_burst_iii = Weapon("Burst Laser III", "Laser", 19, 5, 4, 1, 1, 0, 0, 1, 0, 0);

	//Missile Weapons - Require Missiles as ammo, ignore shields
//Test Missile
Weapon missile_test = Weapon("TEST_MISSILE", "Missile", 12, 1, 2, 2, 0, 20, 10, 2, 2, 0);
//Leto Missiles
Weapon missile_leto = Weapon("Leto Missile", "Missile", 9, 1, 1, 1, 0, 0, 0, 1, 1, 0);
//Artemis
Weapon missile_artemis = Weapon("Artemis Missile", "Missile", 11, 1, 1, 2, 0, 0, 0, 1, 1, 0);
//Hermes
Weapon missile_hermes = Weapon("Hermes Missile", "Missile", 14, 1, 3, 3, 0, 0, 0, 1, 1, 0);
//Breach Missiles
Weapon missile_breach = Weapon("Breach Missile", "Missile", 22, 1, 3, 4, 0, 0, 0, 1, 7, 0);
//Pegasus
Weapon missile_pegasus = Weapon("Pegasus Missile", "Missile", 20, 2, 3, 2, 0, 0, 0, 1, 1, 0);
