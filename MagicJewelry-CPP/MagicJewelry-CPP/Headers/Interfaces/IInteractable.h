#pragma once

#include <SDL.h>

class IInteractable
{
public:
	virtual bool CanInteract() = 0;
	virtual void Interact(SDL_Event* event) = 0;
};