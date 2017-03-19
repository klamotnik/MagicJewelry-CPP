#pragma once

#include <SDL.h>

class Viewport
{
public:
	Viewport(SDL_Rect properties);
	Viewport(SDL_Surface* surface, int x = 0, int y = 0);
	~Viewport();
	SDL_Surface* GetSurface();
	SDL_Rect GetProperties();
private:
	SDL_Rect surfaceProperties;
	SDL_Surface* surface;
};

