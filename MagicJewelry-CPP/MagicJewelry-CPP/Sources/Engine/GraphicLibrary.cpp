#include <SDL_image.h>
#include "Engine\GraphicLibrary.h"

GraphicLibrary::GraphicLibrary()
{
}


void GraphicLibrary::DrawOnViewport(Viewport* Source, Viewport* Destination)
{
	SDL_UpperBlit(Source->GetSurface(), nullptr, Destination->GetSurface(), &Source->GetProperties());
}

void GraphicLibrary::DrawOnViewport(IRenderable* Source, Viewport* Destination)
{
	DrawOnViewport(Source->GetViewport(), Destination);
}

void GraphicLibrary::DrawOnViewport(IRenderable * Source, IRenderable * Destination)
{
	DrawOnViewport(Source->GetViewport(), Destination->GetViewport());
}

void GraphicLibrary::DrawOnScreen(Viewport* Source, Window* Destination)
{
	SDL_UpperBlit(Source->GetSurface(), nullptr, Destination->GetWindowSurface(), &Source->GetProperties());
}

void GraphicLibrary::DrawOnScreen(IRenderable* Source, Window* Destination)
{
	DrawOnScreen(Source->GetViewport(), Destination);
}

Viewport* GraphicLibrary::LoadSprite(const char* path, SDL_Rect position)
{
	return new Viewport(IMG_Load(path), position.x, position.y);
}

void GraphicLibrary::UpdateScreen(Window* UpdatingWindow) 
{
	SDL_UpdateWindowSurface(UpdatingWindow->GetWindow());
}