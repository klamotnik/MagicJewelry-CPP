#pragma once

#include <SDL.h>

class Viewport
{
public:
	Viewport(SDL_Rect properties);
	Viewport(SDL_Surface* surface, int x = 0, int y = 0);
	static Viewport* LoadSprite(const char* path, SDL_Rect position = { 0, 0, 0, 0 });
	void Draw(Viewport* const &objectToDraw);
	void Clear();
	SDL_Surface* GetSurface();
	SDL_Rect* GetProperties();
	int GetWidth();
	int GetHeight();
	int GetX();
	int GetY();
private:
	SDL_Rect surfaceProperties;
	SDL_Surface* surface;
};

