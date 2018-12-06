// This came with the SpriteLib download, and was not edited at all.
#include "Sprite.h"

/* THE SPRITE CLASS DEFINITION */
Sprite::Sprite(std::string spriteSheetFilename)
{
	this->loadSpriteSheet(spriteSheetFilename.c_str());
	currentAnimation = 0;
	layerID = 0;
	theta = 0;
	centerX = centerY = 0;

	position.set(100, 100, 0);
	velocity.set(0, 0, 0);
	acceleration.set(0, 0, 0);
	force.set(0, 0, 0);

	mass = 1;
}

// just adding the new force to the total net force vector
void Sprite::addForce(Vector3 f)
{
	force = force + f;
}

/* update()
* - this function could update things like physics and position
*/
void Sprite::update(float dt)
{

	// physics update goes here!!!!

	// compute our acceleration
	// F = m*a
	// a = (1.0/m) * force

	// testing purposes
	// compute direction to a particular point in the scene
	// point is (500,300);

	//acceleration.x = force.x;
	//acceleration.y = force.y;


	//// v_i = v_(i-1) + g*dt
	//velocity.x = velocity.x + acceleration.x*dt;
	//velocity.y = velocity.y + acceleration.y*dt;


	//// p_i = p_(i-1) + v*dt
	//position.x = position.x + velocity.x * dt;
	//position.y = position.y + velocity.y * dt;

	setCenter();

	force.set(0, 0, 0);


	/* for fun let's make it rotate */

	theta += 0.01;


	/* re-compute corners */
	recomputeCorners();


}
void Sprite::recomputeCorners() {
	/* rotate around center */
	Vector3 c(sz.width / 2, sz.height / 2, 0);

	corner1 = startingCorner1;
	corner2 = startingCorner2;
	corner3 = startingCorner3;
	corner4 = startingCorner4;
}

bool Sprite::isCollidingWith(Sprite *s) {
	return false;
}


Sprite::~Sprite(void)
{
}

void Sprite::loadSpriteSheet(const char *filename)
{
	sheet.textureID = ilutGLLoadImage((char*)filename);
	sheet.width = ilGetInteger(IL_IMAGE_WIDTH);
	sheet.height = ilGetInteger(IL_IMAGE_HEIGHT);
}

void Sprite::setSpriteFrameSize(int width, int height)
{
	sz.width = width;
	sz.height = height;
	sz.normalizedWidth = (float)width/(float)sheet.width;
	sz.normalizedHeight = (float)height/(float)sheet.height;

	corner1.set(0, 0, 0);
	corner2.set(0, sz.height, 0 );
	corner3.set(sz.width, sz.height,0 );
	corner4.set(sz.width, 0,0 );

	startingCorner1.set(0, 0, 0);
	startingCorner2.set(0, sz.height, 0);
	startingCorner3.set(sz.width, sz.height, 0);
	startingCorner4.set(sz.width, 0, 0);
}

void Sprite::setNumberOfAnimations(int num)
{
	numberOfAnimations = num;
	animations.reserve(num);
	for(int i=0;i<num;i++)
	{
		SpriteAnimation *anim = new SpriteAnimation();
		animations.push_back(anim);
	}
}

/*
 * addSpriteAnimFrame()
 *  - this adds a sprite animation frame to the end of the particular animation list
 *  - (x,y) specify the pixel values of the bottom left corner of the frame
 *  - animationNumber specifies which animation (i.e. JUMP, RUN, etc)
 *    you could use enum's for easier coding 
 */
void Sprite::addSpriteAnimFrame(int animationNumber, int x, int y)
{
	float u,v;
	u = (float)x/sheet.width;
	v = (float)y/sheet.height;

	XY_Coordinate *xy = new XY_Coordinate(x,y, u,v);
	animations[animationNumber]->coords.push_back(xy);
}

void Sprite::addSpriteAnimRow(int animationNumber, float startX, float startY, float spacingX, float spacingY, int numFrames)
{
	float x,y;
	x = startX;
	y = startY;
	for(int i=0;i<numFrames;i++)
	{
		x += spacingX;
		y += spacingY;
		addSpriteAnimFrame(animationNumber, x,y);
	}
}

/*
 * draw()
 * - this draws the sprite texture at its current frame of its current animation
 * - it positions the sprite based on the transformation formula:
 *    v' = RotationMatrix*(v-center) + position
 * where position is the bottom left corner of the sprite
 * and v is each corner of the sprite rectangle, v' is the transformed corner
 * and RotationMatrix is defined by the sprite's theta value (counter clockwise)
 */
void Sprite::draw()
{
	/* draw the sprite */
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();

	/* position the sprite into the particular pixel location */
	glTranslatef(position.x,position.y,0);

	// apply the rotation around the center of the sprite
	glTranslatef(centerX,centerY,0);
	glRotatef(theta, 0,0,1);
	glTranslatef(-centerX,-centerY,0);

	/* get the texture coordinate from the sprite so we know which frame to draw */
	SpriteAnimation *anim = animations[currentAnimation];
	int currentFrame = anim->currentFrame;
	float u,v;
	u = anim->coords[currentFrame]->u;
	v = anim->coords[currentFrame]->v;

	glColor3f(1,1,1);
		/* bind the appropriate texture frame */
		glBindTexture(GL_TEXTURE_2D,sheet.textureID);
		/* draw the image as a quad the size of the first loaded image */
		glBegin(GL_QUADS);
		    glTexCoord2f(u,v);
			glVertex3f(0,0,0);
			
			glTexCoord2f(u,v+sz.normalizedHeight);
			glVertex3f(0,sz.height,0);
			
			glTexCoord2f(u+sz.normalizedWidth,v+sz.normalizedHeight);
			glVertex3f(sz.width,sz.height,0);
			
			glTexCoord2f(u+sz.normalizedWidth,v);
			glVertex3f(sz.width,0,0);
		glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);
}

/*
* draw()
* - this draws the sprite texture at its current frame of its current animation
* - it positions the sprite based on the transformation formula:
*    v' = RotationMatrix*(v-center) + position
* where position is the bottom left corner of the sprite
* and v is each corner of the sprite rectangle, v' is the transformed corner
* and RotationMatrix is defined by the sprite's theta value (counter clockwise)
*/
void Sprite::draw2()
{
	/* draw the sprite */
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();

	/* position the sprite into the particular pixel location */
	glTranslatef(position.x, position.y, 0); // not originally in draw2

	/* get the texture coordinate from the sprite so we know which frame to draw */
	SpriteAnimation *anim = animations[currentAnimation];
	int currentFrame = anim->currentFrame;
	float u, v;
	u = anim->coords[currentFrame]->u;
	v = anim->coords[currentFrame]->v;

	glColor3f(1, 1, 1);
	/* bind the appropriate texture frame */
	glBindTexture(GL_TEXTURE_2D, sheet.textureID);

	/* draw the image as a quad the size of the first loaded image */
	glBegin(GL_QUADS);
	glTexCoord2f(u, v);
	glVertex3f(corner1.x, corner1.y, 0);
	
	glTexCoord2f(u, v + sz.normalizedHeight);
	glVertex3f(corner2.x, corner2.y, 0);

	glTexCoord2f(u + sz.normalizedWidth, v + sz.normalizedHeight);
	glVertex3f(corner3.x, corner3.y, 0);

	glTexCoord2f(u + sz.normalizedWidth, v);
	glVertex3f(corner4.x, corner4.y, 0);

	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);
}