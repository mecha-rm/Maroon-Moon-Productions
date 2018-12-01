#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/glut.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"
#include "Vector3.h"

#include <string>

class XY_Coordinate
{
public:
	XY_Coordinate(float _x, float _y, float _u, float _v){ x=_x; y=_y; u = _u; v=_v;}
	~XY_Coordinate(){}
	float x,y;
	float u,v;
};

class SpriteAnimation 
{
public:
	SpriteAnimation(void)
	{
		currentFrame = 0;
		doesLoop = true;
	}
	~SpriteAnimation(void){}
	
	void nextFrame()
	{
		int numFrames = coords.size();
		currentFrame++;
		if(currentFrame >= numFrames)
		{
			if(doesLoop) currentFrame = 0;
			else currentFrame = numFrames - 1;
		}
	}

	void setLooping(bool loop) {doesLoop = loop;}

	/* each animation has a list of x,y coordinates
	   that can be cycled through */
	std::vector<XY_Coordinate*> coords;
	bool doesLoop;
	int currentFrame;
};

typedef struct _SpriteSheetInfo
{
	unsigned int textureID;
	float width,height;
}SpriteSheetInfo;

typedef struct _SpriteSize
{
	float width, height;
	float normalizedWidth,normalizedHeight;
}SpriteSize;

/* Sprite class
 * - this class takes care of everything
     related to sprites 
	 loading/drawing/setting states etc.
 */ 
class Sprite
{
public:
	Sprite(std::string spriteSheetFilename);
	~Sprite(void);

	void loadSpriteSheet(const char *filename);
	void setSpriteFrameSize(int width, int height);
	void setNumberOfAnimations(int num);
	void addSpriteAnimFrame(int animationNumber, int x, int y);
	void addSpriteAnimRow(int animationNumber, float startX, float startY, float spacingX, float spacingY, int numFrames);

	void setLayerID(float value) {
		layerID = value;
	}
	void setCenter(float x, float y) {
		centerX = x; centerY = y;
	}
	void setPosition(float x, float y) {
		positionX = x; positionY = y;
		position.x = x;
		position.y = y;
		position.z = 0;
	}
	void setOrientation(float _theta) {
		theta = _theta;
	}
	float getOrientation() {return theta;}

	/* drawing */
	virtual void draw();
	virtual void draw2();

	void setCurrentAnimation(int anim) {
		currentAnimation = anim;
		if(currentAnimation >= animations.size()) currentAnimation = 0;
	}
	/* update */
	void addForce(Vector3 v);
	virtual void update(float dt);

	void nextFrame(){
		animations[currentAnimation]->nextFrame();
	}


	/* sprite info */
	SpriteSize sz;
	SpriteSheetInfo sheet;
	int numberOfAnimations;
	int currentAnimation;

	/* position/center/orientation */
	/* these should be VECTORS! */
	float positionX,positionY;

	void setRadius(float value) {
		radius = value;
	}
	void setCenter() {
		center.x = position.x + sz.width / 2.f;
		center.y = position.y + sz.height / 2.f;
	}

	bool isCollidingWith(Sprite *s);

	Vector3 position;  // use this!  Its a vector!!

	Vector3 corner1, corner2, corner3, corner4;
	Vector3 startingCorner1, startingCorner2, startingCorner3, startingCorner4;

	void recomputeCorners();



	float centerX,centerY;
	float theta;
	float radius; // this is the radius of the sprite collision circle
	Vector3 center; // this is the center of the sprite

	// physics;
	Vector3 velocity;
	Vector3 acceleration;
	Vector3 force;
	float mass;




	// which layer this sprite is on, lower is further away, 
	// background is 0, foreground > 0
	int layerID; 

	/* list of animations */
	std::vector<SpriteAnimation*> animations;
};
