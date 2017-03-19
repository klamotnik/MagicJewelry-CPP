#include "..\..\Headers\Engine\TextRenderer.h"

TextRenderer* TextRenderer::textRenderer = nullptr;
TTF_Font* TextRenderer::font = nullptr;

TextRenderer* TextRenderer::GetInstance()
{
	if(textRenderer == nullptr)
	{
		TTF_Init();
		textRenderer = new TextRenderer();
		if(font == nullptr)
		{
			#ifdef DEBUG
			TextRenderer::font = TTF_OpenFont("/Projects/MagicJewelry-CPP/MagicJewelry-CPP/Debug/font/impact.ttf", 12);
			#else
			TextRenderer::font = TTF_OpenFont("font/impact.ttf", 12);
			#endif
		}
	}
	return textRenderer;
}

Viewport* TextRenderer::RenderText(const char * textToRender)
{
	return new Viewport(TTF_RenderText_Solid(font, textToRender, { 0xFF, 0xFF, 0xFF, 0xFF }));
}

TextRenderer::TextRenderer()
{
}
