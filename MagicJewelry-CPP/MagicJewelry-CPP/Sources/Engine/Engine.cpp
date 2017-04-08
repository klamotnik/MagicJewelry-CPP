#include <ctime>
#include "Engine\Engine.h"
#include "Components\Levels\MainMenu.h"
#include "Engine\LevelManager.h"

Engine::Engine()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = new Window(640, 480, "Magic Jewelry");
	event = new SDL_Event();
	endGame = false;
}

Engine::~Engine()
{
	delete window;
	SDL_Quit();
}

void Engine::Start()
{
	srand(time(nullptr));
	LevelManager* levelManager = LevelManager::GetInstance();
	while (!endGame)
	{
		//sprawdzenie klawiatury/myszy i rozgloszenie eventow
		while (SDL_PollEvent(event))
		{
			if (event->type == SDL_QUIT)
				endGame = true;
			else
				levelManager->GetCurrentLevel()->Interact(event);
		}
		//rozgloszenie ticka zostalo przeniesione do refresha levelu
		levelManager->GetCurrentLevel()->Refresh();
		if (window->GetWindowSurface())
		{
			window->DrawOnScreen(levelManager->GetCurrentLevel()->GetViewport());
		}
		SDL_Delay(20);
	}
}