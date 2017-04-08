#include "Components\Levels\MainMenu.h"
#include "Components\Logo.h"
#include "Components\Menus\Elements\PlayMenuElement.h"
#include "Components\Menus\Elements\ScoresMenuElement.h"
#include "Components\Menus\Elements\ExitMenuElement.h"

MainMenu::MainMenu(Viewport* viewport) : Level(viewport)
{
	AddActor(new Logo(100, 50, true));
	//logo->Move(logo->GetViewport()->get);
	menuContainer = new MenuContainer();
	AddActor(menuContainer);

	menuContainer->AddElement<PlayMenuElement>("1play", "Graj");
	menuContainer->SetActiveElement("1play");
	menuContainer->AddElement<ScoresMenuElement>("2scores", "Wyniki");
	menuContainer->AddElement<ExitMenuElement>("3end", "Koniec");
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