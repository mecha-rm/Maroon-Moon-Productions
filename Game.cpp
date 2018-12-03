#include "Game.h"
#include "drawPrimitives.h"

using namespace std;

/* this is called by std::sort to sort the list based on layerID 
 *  for drawing in the proper order 
 */
bool spriteSortingFunction(Sprite *s1, Sprite *s2)
{
	// return true if s1's layerID is less than s2's layerID
	return (s1->layerID < s2->layerID);
}

/* constructor */
Game::Game(void)
{
	/* green background */
	stateInfo.bgClearColor.red = 1;
	stateInfo.bgClearColor.green = 1;
	stateInfo.bgClearColor.blue = 1;

	/* init state */
	stateInfo.gameState = STATE_GAMEPLAY;
	renderingTimer = new Timer("RENDER");
	updateTimer = new Timer("UPDATE");
}

/* destructor */
Game::~Game(void)
{
	/* deallocate memory and clean up here. if needed */
}

/* 
 * initializeGame()
 * - this function is called in the constructor to initialize everything related
 *   to the game, i..e loading sprites etc.
 * - MUST be called prior to any drawing/updating (you should add in checks to ensure this occurs in the right order)
 */
void Game::initializeGame()
{
	// The player's sprite
	/* this is a sprite without any animations, it is just an image */
	player = new Sprite("images/ImgDmp/GDW3-FTL-Kestrel Labeled.png");
	player->setNumberOfAnimations(1);
	player->setSpriteFrameSize(1400, 876);
	player->addSpriteAnimFrame(0,0,0);
	player->setPosition(-168.0F, 62.0F);
	player->setCenter(player->sz.width/2, player->sz.height/2); // center of the sprites origin for rotation
	player->setLayerID(2);
	player->setCenter();
	player->setRadius(player->sz.width / 2);

	/* add it to our list so we can draw it */
	this->addSpriteToDrawList(player);
	
	// Ship dooes
	/*
	opponent = new Sprite("images/ImgDmp/spaceship.png");
	opponent->setNumberOfAnimations(1);
	opponent->setSpriteFrameSize(595, 438);
	opponent->addSpriteAnimFrame(0, 0, 0);
	opponent->setPosition(400, 200);
	opponent->setCenter(495 / 2, 438 / 2); // center of the sprites origin for rotation
	opponent->setLayerID(2);
	opponent->setCenter();
	opponent->setRadius(148 / 2);
	*/

	doors = new Sprite("images/ImgDmp/GDW3-FTL-Doors-Closed.png");
	doors->setNumberOfAnimations(1);
	doors->setSpriteFrameSize(1400, 876);
	doors->addSpriteAnimFrame(0, 0, 0);
	doors->setPosition(-142.0F, 62.0F);
	doors->setCenter(doors->sz.width / 2, doors->sz.height / 2); // center of the sprites origin for rotation
	doors->setLayerID(2);
	doors->setCenter();
	doors->setRadius(doors->sz.width / 2);

	this->addSpriteToDrawList(doors);

	opponent = new Sprite("images/ImgDmp/GDW3-FTL-Enemy-Scout Labeled.png");
	opponent->setNumberOfAnimations(1);
	opponent->setSpriteFrameSize(438, 700);
	opponent->addSpriteAnimFrame(0, 0, 0);
	opponent->setPosition(1400, 140);
	opponent->setCenter(opponent->sz.width / 2, opponent->sz.height / 2); // center of the sprites origin for rotation
	opponent->setLayerID(2);
	opponent->setCenter();
	opponent->setRadius(opponent->sz.width / 2);

	this->addSpriteToDrawList(opponent);

	
	hud = new Sprite("images/ImgDmp/GDW3-FTL-HUD.png");
	hud->setNumberOfAnimations(1);
	hud->setSpriteFrameSize(1920, 1080);
	hud->setPosition(0, 0);
	hud->addSpriteAnimFrame(0, 0, 0);
	hud->setLayerID(3);
	hud->setCenter();
	hud->setRadius(hud->sz.width / 1);
	
	// this->addSpriteToDrawList(hud);
	
	/* add it to our list so we can draw it */
	//this->addSpriteToDrawList(opponent);

	// load the text box
	textBox = new Sprite("images/ImgDmp/FTL - Rules Textbox.png");
	textBox->setNumberOfAnimations(1);
	textBox->setSpriteFrameSize(1750, 949);
	textBox->setPosition(80, 25);
	textBox->addSpriteAnimFrame(0, 0, 0);
	textBox->setLayerID(3);
	textBox->setCenter();

	this->addSpriteToDrawList(textBox);

	///* load the background */
	bg = new HorizontalScrollingBackground("images/Backgrounds/backGround.jpg",stateInfo.windowWidth,stateInfo.windowHeight);
	this->addSpriteToDrawList(bg);
	bg->setLayerID(0);

}

