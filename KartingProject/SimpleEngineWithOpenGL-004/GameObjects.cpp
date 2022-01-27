#include "GameObjects.h"

GameObjects::GameObjects(const char *texturepath, SDL_Renderer *ren, int x, int y)
{
	filePath = *texturepath;
}

void GameObjects::update()
{
	objectDimensions.y = posY;
	objectDimensions.x = posX;
}

//Draw Players
void GameObjects::render()
{
	SDL_RenderCopyEx(renderer, objectTexture, NULL, &objectDimensions, angleRotation, center, flip);
}

void GameObjects::setSize(int x, int y)
{
	objectDimensions.h = x;
	objectDimensions.w = y;
}

SDL_Rect* GameObjects::getRect()
{
	return &objectDimensions;
}

void GameObjects::setPosX(float x)
{
	posX = x;
}

void GameObjects::setPosY(float y)
{
	posY = y;
}

void GameObjects::setPosition(float x, float y)
{
	posX = x;
	posY = y;
}

float GameObjects::getX()
{
	return posX;
}

float GameObjects::getY()
{
	return posY;
}
