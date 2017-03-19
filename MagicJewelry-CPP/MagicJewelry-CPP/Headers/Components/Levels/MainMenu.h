#pragma once

#include "Engine\Types\Level.h"
#include "Engine\Types\MenuContainer.h"

class MainMenu : public Level
{
public:
	MainMenu(Viewport* viewport);
private:
	MenuContainer* menuContainer;
};

