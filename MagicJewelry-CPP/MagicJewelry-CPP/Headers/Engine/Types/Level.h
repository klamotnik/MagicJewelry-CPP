#pragma once

#include <list>
#include "Interfaces\IRenderable.h"
#include "Interfaces\IInteractable.h"
#include "Engine\Types\Visitors\Ticker.h"
#include "Engine\Types\Actor.h"

using namespace std;

class Level : public IRenderable, public IInteractable
{
public:
	virtual ~Level();
	void Refresh() override;
	bool NeedRefresh() override;
	Viewport* GetViewport() override;
	Ticker* GetTicker();
	virtual bool CanInteract();
	virtual void Interact(SDL_Event* event);
	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);
protected:
	Level(Viewport* viewport);
	Ticker* ticker;
	list<Actor*> actorList;
};

