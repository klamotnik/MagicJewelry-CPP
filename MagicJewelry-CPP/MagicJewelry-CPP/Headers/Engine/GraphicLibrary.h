#pragma once

#include "Interfaces\IRenderable.h"
#include "Types\Viewport.h"
#include "Engine\Window.h"

class GraphicLibrary
{
public:
	static void DrawOnViewport(Viewport* source, Viewport* destination);
	static void DrawOnViewport(IRenderable* source, Viewport* destination);
	static void DrawOnViewport(IRenderable* source, IRenderable* destination);
	static void DrawOnScreen(Viewport* source, Window* destination);
	static void DrawOnScreen(IRenderable* source, Window* destination);
	static Viewport* LoadSprite(const char* path, SDL_Rect position = { 0, 0, 0, 0 });
	static void UpdateScreen(Window* updatingWindow);
private:
	GraphicLibrary();
};

