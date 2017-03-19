#include <algorithm>
#include "Engine\Types\MenuContainer.h"
#include "Engine\GraphicLibrary.h"

using namespace std;

MenuContainer::MenuContainer()
{
}


MenuContainer::~MenuContainer()
{
}

bool MenuContainer::AddElement(char* name, char* caption)
{
	MenuElement* me = nullptr;
	if(menuElements.begin() != menuElements.end())
	{
		me = menuElements.find(name)->second;
		if(me)
			return false;
	}
	menuElements[name] = new MenuElement(name, caption);
	int w = 0, h = 0;
	for(pair<char*, MenuElement*> pair : menuElements)
	{
		Viewport* elementViewport = pair.second->GetViewport();
		h += elementViewport->GetSurface()->h;
		w += elementViewport->GetSurface()->w;
	}
	delete viewport;
	viewport = new Viewport({ 0,200, w, h });
	needRefresh = true;
	return true;
}

bool MenuContainer::RemoveElement(char* name)
{
	map<char*, MenuElement*>::iterator pair = menuElements.find(name);
	if (pair == menuElements.end())
		return false;
	menuElements.erase(pair);
	needRefresh = true;
	return true;
}

void MenuContainer::ClearMenu()
{
	menuElements.clear();
	needRefresh = true;
}

bool MenuContainer::NeedRefresh()
{
	for (pair<char*, MenuElement*> pair : menuElements)
		if (pair.second->NeedRefresh())
			needRefresh = true;
	if (needRefresh)
	{
		Refresh();
		needRefresh = false;
		return true;
	}
	return false;
}

void MenuContainer::Refresh()
{
	for(pair<char*, MenuElement*> pair : menuElements)
	{
		GraphicLibrary::DrawOnViewport(pair.second, viewport);
	}
}

Viewport * MenuContainer::GetViewport()
{
	return viewport;
}
