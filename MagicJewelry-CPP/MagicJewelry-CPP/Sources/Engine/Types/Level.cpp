#include <algorithm>
#include "Engine\Types\Level.h"
#include "Engine\GraphicLibrary.h"

using namespace std;

Level::Level(Viewport* viewport)
{
	this->viewport = viewport;
	ticker = new Ticker();
}

void Level::Refresh()
{
	ticker->Broadcast();
	for (Actor* actor : actorList)
		if (actor->NeedRefresh())
			GraphicLibrary::DrawOnViewport(actor, this);
}

bool Level::NeedRefresh()
{
	for (Actor* actor : actorList)
		if (actor->NeedRefresh())
			return true;
	return false;
}

Viewport* Level::GetViewport()
{
	return viewport;
}

Ticker * Level::GetTicker()
{
	return ticker;
}

void Level::AddActor(Actor* actor)
{
	if (actor == nullptr)
		return;
	actorList.insert(actorList.end(), actor);
	ticker->Subscribe(actor);
}

void Level::RemoveActor(Actor* actor)
{
	if (actor == nullptr)
		return;
	if (find(actorList.begin(), actorList.end(), actor) == actorList.end())
		return;
	ticker->Unsubscribe(actor);
	actorList.remove(actor);
	delete actor;
}
