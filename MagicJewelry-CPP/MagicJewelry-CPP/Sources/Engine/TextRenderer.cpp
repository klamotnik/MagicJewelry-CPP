#include "..\..\Headers\Engine\TextRenderer.h"

TextRenderer* TextRenderer::textRenderer = nullptr;
TTF_Font* TextRenderer::font = nullptr;

TextRenderer* TextRenderer::GetInstance(Color color)
{
	if(textRenderer == nullptr)
	{
		TTF_Init();
		textRenderer = new TextRenderer();
		if(font == nullptr)
		{
			#ifdef DEBUG
			TextRenderer::font = TTF_OpenFont("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/font/xolonium.ttf", 28);
			#else
			TextRenderer::font = TTF_OpenFont("font/impact.ttf", 12);
			#endif
		}
	}
	textRenderer->currentColor->r = color | 0x000000FF;
	textRenderer->currentColor->g = color | 0x0000FF00;
	textRenderer->currentColor->b = color | 0x00FF0000;
	textRenderer->currentColor->a = color | 0xFF000000;
	return textRenderer;
}

Viewport* TextRenderer::RenderText(const char * textToRender)
{
	return new Viewport(TTF_RenderText_Shaded(font, textToRender, *currentColor, { 0 }));
}

TextRenderer::TextRenderer()
{
	currentColor = new SDL_Color();
}
