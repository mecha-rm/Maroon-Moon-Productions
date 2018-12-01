// The class for the game loop
#include "Gameplay.h"
#include "Utilities.h"
// #include "Timer.h"
// #include "Sprite.h"

#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <ctype.h>
#include <windows.h>

// Gameplay is playing by default
bool Gameplay::play = true;

Gameplay::Gameplay() { 
	// tw.ResizeScreenBuffers(twWidth, twHeight);
}

// Gameplay Loop
bool Gameplay::gameLoop()
{
	// Text-Version (GRID)
	/*

	std::string inputStr(""); // the string used for input
	char * inputArr; // the input in array form
	Sprite inputSprite; // input sprite
	unsigned int inputWidth(0), inputHeight(1);
	unsigned int inputPosX(1), inputPosY(10); // the position of the input

	bool Continue = TRUE;
	// pShip.printShip(); // prints the ship
	// std::cout << std::endl;
	// pShip.printStats(); // prints the stats of the ship

	createTextWindow(); // creates the buffer

	// windowColourTest(); // colour test
	// windowTypeTest(); // typing test
	// windowColourTypeTest(); // colour and typing test

	while (Continue) {

		Timer::CalculateDeltaTime();
		
	
		typeToWindow(inputStr); // called to see if something is being typed
		if (play == false) // if the escape key is pressed, play is equal to false. If play is equal to false, the game ends.
			return false;

		inputArr = new char[sizeof(inputStr)];
		memcpy(inputArr, inputStr.c_str(), sizeof(inputStr) / sizeof(char)); // puts the string into the array
		
		inputWidth = inputStr.length(); // gets the length of the string to know how many characters it should be
		inputSprite.SetSprite(inputArr, inputWidth, inputHeight); // sets the new spriet
		inputSprite.SetPosition(inputPosX, inputPosY); // sets the position of the sprite

		tw.RenderSprite(inputSprite); // renders the sprite
		tw.SwapBackBuffers(); // swaps buffers so that the sprite is visisble

	}

	// system("pause");
	// system("CLS"); // clear's the screen	
	*/


	std::string input("");
	int eWeapon(0); // saves index of ship's chosen weapon

	while (enemy.getHull() > 0)
	{
		std::cout << "PLAYER\n******************************************************" << std::endl;
		pShip.printShip();
		std::cout << std::endl;
		pShip.printStats();


		std::cout << "\nENEMY\n******************************************************" << std::endl;
		enemy.printShip();
		std::cout << std::endl;
		enemy.printStats();

		std::cout << std::endl;
		std::cout << "Select a weapon to use \n-----------------------------------------" << std::endl;
		for (int i = 0; i < pShip.weapons.size(); i++)
			std::cout << i + 1 << ") " << pShip.weapons.at(i).toString() << std::endl;
		
		std::cout << "DECIDE: ";
		getline(std::cin, input);

		// enemy.setHull(enemy.getHull() - 10);
		enemy.setHull(enemy.getHull() - pShip.weapons.at(std::stoi(input) - 1).getHullDam());

		// Enemy Attack
		eWeapon = rand() % enemy.weapons.size();
		pShip.setHull(pShip.getHull() - enemy.weapons.at(eWeapon).getHullDam()); // damanging the player

		system("pause");
		system("CLS");
	}


	return false;
}

