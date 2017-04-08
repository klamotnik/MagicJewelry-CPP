#pragma once

#include "Engine\Types\MenuElement.h"

class ExitMenuElement : public MenuElement
{
public:
	ExitMenuElement(char* name, char* caption) : MenuElement(name, caption) {
	}
	virtual ~ExitMenuElement() {}
	void Interact(SDL_Event* e) override {

	}
};