/* draw()
 * - this gets called automatically about 30 times per second
 * - this function just draws the sprites 
 */
void Game::draw()
{
	/* pre-draw - setup the rendering */
	PreDraw();

	/* draw - actually render to the screen */
	DrawGame();
	
	/* post-draw - after rendering, setup the next frame */
	PostDraw();
}

/*
 * Pre-Draw() is for setting up things that need to happen in order to draw
 *    the game, i.e. sorting, splitting things into appropriate lists etc.
 */
void Game::PreDraw()
{
	/* clear the screen */
	glViewport(0,0,stateInfo.windowWidth,stateInfo.windowHeight);
	glClearColor(stateInfo.bgClearColor.red, 
				 stateInfo.bgClearColor.green, 
				 stateInfo.bgClearColor.blue, 0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // clear out the transformation matrix
	glEnable(GL_TEXTURE_2D); // turn on texturing

	// if we update our timer it will tell us the elapsed time since the previous 
	// frame that we rendered
	renderingTimer->tick();


	/* sort the sprites by layerID so we draw them in the right order */
	std::sort(spriteListToDraw.begin(), spriteListToDraw.end(), spriteSortingFunction);

}

/* 
 * DrawGame()
 *  - this is the actual drawing of the current frame of the game.
 */
void Game::DrawGame()
{
	/* here is where your drawing stuff goes */
	drawSprites();

	glDisable(GL_TEXTURE_2D);
	drawTestPrimitives(); 
	setColor(255, 255, 255);

	if (battle)
	{
		// printing player stats
		drawText("Name: " + Gameplay::getPlayer()->getName(), 600.0F, 180.0F);
		drawText("Hull: " + Gameplay::getPlayer()->getHealthBar(), 600.0, 156.0F);
		drawText("Shield: " + std::to_string(Gameplay::getPlayer()->getShield()), 600.0F, 132.0F);

		for (int i = 0; i < Gameplay::getPlayer()->areas.size(); i++)
		{

		}

		// printing enemy stats
		drawText("Name: " + Gameplay::getEnemy()->getName(), 1200.0F, 180.0F); // printing the player stats
		drawText("Hull: " + Gameplay::getEnemy()->getHealthBar(), 1200.0, 156.0F);
		drawText("Shield: " + std::to_string(Gameplay::getEnemy()->getShield()), 1200.0F, 132.0F);
	}

	setColor(255, 0, 0);
	//drawCircle(10, player->radius, player->center.x, player->center.y);
	//drawCircle(10, opponent->radius, opponent->center.x, opponent->center.y);

	/* this makes it actually show up on the screen */
	glutSwapBuffers();
}

/*
 * PostDraw()
 *  - in here you should clean up and set up things for the next frame
 *  - i.e. once I've used my assets, I can change them to set up things for
 *    the next frame, usually just memory management or setting up game state 
 *    boolean values etc.  
 */
void Game::PostDraw()
{
	// nothing here at the moment
}

/* drawSprites()
 * - this function is what actually draws the sprites
 *   onto the screen at their appropriate location
 * - it actually loops through a list of active sprites
 *   and then sorts them by their layerID and then draws them
 * - the sorting has to happen so that you draw from back to front
 *   just like a painter and a canvas.
 */
void Game::drawSprites()
{
	// this just goes through the list of sprites and tells them to draw
	std::vector<Sprite*>::iterator it; 
	for(it=spriteListToDraw.begin(); it != spriteListToDraw.end();it++)
	{
		Sprite *s = (*it);
		s->draw2(); // use draw '1' for mouse input
	}

}

/* for testing purposes to show you how to use
   the drawing primitives capabilities */
void Game::drawTestPrimitives()
{
	/* draw line */
	if (input.mouseDown)
	{
		setLineWidth(5.f);
		setColor(1, 0, 0);
		drawLine(input.clickX, input.clickY, input.currentX, input.currentY);
		setLineWidth(1.f);
	}
}

// starts the battle if 'true'
void Game::startBattle(bool battle)
{
	// Removes the textbox by hiding it behind the background.
	if (battle == true && this->battle == false) // if a battle is starting...
	{
		textBox->setPosition(-3000, -3000); // moves the textbox off screen.
	}
	else if (battle == false && this->battle == true)
	{

	}
	
	// textBox->setLayerID(0);
	this->battle = battle;
}

/* update()
  - this function is essentially the game loop
    it gets called often and as such you
	don't actually need a "loop" to define the game
	it happens behind the scenes
  - think of this function as one iteration of the game loop
  - if you need to update physics calculations, sprite animation info,
    or sound etc, it goes in here
*/
void Game::update()
{
	// update our clock so we have the delta time since the last update
	updateTimer->tick();


	/* you should probably update all of the sprites in a list just like the drawing */
	/* maybe two lists, one for physics updates and another for sprite animation frame update */
	player->update(updateTimer->getElapsedTimeSeconds());
	//opponent->update(updateTimer->getElapsedTimeSeconds());

	// calls gp to continue the loop for the game.
	if (battle) // loads up the graphics before the game loop starts
	{
		gp.gameLoop();
	}
	// textBox->setPosition(-3000, -3000);
	// textBox->setPosition(textBox->position.x += 1, textBox->position.y += 1);

	// check collisions below here!
	// ???
	if (press) {
		std::cout << gp.getPlayer()->getCrew()[0].nextMove.empty() << std::endl;
		gp.getPlayer()->crewMove();
		gp.getPlayer()->printShip();
		press = false;
		/*
		cout << pShip.getCrew()[0].nextMove.empty() << endl;
		pShip.crewMove();
		pShip.printShip();
		press = false;
		*/
	}
}

/* 
 * addSpriteToDrawList()
 * - this function simply pushes the sprite to the end of the list
 */
void Game::addSpriteToDrawList(Sprite *s)
{
	if(s)
	{
		/* push the sprite to the back of the list */
		this->spriteListToDraw.push_back(s);
	}
}


/*************************************************/
/* INPUT - keyboard/mouse functions below        */
/*************************************************/
/* keyboardDown()
   - this gets called when you press a key down
   - you are given the key that was pressed
     and where the (x,y) location of the mouse is when pressed
*/
void Game::keyboardDown(unsigned char key, int mouseX, int mouseY)
{
	float f = 100;
	switch(key)
	{
	case 'w':
		player->addForce(Vector3(0, f, 0));
		break;
	case 'a':
		player->addForce(Vector3(-f, 0, 0));
		break;
	case 's':
		player->addForce(Vector3(0, -f, 0));
		break;
	case 'd':
		player->addForce(Vector3(f, 0, 0));
		break;
	case 'r':  // reset position, velocity, and force
		player->position.set(100, 100, 0);
		player->velocity.set(0, 0, 0);
		player->acceleration.set(0, 0, 0);
		player->force.set(0, 0, 0);
		break;
	case 13: // enter key
		startBattle(true);
		break;
	case 32: // the space bar
		break;
	case 27: // the escape key
	case 'q': // the 'q' key
		exit(1);
		break;
	}
}
/* keyboardUp()
   - this gets called when you lift a key up
   - you are given the key that was pressed
     and where the (x,y) location of the mouse is when pressed
*/
void Game::keyboardUp(unsigned char key, int mouseX, int mouseY)
{
	switch(key)
	{
	case 32: // the space bar
		break;
	case 27: // the escape key
	case 'q': // the 'q' key
		exit(1);
		break;
	}
}

/*
 * mouseClicked
 * - this function is called when the mouse is clicked and it handles the 
 *   input state managment
 */
void Game::mouseClicked(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN) 
	{
		input.mouseDown = true;
		input.clickX = x*stateInfo.ratioWidth;
		input.clickY = (stateInfo.windowHeight-y)*stateInfo.ratioHeight;
		input.button = button;

		switch(button)
		{
		case GLUT_LEFT_BUTTON:
			
			break;
		case GLUT_RIGHT_BUTTON:
		
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		}
	}
	else
	{
		/* set force */
		Vector3 f;
		f.set(input.currentX - input.clickX, input.currentY - input.clickY, 0);
		f = f * 20.f;
		player->addForce(f);
		
		input.mouseDown = false;
	}

}

/*
 * mouseMoved(x,y)
 * - this occurs only when the mouse is pressed down
 *   and the mouse has moved.  you are given the x,y locations
 *   in window coordinates (from the top left corner) and thus 
 *   must be converted to screen coordinates using the screen to window pixels ratio
 *   and the y must be flipped to make the bottom left corner the origin.
 */
void Game::mouseMoved(int x, int y)
{
	/* convert from window to screen pixel coordinates */
	input.currentX = x*stateInfo.ratioWidth;
	input.currentY = (stateInfo.windowHeight-y)*stateInfo.ratioHeight;
	
	if(input.mouseDown)
	{
		if(input.button == GLUT_LEFT_BUTTON)
		{
			// nothing yet
		}
	}
}
