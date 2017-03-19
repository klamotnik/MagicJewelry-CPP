#pragma once

#include <list>
#include "Interfaces\IRenderable.h"
#include "Engine\Types\Visitors\Ticker.h"
#include "Engine\Types\Actor.h"

using namespace std;

class Level : public IRenderable
{
public:
	void Refresh() override;
	bool NeedRefresh() override;
	Viewport* GetViewport() override;
	Ticker* GetTicker();
	void CheckEvents();
	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);
protected:
	Level(Viewport* viewport);
	Ticker* ticker;
	list<Actor*> actorList;
};

