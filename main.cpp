/*
Developers: Alexander Da Costa (100704694), Caleb Birnie (100699828), Carter Menary (100700587), Devin Fitzpatrick (100709082), Nathan Tuck (100708651), Roderick “R.J.” Montague (100701758)
Date: 12/04/2018
References:
	> TutorialsPoint.com/switch statements (https://www.tutorialspoint.com/cplusplus/cpp_switch_statement.htm), Cplusplus.com/tolower (http://www.cplusplus.com/reference/cctype/tolower/), FTL: Faster Than Light Wiki/Home (https://ftl.fandom.com/wiki/FTL:_Faster_Than_Light_Wiki)
	> TutorialsPoint.com/Static Members of a C++ Class (https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm)
*/

/******************************************/
/* A Very Basic Sprite Lib starter Code
 * - this contains simple functionality to 
 *   start you off with loading sprites,
 *   drawing them and have a very base engine
 *   that handles basic input (keyboard/mouse)
 *   and update events for timers/display
 */

#include <windows.h>
#include <mmsystem.h> // used for music
#include "Game.h"

#include <random>
#include <ctime>
/******************************************/
/* GLOBAL VARIABLES */
/******************************************/
#define WINDOW_SCREEN_WIDTH 1920
#define WINDOW_SCREEN_HEIGHT 1000
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1000

/*********************************/
/* GLOBAL SPRITE INFO */
/*********************************/
#define FRAMES_PER_SECOND 30
const int FRAME_DELAY_SPRITE=1000/FRAMES_PER_SECOND;

/* the Game */
Game *theGame;

/* function DisplayCallbackFunction(void)
 * Description:
 *  - this is the openGL display routine
 *  - this draws the sprites appropriately
 */
void DisplayCallbackFunction(void)
{
	theGame->draw();
}

/* function void KeyboardCallbackFunction(unsigned char, int,int)
 * Description:
 *   - this handles keyboard input when a button is pressed
 */
void KeyboardCallbackFunction(unsigned char key, int x, int y)
{
	std::cout << "Keycode:"<<(int)key<<std::endl;
	theGame->keyboardDown(key,x,y);

}
/* function void KeyboardUpCallbackFunction(unsigned char, int,int)
 * Description:
 *   - this handles keyboard input when a button is lifted
 */
void KeyboardUpCallbackFunction(unsigned char key, int x, int y)
{
	theGame->keyboardUp(key,x,y);
}


/* function initImageLibrary()
 * Description:
 *   - initialize the DevIL library properly
 */
void initImageLibrary()
{
	glEnable(GL_TEXTURE_2D);
	ilInit();
	iluInit();
	ilutRenderer(ILUT_OPENGL);
}
	

/* function TimerCallbackFunction(int value)
 * Description: 
 *  - this is called many times per second
 *  - this enables you to animate things
 *  - no drawing, just changing the state
 *  - changes the frame number and calls for a redisplay
 *  - FRAME_DELAY_SPRITE is the number of milliseconds to wait before calling the timer again
 */
void TimerCallbackFunction(int value)
{
	theGame->update();		

	glutPostRedisplay();
	glutTimerFunc(FRAME_DELAY_SPRITE,TimerCallbackFunction,0);
}

/* function WindowReshapeCallbackFunction()
 * Description: 
 *  - this is called whenever the window is resized 
 *  - and sets up the projection matrix properly
 *  - currently set up for an orthographic view (2D only)
 */
void WindowReshapeCallbackFunction(int w,int h)
{
	float asp = (float)w/(float)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,WINDOW_SCREEN_WIDTH,0,WINDOW_SCREEN_HEIGHT);
	
	theGame->setNewWindowSize(w,h);
	theGame->setScreenSize(WINDOW_SCREEN_WIDTH, WINDOW_SCREEN_HEIGHT);
	theGame->updateScreenRatio();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MouseClickCallbackFunction(int button, int state, int x, int y)
{
	theGame->mouseClicked(button,state,x,y);
	glutPostRedisplay();
}


/* function MouseMotionCallbackFunction()
 * Description:
 *   - this is called when the mouse is clicked and moves
 */
void MouseMotionCallbackFunction(int x, int y)
{
	theGame->mouseMoved(x,y);
	glutPostRedisplay();
}

/* function main()
 * Description:
 *  - this is the main function
 *  - does initialization and then calls glutMainLoop() to start the event handler
 */
int main(int argc, char **argv)
{
	srand(time(0)); // seeding the randomizer
	PlaySound(TEXT("audio/FTL.wav"), NULL, SND_LOOP | SND_ASYNC); // starts playing the song and looping it.

	/* initialize the window and OpenGL properly */
	glutInit(&argc,argv);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutCreateWindow("Maroon Moon Productions - Game Development Workshop I (INFR 1395U) - FTL: Faster Than Light");

	/* set up our function callbacks */
	glutDisplayFunc(DisplayCallbackFunction);
	glutKeyboardFunc(KeyboardCallbackFunction);
	glutKeyboardUpFunc(KeyboardUpCallbackFunction);
	glutReshapeFunc(WindowReshapeCallbackFunction);
	glutMouseFunc(MouseClickCallbackFunction);
	glutMotionFunc(MouseMotionCallbackFunction);
	glutTimerFunc(1,TimerCallbackFunction,0);
	
	/* initialize the image library engine */
	initImageLibrary();

	/* init the game */
	theGame = new Game();
	theGame->setNewWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	theGame->initializeGame();

	/* start the event handler */
	glutMainLoop();
	return 0;
}