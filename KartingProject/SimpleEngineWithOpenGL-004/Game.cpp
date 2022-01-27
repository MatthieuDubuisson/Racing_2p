#include <iostream>
#include "Game.h"
#include "Car.h"
#include "Car2.h"
#include "TexturesManager.h"
#include <SDL.h>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

//Game constructor
Game::Game()
{
}

Game::~Game()
{
}

	//init players and textures
Car *car;
Car2 *car2;
const Uint8* keyState;
SDL_Texture* playerTexture;
SDL_Texture* player2Texture;

SDL_Texture* backgroundTexture;

SDL_Texture* maxLapsTexture;
SDL_Texture* j1Lap;
SDL_Texture* j2Lap;
SDL_Texture* winTexture;

SDL_Rect backgroundRect, scrRect, maxLapsRect, j1LapsRect, j2LapsRect, winRect;
std::string bg;
std::string playerSpritePath;

		// set when the game start
void Game::init(const char* title, int posX, int posY, int width, int height)
{
	//initialize window
	if (SDL_INIT_EVERYTHING)
	{
		window = SDL_CreateWindow("Kart Game", posX, posY, width, height, 0);
		isRunning = true;
		renderer = SDL_CreateRenderer(window, -1, 0);
	}

	//Verifications
	if (window)
	{
		cout << "Window has been initialized !\n";
	}

	if (renderer)
	{
		cout << "Renderer has been created ! \n";
	}

	else
	{
		isRunning = false;
	}

		//Load textures when start

	//background
	bg = "Resources\\RaceBackground.png";
	backgroundTexture = TexturesManager::loadTexture(bg.c_str(), renderer);
	scrRect.w = 800;
	scrRect.h = 600;
	backgroundRect.w = 800;
	backgroundRect.h = 600;

	//player1
	playerSpritePath = "Resources\\player1Car.png";
	car = new Car(playerSpritePath.c_str(), renderer, 270, 460);
	car->setSize(30,60);

	//player2
	playerSpritePath = "Resources\\player2Car.png";
	car2 = new Car2(playerSpritePath.c_str(), renderer, 301, 528);
	car2->setSize(30, 60);

	//Laps counter
	maxLapsTexture = TexturesManager::loadTexture("Resources\\maxLaps.png", renderer);
	maxLapsRect.w = 83;
	maxLapsRect.h = 60;
	maxLapsRect.x = 360;
	maxLapsRect.y = 355;

	j1Lap = TexturesManager::loadTexture("Resources\\J1Lap0.png", renderer);
	j1LapsRect.w = 35;
	j1LapsRect.h = 35;
	j1LapsRect.x = 360;
	j1LapsRect.y = 353;

	j2Lap = TexturesManager::loadTexture("Resources\\J2Lap0.png", renderer);
	j2LapsRect.w = 35;
	j2LapsRect.h = 35;
	j2LapsRect.x = 360;
	j2LapsRect.y = 381;

	//win message position
	winRect.w = 200;
	winRect.h = 100;
	winRect.x = 300;
	winRect.y = 221;
}


void Game::processInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
			isRunning = false;
			break;
	default:
		break;
	}

	//keyboard state
	keyState = SDL_GetKeyboardState(NULL);

// Player1 inputs
	if (keyState[SDL_SCANCODE_W])
	{
		car->move("forward");
	}

	if (keyState[SDL_SCANCODE_S])
	{
		car->move("backward");
	}

	if (keyState[SDL_SCANCODE_D])
	{
		car->move("right");
	}

	if (keyState[SDL_SCANCODE_A])
	{
		car->move("left");
	}

//Player2 inputs
	if (keyState[SDL_SCANCODE_UP])
	{
		car2->move("forward");
	}

	if (keyState[SDL_SCANCODE_DOWN])
	{
		car2->move("backward");
	}

	if (keyState[SDL_SCANCODE_RIGHT])
	{
		car2->move("right");
	}

	if (keyState[SDL_SCANCODE_LEFT])
	{
		car2->move("left");
	}
}

void Game::update()
{

//Players update

	car->update();
	car2->update();

//Player1 counter update

	if (car->getNbLaps() == 1)
	{
		j1Lap = TexturesManager::loadTexture("Resources\\J1Lap1.png", renderer);
	}

	if (car->getNbLaps() == 2)
	{
		j1Lap = TexturesManager::loadTexture("Resources\\J1Lap2.png", renderer);
	}

	if (car->getNbLaps() == 3)
	{
		j1Lap = TexturesManager::loadTexture("Resources\\J1Lap3.png", renderer);
	}
	if (car->getNbLaps() == 4)
	{
		j1Lap = TexturesManager::loadTexture("Resources\\J1Lap4.png", renderer);
	}

	if (car->getNbLaps() == 5)
	{
		j1Lap = TexturesManager::loadTexture("Resources\\J1Lap5.png", renderer);
	}

	if ((car->getNbLaps()>= 6) && (car->getNbLaps() > car2->getNbLaps()))
	{
		//cout << "\n\n Red Player win";
		winTexture = TexturesManager::loadTexture("Resources\\j1win.png", renderer);
	}

//Player2 counter update

	if (car2->getNbLaps() == 1)
	{
		j2Lap = TexturesManager::loadTexture("Resources\\J2Lap1.png", renderer);
	}

	if (car2->getNbLaps() == 2)
	{
		j2Lap = TexturesManager::loadTexture("Resources\\J2Lap2.png", renderer);
	}

	if (car2->getNbLaps() == 3)
	{
		j2Lap = TexturesManager::loadTexture("Resources\\J2Lap3.png", renderer);
	}
	if (car2->getNbLaps() == 4)
	{
		j2Lap = TexturesManager::loadTexture("Resources\\J2Lap4.png", renderer);
	}

	if (car2->getNbLaps() == 5)
	{
		j2Lap = TexturesManager::loadTexture("Resources\\J2Lap5.png", renderer);
	}

	if ((car2->getNbLaps() >= 6) && (car2->getNbLaps() > car->getNbLaps()))
	{
		//cout << "\n\n Blue Player win";
		winTexture = TexturesManager::loadTexture("Resources\\j2win.png", renderer);
	}
}

//Draw all textures

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTexture, &scrRect, &backgroundRect);
	SDL_RenderCopy(renderer, maxLapsTexture, NULL, &maxLapsRect);
	SDL_RenderCopy(renderer, j1Lap, NULL, &j1LapsRect);
	SDL_RenderCopy(renderer, j2Lap, NULL, &j2LapsRect);
	SDL_RenderCopy(renderer, winTexture, NULL, &winRect);
	car->render();
	car2->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
}

bool Game::running()
{
	return isRunning;
}
