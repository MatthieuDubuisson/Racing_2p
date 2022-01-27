#pragma once
#include "TexturesManager.h"
#include"Game.h"
#include <time.h>
#include <iostream>
#include "Vector2.h"

class GameObjects
{
protected:
	SDL_Texture *objectTexture;
	SDL_Renderer *renderer;
	std::string type;

	SDL_Rect GOcrop, objectDimensions;
	double angleRotation;
	SDL_Point *center;
	SDL_RendererFlip flip;

public:
	int posX;
	int posY;
	char filePath;

	GameObjects(const char *texturepath, SDL_Renderer *ren, int x, int y);
	GameObjects(){};

	virtual void update();
	virtual void render();
	virtual void setSize(int x, int y);
	virtual SDL_Rect *getRect();
	virtual void setPosX(float x);
	virtual void setPosY(float y);
	virtual void setPosition(float x, float y);
	float getX();
	float getY();
};