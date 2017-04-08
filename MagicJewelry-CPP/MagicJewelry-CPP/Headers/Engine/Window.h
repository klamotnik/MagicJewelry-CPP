#pragma once

#include <string>
#include <SDL.h>
#include "Engine\Types\Viewport.h"

using namespace std;

class Window
{
public:
	Window(int Width, int Height, string Title);
	~Window();
	SDL_Surface* GetWindowSurface();
	SDL_Window* GetWindow();
	void DrawOnScreen(Viewport* viewportToDraw);
private:
	SDL_Surface* windowSurface;
	SDL_Window* window;
	string title;
};

