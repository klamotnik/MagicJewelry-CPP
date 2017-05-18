#pragma once

#include "Engine\Types\Level.h"
#include "Components\Logo.h"
#include "Components\Board.h"
#include "Components\NextBrickGroup.h"

class Game : public Level
{
public:
	Game(Viewport* viewport);
private:
	Logo* logo;
	Board* board;
	NextBrickGroup* nextBrickGroup;
};

