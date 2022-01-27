#include "Car2.h"
#include "Maths.h"
#include <iostream>

//Player2 constructor

Car2::Car2(const char* texturepath, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objectTexture = TexturesManager::loadTexture(texturepath, renderer);
	posX = x;
	posY = y;
	objectDimensions.h = 60;
	objectDimensions.w = 30;
	maxPowerSpeed = 4.0f;
	powerSpeed = 0.0f;
	rotationSpeed = 3.0f;
	rotation = 0.0f;
	pi = 3.14155926535;
	twoPi = pi * 2.0f;
	nbLaps = 0.0f;
	isOnRoad = false;
}

Car2::~Car2()
{
}

void Car2::collisionDetection()
{
//Reduce speed when meet collision
	if (posX > 730)
	{
		maxPowerSpeed = 2.0f;
	}

	else if (posX < 10)
	{
		maxPowerSpeed = 2.0f;
	}

	else if (posY < 10)
	{
		maxPowerSpeed = 2.0f;
	}

	else if (posY > 550)
	{
		maxPowerSpeed = 2.0f;
	}

	else if ((posX > 150) && (posX < 600) && (posY > 160) && (posY < 430))
	{
		maxPowerSpeed = 1.5f;
	}


	else
	{
		maxPowerSpeed = 4.0f;
	}


}

void Car2::lapsDetection()
{
	//Verify if the player are not cheating and take the road
	if ((posX > 350) && (posX < 400) && (posY > 10) && (posY < 160))
	{
		std::cout << "good zone";
		isOnRoad = true;
	}

	//Checking finishing line and increment laps
	else if ((posX > 350) && (posX < 400) && (posY > 430) && (posY < 550))
	{

		if (isOnRoad)
		{
			std::cout << "finish line";
			isOnRoad = false;
			nbLaps++;
			std::cout << nbLaps;
		}
	}
}

//update position, rotation and collisions of the player

void Car2::update()
{
	objectDimensions.y = posY;
	objectDimensions.x = posX;
	collisionDetection();
	lapsDetection();


	if (rotation >= (twoPi))
	{
		rotation = 0;
	}
	if (rotation <= -twoPi)
	{
		rotation = 0;
	}

	if (powerSpeed >= maxPowerSpeed)
	{
		powerSpeed = maxPowerSpeed;
	}

	if (powerSpeed <= 0.0f)
	{
		powerSpeed = 0.0f;
	}

	//powerSpeed -= 0.02f;
	//std::cout << powerSpeed;
	//std::cout << rotation;
	//std::cout << maxPowerSpeed;
}

//Player move

void Car2::move(std::string direction)
{

	if (direction == "forward")
	{
		maxPowerSpeed = 4.0f;
		powerSpeed += 0.05f;
		posY -= Maths::sin(rotation) * powerSpeed;
		posX += Maths::cos(rotation) * powerSpeed;
	}

	else if (direction == "backward")
	{
		maxPowerSpeed = 2.5f;
		powerSpeed += 0.05f;
		posY += Maths::sin(rotation) * powerSpeed;
		posX -= Maths::cos(rotation) * powerSpeed;
	}

	else if (direction == "right")
	{
		rotation -= 0.012 * pi;
		angleRotation += pi / 1.455;
	}

	else if (direction == "left")
	{
		rotation += 0.012 * pi;
		angleRotation -= pi / 1.455;
	}
}

Vector2 Car2::getForward() const
{
	return Vector2(Maths::cos(rotation), -Maths::sin(rotation));
}

int Car2::getMaxSpeed()
{
	return maxPowerSpeed;
}

int Car2::getSpeed()
{
	return powerSpeed;
}

int Car2::getRotationSpeed()
{
	return rotationSpeed;
}

float Car2::getRotation()
{
	return rotation;
}

int Car2::getPi()
{
	return pi;
}

int Car2::getTwoPi()
{
	return twoPi;
}

int Car2::getNbLaps()
{
	return nbLaps;
}
