#pragma once

#include "Engine\Types\Actor.h"
#include "Components\Brick.h"

class NextBrickGroup : public Actor
{
public:
	NextBrickGroup(int X, int Y);
	virtual ~NextBrickGroup();
	Brick** DrawNextGroup();
	virtual bool CanInteract() override;
	virtual bool NeedRefresh() override;
	virtual void Refresh() override;
private:
	Brick* nextBrickGroup[3];
};

