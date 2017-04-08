#include <cstdlib>
#include "Components\Logo.h"

using namespace std;

#ifdef DEBUG
Viewport** Logo::sprites = new Viewport*[9]
{
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/0.png"),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/1.png", { 2, 2 }),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/2.png", { 2, 2 }),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/3.png", { 2, 2 }),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/4.png", { 2, 2 }),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/5.png", { 2, 2 }),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/6.png", { 2, 2 }),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/7.png", { 2, 2 }),
	Viewport::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/8.png", { 2, 2 })
};
#else
Viewport** Logo::sprites = new Viewport*[9]{
	Viewport::LoadSprite("gfx/logo/0.png"),
	Viewport::LoadSprite("gfx/logo/1.png", { 2, 2 }),
	Viewport::LoadSprite("gfx/logo/2.png", { 2, 2 }),
	Viewport::LoadSprite("gfx/logo/3.png", { 2, 2 }),
	Viewport::LoadSprite("gfx/logo/4.png", { 2, 2 }),
	Viewport::LoadSprite("gfx/logo/5.png", { 2, 2 }),
	Viewport::LoadSprite("gfx/logo/6.png", { 2, 2 }),
	Viewport::LoadSprite("gfx/logo/7.png", { 2, 2 }),
	Viewport::LoadSprite("gfx/logo/8.png", { 2, 2 })
};
#endif

Logo::Logo(int X, int Y, bool Animate = false) : Actor(new Viewport({ X, Y, 311, 122 }))
{
	animate = Animate;
	currentColor = LogoColor::Orange;
	timeFromChange = 0;
	viewport->Draw(sprites[0]);
	viewport->Draw(sprites[currentColor]);
}

void Logo::Tick(int deltaTime) 
{
	if(animate) 
	{
		timeFromChange += deltaTime;
		if(timeFromChange > 500)
		{
			while(!ChangeColor(static_cast<Logo::LogoColor>(rand() % 8 + 1)));
			timeFromChange = 0;
		}
	}
}

bool Logo::ChangeColor(Logo::LogoColor Color) {
	if (currentColor == Color)
		return false;
	currentColor = Color;
	Refresh();
	return true;
}

void Logo::Refresh() {
	viewport->Draw(sprites[currentColor]);
	Actor::Refresh();
}