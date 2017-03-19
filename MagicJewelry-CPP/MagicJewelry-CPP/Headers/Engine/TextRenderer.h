#pragma once

#define DEBUG

#include <SDL_ttf.h>
#include "Engine\Types\Viewport.h"

class TextRenderer
{
public:
	static TextRenderer* GetInstance();
	Viewport* RenderText(const char* textToRender);
private:
	TextRenderer();
	static TextRenderer* textRenderer; 
	static TTF_Font* font;
};

