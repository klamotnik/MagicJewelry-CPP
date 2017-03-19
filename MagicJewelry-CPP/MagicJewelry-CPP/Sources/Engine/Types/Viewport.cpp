#include "Engine\Types\Viewport.h"

Viewport::Viewport(SDL_Rect properties = { 0, 0, 0, 0 })
{
	surfaceProperties = properties;
	surface = SDL_CreateRGBSurface(0, surfaceProperties.w, surfaceProperties.h, 32, 0, 0, 0, 0xff);
}

Viewport::Viewport(SDL_Surface* surface, int x, int y)
{
	this->surface = surface;
	surfaceProperties = { x, y, surface->w, surface->h };
}

Viewport::~Viewport()
{
}

SDL_Surface* Viewport::GetSurface() {
	return surface;
}

SDL_Rect Viewport::GetProperties() {
	return surfaceProperties;
}