Ship Gameplay::createShip(int type)
{
	Ship tempShip = Ship();

	return Ship();
}
//
//// Makes the buffer
//void Gameplay::createTextWindow()
//{
//	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0); // makes the console full-screen
//	tw.ResizeScreenBuffers(twWidth, twHeight); // resizes the text window; the size of the window was set in the constructor.
//
//	hIn = GetStdHandle(STD_INPUT_HANDLE);
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	Timer::InitializeDeltaTime(); // gets the system time
//}
//
//// Types ot the buffer screen; needs to be re-worked. A string is sent by reference for the input recieving. If a 'true' is returned, the user has decided to lock-in their input
//bool Gameplay::typeToWindow(std::string & input)
//{
//	// Assumes the buffer has already been created and the initial time has been gotten
//	/*
//	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
//	HANDLE hIn;
//	HANDLE hOut;
//
//	hIn = GetStdHandle(STD_INPUT_HANDLE);
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	Timer::InitializeDeltaTime(); // gets the system time
//	*/
//	
//	static char key = NULL; // the key pressed down; the program needs to remeber if the key was ever let go.
//
//	ReadConsoleInput(hIn, &InRec, 1, &NumRead);
//
//	switch (InRec.EventType)
//	{
//
//	// Keyboard input
//	case KEY_EVENT:
//
//		if (InRec.Event.KeyEvent.bKeyDown && key == NULL) // if the key was just pressed
//		{
//			switch (InRec.Event.KeyEvent.uChar.AsciiChar) // gets the ASCII character of the key
//			{
//			// Backspace
//			case 8:
//				if(input.length() > 0) // removes one character from the string if there are characters to remove.
//					input.pop_back();
//				break;
//			
//			// Enter Key (Carriage Return)
//			case 13:
//				return true; // returns true to tell the program the user is done with their input.
//				break;
//
//			// Escape;
//			case 27:
//				// if 'escape' is pressed, the game ends.
//				play = false;
//				return false;
//				break;
//
//			// Delete Key
//			case 127:
//				// Removes all characters from the input
//				input = "";
//				break;
//
//			default:
//
//				key = InRec.Event.KeyEvent.uChar.AsciiChar; // gets the current character
//
//				if(input.length() < 28 && key >= 32) // blocks off empty characters, aside from spaces
//					input += key; // adds the  current character to the input string
//			
//			}
//		}
//		else if (!InRec.Event.KeyEvent.bKeyDown) // if no key is being held down.
//		{
//			key = NULL; // 'key' is set to 'NULL' to tell the program that there is no key being held down.
//		}
//
//	case MOUSE_EVENT:
//
//		break;
//	}
//
//	return false;
//}
//
//// NOTE: you need to comment out hte lines that change the colour in GameWindow and Sprite to work.
//// Colour Text Test
//void Gameplay::windowColourTest()
//{
//	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
//
//	GameWindow tw(1600, 800);
//	tw.setColor(4);
//	char myBuffer[4] = { 'l','a','a','l' };
//
//	Sprite mySprite(myBuffer, 2, 2);
//
//	Timer::InitializeDeltaTime();
//
//	HANDLE hIn;
//	HANDLE hOut;
//
//	bool Continue = TRUE;
//
//	INPUT_RECORD InRec;
//	DWORD NumRead;
//
//	hIn = GetStdHandle(STD_INPUT_HANDLE);
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//
//	//A note on how to set cursor position, if it is ever useful again. 
//	//SetConsoleCursorPosition(hOut, 
//	//	MouseWhere); 
//
//
//	int pX = 0;
//	int pY = 0;
//
//	const int sArrW = 20;
//	const int sArrL = 40;
//
//	char sArr[sArrW * sArrL] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', };
//
//	Sprite arrSprite(sArr, sArrW, sArrL);
//	arrSprite.SetPosition(50, 5);
//
//	for (int x = 0; x < sArrW; x++) {
//		for (int y = 0; y < sArrL; y++) {
//			sArr[y + x * sArrL] = '#';
//		}
//	}
//
//	while (Continue) {
//
//		Timer::CalculateDeltaTime();
//
//		tw.RenderSprite(mySprite);
//
//		arrSprite.SetSprite(sArr, sArrL, sArrW);
//		tw.RenderSprite(arrSprite);
//
//		tw.SwapBackBuffers();
//		float check = Timer::GetDeltaTime();
//
//		ReadConsoleInput(hIn, &InRec, 1, &NumRead);
//
//		switch (InRec.EventType)
//		{
//		case KEY_EVENT:
//
//
//			if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x')
//			{
//				cout << "Exiting..." << endl;
//				Continue = FALSE;
//			}
//
//			sArr[pX + pY * 40] = '#';
//			if (InRec.Event.KeyEvent.bKeyDown) {
//				if (InRec.Event.KeyEvent.wVirtualKeyCode == 37) {
//					if (pX != 0) pX -= 1;
//				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 38) {
//					if (pY != 0) pY -= 1;
//				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 39) {
//					if (pX != sArrL - 1) pX += 1;
//					mySprite.SetPosition(mySprite.GetPosition().X + 1, mySprite.GetPosition().Y);
//				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 40) {
//					if (pY != sArrW - 1) pY += 1;
//				}
//			}
//
//			sArr[pX + pY * sArrL] = '0';
//
//			break;
//
//		case MOUSE_EVENT:
//
//			break;
//		}
//	}
//}
//
//// Typing Test; the program gets the key pressed upon its release, which requires the user to press down hard. This will need to be revised for the game input.
//void Gameplay::windowTypeTest()
//{
//	// For some reason, when using a dynamic 'char' array, the console can only print out a total of '28' characters before the rest of the string starts getting glitchy.
//	// However, if a static 'char' array is used, all of the values will print out perfectly.
//	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
//	GameWindow tw(1600, 800);
//
//	// This will print perfectly
//	char alphaChars[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd' };
//	Sprite defSprite(alphaChars, sizeof(alphaChars)/sizeof(char), 1); // sizeof(char) is equal to '1', so it does nothing here.
//	defSprite.SetPosition(10, 22);
//
//	std::string input = ""; // user input
//	// std::string input = "THIS IS WHAT IT TAKES TO BE INFINITEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"; // user input; uncomment to show what happens when 28+ characters are used.
//	char * userInput; // used to covert the input to a char array
//	Sprite inputSprite; // input sprite
//	char key = NULL; // the selected key
//
//
//	Timer::InitializeDeltaTime();
//
//	HANDLE hIn;
//	HANDLE hOut;
//
//	bool Continue = TRUE;
//
//	INPUT_RECORD InRec;
//	DWORD NumRead;
//
//	hIn = GetStdHandle(STD_INPUT_HANDLE);
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	//A note on how to set cursor position, if it is ever useful again.
//	//SetConsoleCursorPosition(hOut,
//	//	MouseWhere);
//
//	// Prints the buffer to the screen; gets the user's input; Everything in the game loop should be in that while continue.
//
//	while (Continue) {
//
//		Timer::CalculateDeltaTime();
//
//		// User input to screen
//		userInput = new char[sizeof(input)];
//		memcpy(userInput, input.c_str(), sizeof(input)); // takes the input and puts it into the dynamic 'char' array
//
//		inputSprite.SetSprite(userInput, input.length(), 1); // sets the sprite and its size
//		inputSprite.SetPosition(10, 20); // sets the position of the sprite
//		tw.RenderSprite(inputSprite); // renders the sprite
//		
//		defSprite.SetSprite(alphaChars, sizeof(alphaChars) / sizeof(char), 1); // sets the sprite to 'alphaChars'
//		tw.RenderSprite(defSprite);
//		tw.SwapBackBuffers();
//		
//		float check = Timer::GetDeltaTime();
//
//		ReadConsoleInput(hIn, &InRec, 1, &NumRead);
//
//		switch (InRec.EventType)
//		{
//
//		case KEY_EVENT:
//			// input += InRec.Event.KeyEvent.uChar.AsciiChar;
//			// text += InRec.Event.KeyEvent.uChar.AsciiChar;
//			std::cout << InRec.Event.KeyEvent.uChar.AsciiChar << std::endl;
//
//			// Adds the charater to the string if the key has been released
//			if (InRec.Event.KeyEvent.bKeyDown == false && key != NULL)
//			{
//				input += key; // key returns proper output, so what gives?
//				// std::cout << key << std::endl;
//				// std::cout << input << std::endl;
//				key = NULL;
//			}
//			else
//			{
//				if(key == NULL) // if there's not a saved key
//					key = InRec.Event.KeyEvent.uChar.AsciiChar; // gets the character of the key pressed down
//			}
//
//			// ESCAPE KEY to EXIT
//			if (InRec.Event.KeyEvent.uChar.AsciiChar == 27)
//			{
//				cout << "Exiting..." << endl;
//				Continue = FALSE;
//			}
//
//			break;
//
//		case MOUSE_EVENT:
//
//			break;
//		}
//	
//		// if (input.length() >= 28)
//			// input = "";
//	}
//}
//
//// Colour and Type Test; typing text whilst also changing the colour.
//void Gameplay::windowColourTypeTest()
//{
//	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
//	GameWindow tw(1600, 800);
//
//	char myBuffer[4] = { 'l','a','a','l' };
//
//	Sprite mySprite(myBuffer, 2, 2);
//
//	std::string input = ""; // user input
//	char * userInput; // used to covert the input to a char array
//
//	Sprite inputSprite;
//	char key = NULL; // the selected key
//
//	Timer::InitializeDeltaTime();
//
//	HANDLE hIn;
//	HANDLE hOut;
//
//	bool Continue = TRUE;
//
//	INPUT_RECORD InRec;
//	DWORD NumRead;
//
//	hIn = GetStdHandle(STD_INPUT_HANDLE);
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	//A note on how to set cursor position, if it is ever useful again.
//	//SetConsoleCursorPosition(hOut,
//	//	MouseWhere);
//
//
//	int pX = 0;
//	int pY = 0;
//
//	const int sArrW = 20;
//	const int sArrL = 40;
//
//	char sArr[sArrW * sArrL] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', };
//
//	Sprite arrSprite(sArr, sArrW, sArrL);
//	arrSprite.SetPosition(50, 5);
//
//	for (int x = 0; x < sArrW; x++) {
//		for (int y = 0; y < sArrL; y++) {
//			sArr[y + x * sArrL] = '#';
//		}
//	}
//
//	// Prints the buffer to the screen; gets the user's input; Everything in the game loop should be in that while continue.
//
//	while (Continue) {
//
//		Timer::CalculateDeltaTime();
//
//		tw.RenderSprite(mySprite);
//
//		arrSprite.SetSprite(sArr, sArrL, sArrW);
//
//
//		tw.RenderSprite(arrSprite);
//
//		// INPUT SPRITES
//		userInput = new char[sizeof(input)];
//		memcpy(userInput, input.c_str(), sizeof(input));
//
//		inputSprite.SetSprite(userInput, sizeof(input), 1);
//		inputSprite.SetPosition(100, 20);
//		tw.RenderSprite(inputSprite);
//
//
//		tw.SwapBackBuffers();
//
//		float check = Timer::GetDeltaTime();
//
//		ReadConsoleInput(hIn, &InRec, 1, &NumRead);
//
//		switch (InRec.EventType)
//		{
//
//		case KEY_EVENT:
//			// input += InRec.Event.KeyEvent.uChar.AsciiChar;
//			// text += InRec.Event.KeyEvent.uChar.AsciiChar;
//			// std::cout << InRec.Event.KeyEvent.uChar.AsciiChar << std::endl;
//
//			// Adds the charater to the string if the key has been released
//			if (InRec.Event.KeyEvent.bKeyDown == false && key != NULL)
//			{
//				input += key;
//				key = NULL;
//			}
//			else
//			{
//				// if(key == NULL) // if there's not a saved key
//				key = InRec.Event.KeyEvent.uChar.AsciiChar; // gets the character of the key pressed down
//			}
//
//			if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x')
//			{
//				cout << "Exiting..." << endl;
//				Continue = FALSE;
//			}
//
//			sArr[pX + pY * 40] = '#';
//			// true if pressed down; false otherwise
//			if (InRec.Event.KeyEvent.bKeyDown) {
//				if (InRec.Event.KeyEvent.wVirtualKeyCode == 37) {
//					if (pX != 0) pX -= 1;
//				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 38) {
//					if (pY != 0) pY -= 1;
//				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 39) {
//					if (pX != sArrL - 1) pX += 1;
//					mySprite.SetPosition(mySprite.GetPosition().X + 1, mySprite.GetPosition().Y);
//				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 40) {
//					if (pY != sArrW - 1) pY += 1;
//				}
//			}
//			sArr[pX + pY * sArrL] = '0';
//
//			break;
//
//		case MOUSE_EVENT:
//
//			break;
//		}
//	}
//}
