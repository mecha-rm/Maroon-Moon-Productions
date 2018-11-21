#include "Controls.h"

//Constructor - Sets default controls
Controls::Controls() {
	setCrew1(112); // F1
	setCrew2(113); // F2
	setCrew3(114); // F3
	setCrew4(115); // F4
	setCrew5(116); // F5
	setCrew6(117); // F6
	setCrew7(118); // F7
	setCrew8(119); // F8
	setCrewAll(81); // Q
	setReturnStations(13); // Enter
	setSaveStations(191); // / 
	setToggleTime(32); // Space
	setFTLJump(74); // J
	setUpgrades(85); // U
	setInventory(73); // I
	setStore(75); // K
	setOptions(79); // O
	setDoorsOpen(90); // Z
	setDoorsClose(88); // X
	setWeapon1(49); // 1
	setWeapon2(50); // 2
	setWeapon3(51); // 3
	setWeapon4(52); // 4
	setToggleAutofire(86); // V
	setPowerShields(65); // A
	setPowerEngines(83); // S
	setPowerOxygen(70); // F
	setPowerMedbay(68); // D
	setPowerWeapons(87); // W
	setDePowerModifier(16); // Shift
	setSelectRoomsUp(38); // Up Arrow
	setSelectRoomsDown(40); // Down Arrow
	setSelectRoomsLeft(37); // Left Arrow
	setSelectRoomsRight(39); // Right Arrow
	setSwitchSelectedShip(9); // Tab
	setPauseMenu(27); // Esc
}

//Getters (for checking keystrokes and the like)
int Controls::getCrew1() { return Crew1; }
int Controls::getCrew2() { return Crew2; }
int Controls::getCrew3() { return Crew3; }
int Controls::getCrew4() { return Crew4; }
int Controls::getCrew5() { return Crew5; }
int Controls::getCrew6() { return Crew6; }
int Controls::getCrew7() { return Crew7; }
int Controls::getCrew8() { return Crew8; }
int Controls::getCrewAll() { return CrewAll; }
int Controls::getReturnStations() { return ReturnStations; }
int Controls::getSaveStations() { return SaveStations; }
int Controls::getToggleTime() { return ToggleTime; }
int Controls::getFTLJump() { return FTLJump; }
int Controls::getUpgrades() { return Upgrades; }
int Controls::getInventory() { return Inventory; }
int Controls::getStore() { return Store; }
int Controls::getOptions() { return Options; }
int Controls::getDoorsOpen() { return DoorsOpen; }
int Controls::getDoorsClose() { return DoorsClose; }
int Controls::getWeapon1() { return Weapon1; }
int Controls::getWeapon2() { return Weapon2; }
int Controls::getWeapon3() { return Weapon3; }
int Controls::getWeapon4() { return Weapon4; }
int Controls::getToggleAutofire() { return ToggleAutofire; }
int Controls::getPowerShields() { return PowerShields; }
int Controls::getPowerEngines() { return PowerEngines; }
int Controls::getPowerOxygen() { return PowerOxygen; }
int Controls::getPowerMedbay() { return PowerMedbay; }
int Controls::getPowerWeapons() { return PowerWeapons; }
int Controls::getDePowerModifier() { return DePowerModifier; }
int Controls::getSelectRoomsUp() { return SelectRoomsUp; }
int Controls::getSelectRoomsDown() { return SelectRoomsDown; }
int Controls::getSelectRoomsLeft() { return SelectRoomsLeft; }
int Controls::getSelectRoomsRight() { return SelectRoomsRight; }
int Controls::getSwitchSelectedShip() { return SwitchSelectedShip; }
int Controls::getPauseMenu() { return PauseMenu; }

//Setters (if we want to implement changing the keybindings)
void Controls::setCrew1(unsigned int e) { Crew1 = e; }
void Controls::setCrew2(unsigned int e) { Crew2 = e; }
void Controls::setCrew3(unsigned int e) { Crew3 = e; }
void Controls::setCrew4(unsigned int e) { Crew4 = e; }
void Controls::setCrew5(unsigned int e) { Crew5 = e; }
void Controls::setCrew6(unsigned int e) { Crew6 = e; }
void Controls::setCrew7(unsigned int e) { Crew7 = e; }
void Controls::setCrew8(unsigned int e) { Crew8 = e; }
void Controls::setCrewAll(unsigned int e) { CrewAll = e; }
void Controls::setReturnStations(unsigned int e) { ReturnStations = e; }
void Controls::setSaveStations(unsigned int e) { SaveStations = e; }
void Controls::setToggleTime(unsigned int e) { ToggleTime = e; }
void Controls::setFTLJump(unsigned int e) { FTLJump = e; }
void Controls::setUpgrades(unsigned int e) { Upgrades = e; }
void Controls::setInventory(unsigned int e) { Inventory = e; }
void Controls::setStore(unsigned int e) { Store = e; }
void Controls::setOptions(unsigned int e) { Options = e; }
void Controls::setDoorsOpen(unsigned int e) { DoorsOpen = e; }
void Controls::setDoorsClose(unsigned int e) { DoorsClose = e; }
void Controls::setWeapon1(unsigned int e) { Weapon1 = e; }
void Controls::setWeapon2(unsigned int e) { Weapon2 = e; }
void Controls::setWeapon3(unsigned int e) { Weapon3 = e; }
void Controls::setWeapon4(unsigned int e) { Weapon4 = e; }
void Controls::setToggleAutofire(unsigned int e) { ToggleAutofire = e; }
void Controls::setPowerShields(unsigned int e) { PowerShields = e; }
void Controls::setPowerEngines(unsigned int e) { PowerEngines = e; }
void Controls::setPowerOxygen(unsigned int e) { PowerOxygen = e; }
void Controls::setPowerMedbay(unsigned int e) { PowerMedbay = e; }
void Controls::setPowerWeapons(unsigned int e) { PowerWeapons = e; }
void Controls::setDePowerModifier(unsigned int e) { DePowerModifier = e; }
void Controls::setSelectRoomsUp(unsigned int e) { SelectRoomsUp = e; }
void Controls::setSelectRoomsDown(unsigned int e) { SelectRoomsDown = e; }
void Controls::setSelectRoomsLeft(unsigned int e) { SelectRoomsLeft = e; }
void Controls::setSelectRoomsRight(unsigned int e) { SelectRoomsRight = e; }
void Controls::setSwitchSelectedShip(unsigned int e) { SwitchSelectedShip = e; }
void Controls::setPauseMenu(unsigned int e) { PauseMenu = e; }