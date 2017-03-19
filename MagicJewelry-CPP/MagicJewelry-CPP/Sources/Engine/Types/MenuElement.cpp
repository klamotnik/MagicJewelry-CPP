#include "Engine\Types\MenuElement.h"
#include "Engine\TextRenderer.h"
MenuElement::MenuElement(char* name, char* caption)// : Name(name), Caption(caption)
{
	Name = name;
	Caption = caption;
	
	viewport = TextRenderer::GetInstance()->RenderText(Caption);
	needRefresh = true;
}


MenuElement::~MenuElement()
{
}
