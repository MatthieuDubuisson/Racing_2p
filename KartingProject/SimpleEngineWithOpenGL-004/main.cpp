#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Game.h"

using namespace std;

int main(int arc, char** argv)
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart;
	int frameTime;

	Game* game = new Game();
	game->init("Kart Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->processInput();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	return 0;
}