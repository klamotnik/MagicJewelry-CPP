#pragma once

#define DEBUG

#include <SDL_ttf.h>
#include "Engine\Types\Viewport.h"

class TextRenderer
{
public:
	enum Color { WHITE = 0xFFFFFFFF, RED = 0xFF000000};
	static TextRenderer* GetInstance(Color color);
	Viewport* RenderText(const char* textToRender);
private:
	TextRenderer();
	static TextRenderer* textRenderer; 
	static TTF_Font* font;
	SDL_Color* currentColor;
};

