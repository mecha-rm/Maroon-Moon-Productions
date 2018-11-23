// The class for the game loop
#include "Game.h"
#include "Game.h"
#include "Utilities.h"
#include "GameWindow.h"
#include "Timer.h"
#include "Sprite.h"

#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <ctype.h>
#include <windows.h>

Game::Game()
{
}

bool Game::gameLoop()
{



	pShip.printShip(); // prints the ship
	std::cout << std::endl;
	pShip.printStats(); // prints the stats of the ship
	
	
	// bufferColourTest(); // colour test
	bufferTypeTest(); // typing test
	// bufferColourTypeTest(); // colour and typing test

	// system("pause");
	// system("CLS"); // clear's the screen	

	return false;
}

// Colour Text Test
void Game::bufferColourTest()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	GameWindow tw(1600, 800);

	char myBuffer[4] = { 'l','a','a','l' };

	Sprite mySprite(myBuffer, 2, 2);

	Timer::InitializeDeltaTime();

	HANDLE hIn;
	HANDLE hOut;

	bool Continue = TRUE;

	INPUT_RECORD InRec;
	DWORD NumRead;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//A note on how to set cursor position, if it is ever useful again. 
	//SetConsoleCursorPosition(hOut, 
	//	MouseWhere); 


	int pX = 0;
	int pY = 0;

	const int sArrW = 20;
	const int sArrL = 40;

	char sArr[sArrW * sArrL] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', };

	Sprite arrSprite(sArr, sArrW, sArrL);
	arrSprite.SetPosition(50, 5);

	for (int x = 0; x < sArrW; x++) {
		for (int y = 0; y < sArrL; y++) {
			sArr[y + x * sArrL] = '#';
		}
	}

	while (Continue) {

		Timer::CalculateDeltaTime();

		tw.RenderSprite(mySprite);

		arrSprite.SetSprite(sArr, sArrL, sArrW);
		tw.RenderSprite(arrSprite);

		tw.SwapBackBuffers();
		float check = Timer::GetDeltaTime();

		ReadConsoleInput(hIn, &InRec, 1, &NumRead);

		switch (InRec.EventType)
		{
		case KEY_EVENT:


			if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x')
			{
				cout << "Exiting..." << endl;
				Continue = FALSE;
			}

			sArr[pX + pY * 40] = '#';
			if (InRec.Event.KeyEvent.bKeyDown) {
				if (InRec.Event.KeyEvent.wVirtualKeyCode == 37) {
					if (pX != 0) pX -= 1;
				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 38) {
					if (pY != 0) pY -= 1;
				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 39) {
					if (pX != sArrL - 1) pX += 1;
					mySprite.SetPosition(mySprite.GetPosition().X + 1, mySprite.GetPosition().Y);
				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 40) {
					if (pY != sArrW - 1) pY += 1;
				}
			}

			sArr[pX + pY * sArrL] = '0';

			break;

		case MOUSE_EVENT:

			break;
		}
	}
}

