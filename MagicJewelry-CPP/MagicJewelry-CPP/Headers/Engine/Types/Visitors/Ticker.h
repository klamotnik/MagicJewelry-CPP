#pragma once

#include "Engine\Types\Visitors\Abstract\Broadcaster.h"
#include "Interfaces\ITickable.h"

class Ticker : public Broadcaster<ITickable*>
{
public:
	Ticker();
	void Broadcast() override;
private:
	long long lastTime;
};

