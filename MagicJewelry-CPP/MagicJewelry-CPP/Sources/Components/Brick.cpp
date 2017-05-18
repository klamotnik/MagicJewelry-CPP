#include "Components\Brick.h"

#ifdef DEBUG
Viewport** Brick::sprites = new Viewport*[9]
{
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/bricks/b_0.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/bricks/b_1.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/bricks/b_2.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/bricks/b_3.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/bricks/b_4.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/bricks/b_5.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/bricks/b_6.png")
};
#else
Viewport** Brick::sprites = new Viewport*[9]{
	Viewport::LoadSprite("gfx/bricks/b_0.png"),
	Viewport::LoadSprite("gfx/bricks/b_1.png"),
	Viewport::LoadSprite("gfx/bricks/b_2.png"),
	Viewport::LoadSprite("gfx/bricks/b_3.png"),
	Viewport::LoadSprite("gfx/bricks/b_4.png"),
	Viewport::LoadSprite("gfx/bricks/b_5.png"),
	Viewport::LoadSprite("gfx/bricks/b_6.png")
};
#endif

Brick::Brick(int X, int Y, BrickColor Color) : Actor(new Viewport({ X, Y, 30, 30 }))
{
	viewport->Draw(sprites[Color]);
}


Brick::~Brick()
{
}
