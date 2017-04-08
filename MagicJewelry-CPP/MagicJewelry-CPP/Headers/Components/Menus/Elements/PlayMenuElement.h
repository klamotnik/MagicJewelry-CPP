#pragma once

#include "Engine\Types\MenuElement.h"

class PlayMenuElement : public MenuElement
{
public:
	PlayMenuElement(char* name, char* caption);
	virtual ~PlayMenuElement();
	void Interact(SDL_Event* e) override;
};

