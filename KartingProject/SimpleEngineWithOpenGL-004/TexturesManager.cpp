#include "TexturesManager.h"
#include <SDL_ttf.h>


SDL_Texture* TexturesManager::loadTexture(const char *filepath, SDL_Renderer *ren)
{
	SDL_Surface *temp = IMG_Load(filepath);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, temp);
	SDL_FreeSurface(temp);
	return tex;
}

SDL_Texture* TexturesManager::loadText(const char* textToRender, SDL_Color color, int fontSize, SDL_Renderer* ren)
{
	return nullptr;
}
