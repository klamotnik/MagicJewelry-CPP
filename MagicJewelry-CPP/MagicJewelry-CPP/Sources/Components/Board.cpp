#include "Components\Board.h"

#ifdef DEBUG
Viewport** Board::sprites = new Viewport*[9]
{
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/board/board0.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/board/board1.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/board/board2.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/board/board3.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/board/board4.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/board/board5.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/board/board6.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/board/board7.png")
};
#else
Viewport** Brick::sprites = new Viewport*[9]{
	Viewport::LoadSprite("gfx/board/board0.png"),
	Viewport::LoadSprite("gfx/board/board1.png"),
	Viewport::LoadSprite("gfx/board/board2.png"),
	Viewport::LoadSprite("gfx/board/board3.png"),
	Viewport::LoadSprite("gfx/board/board4.png"),
	Viewport::LoadSprite("gfx/board/board5.png"),
	Viewport::LoadSprite("gfx/board/board6.png"),
	Viewport::LoadSprite("gfx/board/board7.png")
};
#endif

Board::Board(int X, int Y) : Actor(new Viewport({ X, Y, 230, 469 }))
{
	viewport->Draw(sprites[0]);
}

Board::~Board()
{
}

void Board::Tick(int deltaTime)
{
}

void Board::MoveBoardActor(int oldX, int oldY, int newX, int newY)
{
	if (boardActors[newY][newX] == nullptr)
	{
		boardActors[newY][newX] = boardActors[oldY][oldX];
		boardActors[oldY][oldX] = nullptr;
	}
}

bool Board::CanMoveBoardActor(int newX, int newY)
{
	if (newX >= 0 && newX < 7 && newY >= 0 && boardActors[newY][newX] == nullptr)
		return true;
	return false;
}

void Board::Interact(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
		case SDLK_DOWN:
			if (CanMoveBoardActor(currentX, currentY - 1))
			{
				MoveBoardActor(currentX, currentY, currentX, currentY - 1);
				MoveBoardActor(currentX, currentY + 1, currentX, currentY);
				MoveBoardActor(currentX, currentY + 2, currentX, currentY + 1);
			}
			break;
		case SDLK_LEFT:
			if (CanMoveBoardActor(currentX - 1, currentY))
			{
				MoveBoardActor(currentX, currentY, currentX - 1, currentY);
				MoveBoardActor(currentX, currentY + 1, currentX - 1, currentY + 1);
				MoveBoardActor(currentX, currentY + 2, currentX - 1, currentY + 2);
			}
			break;
		case SDLK_RIGHT:
			if (CanMoveBoardActor(currentX + 1, currentY))
			{
				MoveBoardActor(currentX, currentY, currentX + 1, currentY);
				MoveBoardActor(currentX, currentY + 1, currentX + 1, currentY + 1);
				MoveBoardActor(currentX, currentY + 2, currentX + 1, currentY + 2);
			}
			break;
			needRefresh = true;
		}
	}
}
