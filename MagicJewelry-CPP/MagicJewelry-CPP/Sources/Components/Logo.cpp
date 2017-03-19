#include <cstdlib>
#include "Components\Logo.h"
#include "Engine\GraphicLibrary.h"

using namespace std;

#ifdef DEBUG
Viewport** Logo::sprites = new Viewport*[9]{
	GraphicLibrary::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/0.png"),
	GraphicLibrary::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/1.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/2.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/3.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/4.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/5.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/6.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/7.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/gfx/logo/8.png", { 2, 2 })
};
#else
Viewport** Logo::sprites = new Viewport*[9]{
	GraphicLibrary::LoadSprite("gfx/logo/0.png"),
	GraphicLibrary::LoadSprite("gfx/logo/1.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("gfx/logo/2.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("gfx/logo/3.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("gfx/logo/4.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("gfx/logo/5.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("gfx/logo/6.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("gfx/logo/7.png", { 2, 2 }),
	GraphicLibrary::LoadSprite("gfx/logo/8.png", { 2, 2 })
};
#endif

Logo::Logo(int X, int Y, bool Animate = false) : Actor(new Viewport({ X, Y, 311, 122 }))
{
	animate = Animate;
	currentColor = LogoColor::Orange;
	timeFromChange = 0;
	GraphicLibrary::DrawOnViewport(sprites[0], GetViewport());
	GraphicLibrary::DrawOnViewport(sprites[currentColor], GetViewport());
}

void Logo::Tick(int deltaTime) 
{
	if(animate) 
	{
		timeFromChange += deltaTime;
		if(timeFromChange > 500)
		{
			while(!ChangeColor(static_cast<Logo::LogoColor>(rand() % 8 + 1)));
			timeFromChange -= 500;
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
	GraphicLibrary::DrawOnViewport(sprites[currentColor], GetViewport());
	Actor::Refresh();
}