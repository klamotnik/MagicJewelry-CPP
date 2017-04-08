#include "Components\Menus\Elements\ScoresMenuElement.h"
#include "Engine\LevelManager.h"
#include "Components\Levels\Scores.h"

ScoresMenuElement::ScoresMenuElement(char* name, char* caption) : MenuElement(name, caption)
{
}

ScoresMenuElement::~ScoresMenuElement()
{
}

void ScoresMenuElement::Interact(SDL_Event * e)
{
	LevelManager::GetInstance()->ChangeLevel<Scores>();
}
