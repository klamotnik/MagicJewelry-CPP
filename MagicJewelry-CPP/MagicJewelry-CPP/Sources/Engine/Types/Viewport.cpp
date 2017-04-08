#include <SDL_image.h>
#include "Engine\Types\Viewport.h"

///<summary>Creates empty Viewport</summary>
Viewport::Viewport(SDL_Rect properties = { 0, 0, 0, 0 })
{
	surfaceProperties = properties;
	surface = SDL_CreateRGBSurface(0, surfaceProperties.w, surfaceProperties.h, 32, 0, 0, 0, 0xff);
}

///<summary>Creates Viewport based on other Viewport</summary>
Viewport::Viewport(SDL_Surface* surface, int x, int y)
{
	this->surface = surface;
	surfaceProperties = { x, y, surface->w, surface->h };
}
///<summary>Loads an image located in path</summary>
Viewport* Viewport::LoadSprite(const char* path, SDL_Rect position)
{
	return new Viewport(IMG_Load(path), position.x, position.y);
}

///<summary>Draw Viewport on this Viewport</summary>
void Viewport::Draw(Viewport* const &objectToDraw)
{
	SDL_UpperBlit(objectToDraw->surface, nullptr, surface, &objectToDraw->surfaceProperties);
}

///<summary>Fill the Viewport with black</summary>
void Viewport::Clear()
{
	SDL_FillRect(surface, &surfaceProperties, 0);
}

SDL_Surface* Viewport::GetSurface() {
	return surface;
}

SDL_Rect* Viewport::GetProperties() {
	return &surfaceProperties;
}

int Viewport::GetWidth()
{
	return surfaceProperties.w;
}

int Viewport::GetHeight()
{
	return surfaceProperties.h;
}

int Viewport::GetX()
{
	return surfaceProperties.x;
}

int Viewport::GetY()
{
	return surfaceProperties.y;
}