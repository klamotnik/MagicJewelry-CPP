#pragma once

#include "Engine\Types\Actor.h"

class Board : public Actor
{
public:
	Board(int X, int Y);
	virtual ~Board();
	virtual void Tick(int deltaTime) override;
private:
	void MoveBoardActor(int oldX, int oldY, int newX, int newY);
	bool CanMoveBoardActor(int newX, int newY);
public:
	virtual void Interact(SDL_Event* event);
private:
	static Viewport** sprites;
	Actor* boardActors[17][7]; //two more rows to simplify
	int currentX, currentY;
};

