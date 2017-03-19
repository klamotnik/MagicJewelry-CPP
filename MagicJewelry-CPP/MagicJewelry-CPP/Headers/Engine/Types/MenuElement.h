#pragma once

#include "Actor.h"
#include "Engine\Types\MenuContainer.h"

class MenuElement : public Actor
{
public:
	MenuElement(char* name, char* caption);
	~MenuElement();
private:
	char* Name;
	char* Caption; 
	//MenuContainer* Parent;
};

