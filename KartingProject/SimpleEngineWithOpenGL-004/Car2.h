#pragma once
#include "GameObjects.h"
#include "Car.h"
#include <iostream>
#include "Vector2.h"

class Car2 : public GameObjects
{
private:
	float maxPowerSpeed;
	float powerSpeed;
	float rotationSpeed;
	float rotation;
	float pi;
	float twoPi;
	float nbLaps;
	bool isOnRoad;

	void collisionDetection();
	void lapsDetection();

public:
	Car2(const char* texturepath, SDL_Renderer* ren, int x, int y);
	~Car2();
	virtual void update() override;
	void move(std::string direction);

	Vector2 getForward() const;
	int getMaxSpeed();
	int getSpeed();
	int getRotationSpeed();
	float getRotation();
	int getPi();
	int getTwoPi();
	int getNbLaps();
};