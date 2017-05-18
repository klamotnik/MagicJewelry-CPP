#include "Engine\Types\MenuElement.h"
#include "Engine\TextRenderer.h"
#include "Engine\LevelManager.h"

MenuElement::MenuElement(char* name, char* caption, void (*action)(SDL_Event*))
{
	Name = name;
	Caption = caption;
	Action = action;
	viewport = TextRenderer::GetInstance(TextRenderer::Color::WHITE)->RenderText(Caption);
	needRefresh = false;
}

void MenuElement::SetActive(bool active)
{
	this->active = active;
	needRefresh = true;
}

void MenuElement::Refresh()
{
	delete viewport;
	viewport = TextRenderer::GetInstance(active ? TextRenderer::Color::RED : TextRenderer::Color::WHITE)->RenderText(Caption);
	needRefresh = false;
}

bool MenuElement::NeedRefresh() {
	return needRefresh;
}

void MenuElement::Interact(SDL_Event* e)
{
	if(Action != nullptr)
		(*Action)(e);
}
