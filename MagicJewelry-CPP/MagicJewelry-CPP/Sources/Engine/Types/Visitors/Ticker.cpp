#include <ctime>
#include "Engine\Types\Visitors\Ticker.h"
#include "Interfaces\ITickable.h"

Ticker::Ticker() : Broadcaster<ITickable*>()
{
	lastTime = clock();
}

void Ticker::Broadcast() 
{
	int deltaTime = clock() - lastTime;

	for (ITickable* object : broadcastList)
		if (object->CanTick())
			object->Tick(deltaTime);

	lastTime = clock();
}