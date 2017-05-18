#include "Components\Levels\MainMenu.h"
#include "Components\Logo.h"
#include "Engine\LevelManager.h"
#include "Components\Levels\Game.h"
#include "Components\Levels\Scores.h"

MainMenu::MainMenu(Viewport* viewport) : Level(viewport)
{
	AddActor(new Logo(165, 75, true));
	menuContainer = new MenuContainer();
	AddActor(menuContainer);
	menuContainer->AddElement("1play", "Graj", [](SDL_Event* e) {LevelManager::GetInstance()->ChangeLevel<Game>(); });
	menuContainer->SetActiveElement("1play");
	menuContainer->AddElement("2scores", "Wyniki", [](SDL_Event* e) {LevelManager::GetInstance()->ChangeLevel<Scores>(); });
	menuContainer->AddElement("3end", "Koniec");
}

void MainMenu::Interact(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
		case SDLK_DOWN: 
		case SDLK_UP: 
		case SDLK_RETURN:
			if(menuContainer->CanInteract())
				menuContainer->Interact(event);
			break;
		}
	}
}