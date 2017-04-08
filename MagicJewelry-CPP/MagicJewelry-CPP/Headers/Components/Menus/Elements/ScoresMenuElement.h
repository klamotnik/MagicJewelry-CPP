#pragma once

#include "Engine\Types\MenuElement.h"

class ScoresMenuElement : public MenuElement
{
public:
	ScoresMenuElement(char* name, char* caption);
	~ScoresMenuElement();
	void Interact(SDL_Event* e) override;
};

