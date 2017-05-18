#pragma once
#include "Engine\Types\Actor.h"
class Brick : public Actor
{
public:
	enum BrickColor{Green = 1, Blue = 2, Orange = 3, Violet = 4, Yellow = 5, Red = 6};
	Brick(int X, int Y, BrickColor Color);
	virtual ~Brick();
private:
	static Viewport** sprites;
};

