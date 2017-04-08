#include "Components\Menus\Elements\PlayMenuElement.h"
#include "Engine\LevelManager.h"
#include "Components\Levels\Game.h"

PlayMenuElement::PlayMenuElement(char* name, char* caption) : MenuElement(name, caption)
{

}


PlayMenuElement::~PlayMenuElement()
{
}

void PlayMenuElement::Interact(SDL_Event* e)
{
	LevelManager::GetInstance()->ChangeLevel<Game>();
}
