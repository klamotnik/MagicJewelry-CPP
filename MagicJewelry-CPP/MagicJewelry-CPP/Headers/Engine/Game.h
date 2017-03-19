#pragma once

#include "Window.h"

class Game
{
public:
	Game();
	~Game();
	void Start();
private:
	Window* window;
};

