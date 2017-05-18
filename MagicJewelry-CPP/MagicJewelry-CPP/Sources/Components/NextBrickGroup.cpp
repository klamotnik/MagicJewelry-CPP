#include <cstdlib>
#include "Components\NextBrickGroup.h"

NextBrickGroup::NextBrickGroup(int X, int Y) : Actor(new Viewport({ X, Y, 30, 90 }))
{
	DrawNextGroup();
}

NextBrickGroup::~NextBrickGroup()
{
}

Brick** NextBrickGroup::DrawNextGroup()
{
	Brick* bricksToReturn[3] = { nextBrickGroup[0], nextBrickGroup[1], nextBrickGroup[2] };
	for(int i = 0; i < 3; ++i)
		nextBrickGroup[i] = new Brick(0, 30 * i, static_cast<Brick::BrickColor>(rand() % 6 + 1));
	needRefresh = true;
	return bricksToReturn;
}

bool NextBrickGroup::CanInteract()
{
	return false;
}

bool NextBrickGroup::NeedRefresh()
{
	if (needRefresh)
	{
		Refresh();
		needRefresh = false;
		return true;
	}
	return false;
}

void NextBrickGroup::Refresh()
{
	viewport->Clear();
	for (int i = 0; i < 3; ++i) 
	{
		nextBrickGroup[i]->Move(0, 60 - i * 30, true);
		viewport->Draw(nextBrickGroup[i]->GetViewport());
	}
}