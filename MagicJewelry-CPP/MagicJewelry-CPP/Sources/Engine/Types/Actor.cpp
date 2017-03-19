#include "Engine\Types\Actor.h"

Actor::Actor()
{
	//subskrybcja do Tickera i Renderera
	//ale bez parenta lub level managera to sie chyba nie uda
	//wiec zajmuje sie tym konstruktor konkretnego levela
}

Actor::Actor(Viewport* viewport)
{
	this->viewport = viewport;
}

void Actor::Tick(int DeltaTime)
{

}

bool Actor::CanInteract()
{
	return false;
}

void Actor::Interact()
{
}

void Actor::Refresh()
{
	needRefresh = true;
}

void Actor::Move(int x, int y, bool newPosition) {
	SDL_Rect* rect = &viewport->GetProperties();
	if (newPosition) {
		rect->x = x;
		rect->y = y;
	}
	rect->x += x;
	rect->y += y;
}

Viewport* Actor::GetViewport()
{
	return viewport;
}

bool Actor::NeedRefresh()
{
	return true;
}
