#pragma once

#include <string>
#include <SDL.h>
#include "Interfaces\IRenderable.h"

using namespace std;

class Window
{
public:
	Window(int Width, int Height, string Title);
	~Window();
	SDL_Surface* GetWindowSurface();
	SDL_Window* GetWindow();
private:
	SDL_Surface* windowSurface;
	SDL_Window* window;
	string title;
};

