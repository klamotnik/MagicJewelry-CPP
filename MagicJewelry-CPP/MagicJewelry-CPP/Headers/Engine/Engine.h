#pragma once

#include <SDL.h>
#include "Window.h"

class Engine
{
public:
	Engine();
	~Engine();
	void Start();
private:
	Window* window;
	SDL_Event* event;
	bool endGame;
};

