// The controls of the crew on the ship. Due to crew members getting cut, this is NOT used in the final game.
#pragma once

class Controls {
public:
	//Constructor - Sets default controls
	Controls();

	//Getters (for checking keystrokes and the like)
	int getCrew1();
	int getCrew2();
	int getCrew3();
	int getCrew4();
	int getCrew5();
	int getCrew6();
	int getCrew7();
	int getCrew8();
	int getCrewAll();
	int getReturnStations();
	int getSaveStations();
	int getToggleTime();
	int getFTLJump();
	int getUpgrades();
	int getInventory();
	int getStore();
	int getOptions();
	int getDoorsOpen();
	int getDoorsClose();
	int getWeapon1();
	int getWeapon2();
	int getWeapon3();
	int getWeapon4();
	int getToggleAutofire();
	int getPowerShields();
	int getPowerEngines();
	int getPowerOxygen();
	int getPowerMedbay();
	int getPowerWeapons();
	int getDePowerModifier();
	int getSelectRoomsUp();
	int getSelectRoomsDown();
	int getSelectRoomsLeft();
	int getSelectRoomsRight();
	int getSwitchSelectedShip();
	int getPauseMenu();
	int getMoveTo();

	//Setters (if we wanted to implement changing the keybindings)
	void setCrew1(unsigned int e);
	void setCrew2(unsigned int e);
	void setCrew3(unsigned int e);
	void setCrew4(unsigned int e);
	void setCrew5(unsigned int e);
	void setCrew6(unsigned int e);
	void setCrew7(unsigned int e);
	void setCrew8(unsigned int e);
	void setCrewAll(unsigned int e);
	void setReturnStations(unsigned int e);
	void setSaveStations(unsigned int e);
	void setToggleTime(unsigned int e);
	void setFTLJump(unsigned int e);
	void setUpgrades(unsigned int e);
	void setInventory(unsigned int e);
	void setStore(unsigned int e);
	void setOptions(unsigned int e);
	void setDoorsOpen(unsigned int e);
	void setDoorsClose(unsigned int e);
	void setWeapon1(unsigned int e);
	void setWeapon2(unsigned int e);
	void setWeapon3(unsigned int e);
	void setWeapon4(unsigned int e);
	void setToggleAutofire(unsigned int e);
	void setPowerShields(unsigned int e);
	void setPowerEngines(unsigned int e);
	void setPowerOxygen(unsigned int e);
	void setPowerMedbay(unsigned int e);
	void setPowerWeapons(unsigned int e);
	void setDePowerModifier(unsigned int e);
	void setSelectRoomsUp(unsigned int e);
	void setSelectRoomsDown(unsigned int e);
	void setSelectRoomsLeft(unsigned int e);
	void setSelectRoomsRight(unsigned int e);
	void setSwitchSelectedShip(unsigned int e);
	void setPauseMenu(unsigned int e);
	void setMoveTo(unsigned int e);

private:
	unsigned int Crew1 = 0;				 //Select Crew 1
	unsigned int Crew2 = 0;				 //Select Crew 2
	unsigned int Crew3 = 0;				 //Select Crew 3
	unsigned int Crew4 = 0;				 //Select Crew 4
	unsigned int Crew5 = 0;				 //Select Crew 5
	unsigned int Crew6 = 0;				 //Select Crew 6
	unsigned int Crew7 = 0;				 //Select Crew 7
	unsigned int Crew8 = 0;				 //Select Crew 8
	unsigned int CrewAll = 0;			 //Select All Crew
	unsigned int ReturnStations = 0;	 //Return crew to stations
	unsigned int SaveStations = 0;		 //Save current crew locations as their station
	unsigned int ToggleTime = 0;		 //Toggle time pause
	unsigned int FTLJump = 0;			 //Opens FTL jump menu
	unsigned int Upgrades = 0;			 //Opens Upgrades menu
	unsigned int Inventory = 0;			 //Opens Inventory menu
	unsigned int Store = 0;				 //Opens Store menu (if available)
	unsigned int Options = 0;			 //Opens Options menu
	unsigned int DoorsOpen = 0;			 //Opens all doors
	unsigned int DoorsClose = 0;		 //Closes all doors
	unsigned int Weapon1 = 0;			 //Selects Weapon 1
	unsigned int Weapon2 = 0;			 //Selects Weapon 2
	unsigned int Weapon3 = 0;			 //Selects Weapon 3
	unsigned int Weapon4 = 0;			 //Selects Weapon 4
	unsigned int ToggleAutofire = 0;	 //Toggles Autofire
	unsigned int PowerShields = 0;		 //Power Shields by 1
	unsigned int PowerEngines = 0;		 //Power Engines by 1
	unsigned int PowerOxygen = 0;		 //Power Oxygen by 1
	unsigned int PowerMedbay = 0;		 //Power Medbay by 1
	unsigned int PowerWeapons = 0;		 //Power Weapons by 1
	unsigned int DePowerModifier = 0;	 //Hold and push Power buttons to depower them
	unsigned int SelectRoomsUp = 0;		 //Move between rooms up
	unsigned int SelectRoomsDown = 0;	 //Move between rooms down
	unsigned int SelectRoomsLeft = 0;	 //Move between rooms left
	unsigned int SelectRoomsRight = 0;	 //Move between rooms right
	unsigned int SwitchSelectedShip = 0; //Switches from one ship to another during combat
	unsigned int PauseMenu = 0;			 //Pauses the game
	unsigned int MoveTo = 0;			 //When on the room you want, press this to move a crew member here
};