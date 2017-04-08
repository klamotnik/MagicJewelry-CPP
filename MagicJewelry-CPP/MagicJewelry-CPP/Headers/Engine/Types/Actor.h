#pragma once
#define DEBUG
#include "Interfaces\IRenderable.h"
#include "Interfaces\ITickable.h"
#include "Interfaces\IInteractable.h"

class Actor : public IRenderable, public ITickable, public IInteractable
{
public:
	virtual bool CanInteract() override;
	virtual void Interact(SDL_Event* event) override;
	virtual void Refresh() override;
	virtual Viewport* GetViewport() override;
	virtual void Tick(int DeltaTime) override;
	virtual bool NeedRefresh() override;
	void Move(int x, int y, bool newPosition = false);
protected:
	static Viewport** sprites;
	bool needRefresh;
	Viewport* viewport;
	Actor();
	Actor(Viewport* viewport);
};

