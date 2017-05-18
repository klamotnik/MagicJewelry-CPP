#pragma once

#include "Engine\Types\Actor.h"

class MenuElement : public Actor
{
public:
	MenuElement(char* name, char* caption, void(*action)(SDL_Event*) = nullptr);
	void SetActive(bool active);
	virtual void Refresh() override;
	virtual bool NeedRefresh() override;
	virtual void Interact(SDL_Event* e);
private:
	char* Name;
	char* Caption; 
	bool active;
	void (*Action)(SDL_Event* e);
};

