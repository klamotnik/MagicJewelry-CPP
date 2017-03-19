#pragma once

class IInteractable
{
public:
	virtual bool CanInteract() = 0;
	virtual void Interact() = 0;
};