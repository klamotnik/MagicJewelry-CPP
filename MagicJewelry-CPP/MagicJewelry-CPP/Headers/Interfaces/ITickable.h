#pragma once

class ITickable 
{
public:
	ITickable() 
	{
		canTick = true;
	}
	virtual bool CanTick() 
	{ 
		return canTick; 
	}
	virtual void Tick(int DeltaTime) = 0;
protected:
	bool canTick;
};