// Typing Test; the program gets the key pressed upon its release, which requires the user to press down hard. This will need to be revised for the game input.
void Game::bufferTypeTest()
{
	// For some reason, when using a dynamic 'char' array, the console can only print out a total of '28' characters before the rest of the string starts getting glitchy.
	// However, if a static 'char' array is used, all of the values will print out perfectly.
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	GameWindow tw(1600, 800);

	// This will print perfectly
	char alphaChars[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd' };
	Sprite defSprite(alphaChars, sizeof(alphaChars)/sizeof(char), 1); // sizeof(char) is equal to '1', so it does nothing here.
	defSprite.SetPosition(10, 22);

	std::string input = ""; // user input
	// std::string input = "THIS IS WHAT IT TAKES TO BE INFINITEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"; // user input; uncomment to show what happens when 28+ characters are used.
	char * userInput; // used to covert the input to a char array
	Sprite inputSprite; // input sprite
	char key = NULL; // the selected key


	Timer::InitializeDeltaTime();

	HANDLE hIn;
	HANDLE hOut;

	bool Continue = TRUE;

	INPUT_RECORD InRec;
	DWORD NumRead;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//A note on how to set cursor position, if it is ever useful again.
	//SetConsoleCursorPosition(hOut,
	//	MouseWhere);

	// Prints the buffer to the screen; gets the user's input; Everything in the game loop should be in that while continue.

	while (Continue) {

		Timer::CalculateDeltaTime();

		// User input to screen
		userInput = new char[sizeof(input)];
		memcpy(userInput, input.c_str(), sizeof(input)); // takes the input and puts it into the dynamic 'char' array

		inputSprite.SetSprite(userInput, input.length(), 1); // sets the sprite and its size
		inputSprite.SetPosition(10, 20); // sets the position of the sprite
		tw.RenderSprite(inputSprite); // renders the sprite
		
		defSprite.SetSprite(alphaChars, sizeof(alphaChars) / sizeof(char), 1); // sets the sprite to 'alphaChars'
		tw.RenderSprite(defSprite);
		tw.SwapBackBuffers();
		
		float check = Timer::GetDeltaTime();

		ReadConsoleInput(hIn, &InRec, 1, &NumRead);

		switch (InRec.EventType)
		{

		case KEY_EVENT:
			// input += InRec.Event.KeyEvent.uChar.AsciiChar;
			// text += InRec.Event.KeyEvent.uChar.AsciiChar;
			std::cout << InRec.Event.KeyEvent.uChar.AsciiChar << std::endl;

			// Adds the charater to the string if the key has been released
			if (InRec.Event.KeyEvent.bKeyDown == false && key != NULL)
			{
				input += key; // key returns proper output, so what gives?
				std::cout << input << std::endl;
				key = NULL;
			}
			else
			{
				if(key == NULL) // if there's not a saved key
					key = InRec.Event.KeyEvent.uChar.AsciiChar; // gets the character of the key pressed down
			}

			// ESCAPE KEY to EXIT
			if (InRec.Event.KeyEvent.uChar.AsciiChar == 27)
			{
				cout << "Exiting..." << endl;
				Continue = FALSE;
			}

			break;

		case MOUSE_EVENT:

			break;
		}
	
		// if (input.length() >= 28)
			// input = "";
	}
}

void Game::bufferColourTypeTest()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	GameWindow tw(1600, 800);

	char myBuffer[4] = { 'l','a','a','l' };

	Sprite mySprite(myBuffer, 2, 2);

	std::string input = ""; // user input
	char * userInput; // used to covert the input to a char array

	Sprite inputSprite;
	char key = NULL; // the selected key

	Timer::InitializeDeltaTime();

	HANDLE hIn;
	HANDLE hOut;

	bool Continue = TRUE;

	INPUT_RECORD InRec;
	DWORD NumRead;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//A note on how to set cursor position, if it is ever useful again.
	//SetConsoleCursorPosition(hOut,
	//	MouseWhere);


	int pX = 0;
	int pY = 0;

	const int sArrW = 20;
	const int sArrL = 40;

	char sArr[sArrW * sArrL] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', };

	Sprite arrSprite(sArr, sArrW, sArrL);
	arrSprite.SetPosition(50, 5);

	for (int x = 0; x < sArrW; x++) {
		for (int y = 0; y < sArrL; y++) {
			sArr[y + x * sArrL] = '#';
		}
	}

	// Prints the buffer to the screen; gets the user's input; Everything in the game loop should be in that while continue.

	while (Continue) {

		Timer::CalculateDeltaTime();

		tw.RenderSprite(mySprite);

		arrSprite.SetSprite(sArr, sArrL, sArrW);


		tw.RenderSprite(arrSprite);

		// INPUT SPRITES
		userInput = new char[sizeof(input)];
		memcpy(userInput, input.c_str(), sizeof(input));

		inputSprite.SetSprite(userInput, sizeof(input), 1);
		inputSprite.SetPosition(100, 20);
		tw.RenderSprite(inputSprite);


		tw.SwapBackBuffers();

		float check = Timer::GetDeltaTime();

		ReadConsoleInput(hIn, &InRec, 1, &NumRead);

		switch (InRec.EventType)
		{

		case KEY_EVENT:
			// input += InRec.Event.KeyEvent.uChar.AsciiChar;
			// text += InRec.Event.KeyEvent.uChar.AsciiChar;
			// std::cout << InRec.Event.KeyEvent.uChar.AsciiChar << std::endl;

			// Adds the charater to the string if the key has been released
			if (InRec.Event.KeyEvent.bKeyDown == false && key != NULL)
			{
				input += key;
				key = NULL;
			}
			else
			{
				// if(key == NULL) // if there's not a saved key
				key = InRec.Event.KeyEvent.uChar.AsciiChar; // gets the character of the key pressed down
			}

			if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x')
			{
				cout << "Exiting..." << endl;
				Continue = FALSE;
			}

			sArr[pX + pY * 40] = '#';
			// true if pressed down; false otherwise
			if (InRec.Event.KeyEvent.bKeyDown) {
				if (InRec.Event.KeyEvent.wVirtualKeyCode == 37) {
					if (pX != 0) pX -= 1;
				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 38) {
					if (pY != 0) pY -= 1;
				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 39) {
					if (pX != sArrL - 1) pX += 1;
					mySprite.SetPosition(mySprite.GetPosition().X + 1, mySprite.GetPosition().Y);
				}if (InRec.Event.KeyEvent.wVirtualKeyCode == 40) {
					if (pY != sArrW - 1) pY += 1;
				}
			}
			sArr[pX + pY * sArrL] = '0';

			break;

		case MOUSE_EVENT:

			break;
		}
	}
}
