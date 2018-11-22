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

	system("pause");
	// system("CLS"); // clear's the screen	
	return false;
}

