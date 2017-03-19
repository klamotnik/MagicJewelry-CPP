#include <ctime>
#include <SDL.h>
#include "Engine\Game.h"
#include "Engine\GraphicLibrary.h"
#include "Components\Levels\MainMenu.h"

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->window = new Window(640, 480, "Window");
}

Game::~Game()
{
	delete window;
	SDL_Quit();
}

void Game::Start() 
{
	srand(time(nullptr));
	Level* mainMenu = new MainMenu(new Viewport({ 0, 0, 640, 480 }));
	while (true) 
	{
		//rozgloszenie ticka zostalo przeniesione do refresha levelu
		mainMenu->Refresh(); 
		if(window->GetWindowSurface())
		{
			GraphicLibrary::DrawOnScreen(mainMenu, window);
			GraphicLibrary::UpdateScreen(window);
		}
		SDL_Delay(20);
	}
}