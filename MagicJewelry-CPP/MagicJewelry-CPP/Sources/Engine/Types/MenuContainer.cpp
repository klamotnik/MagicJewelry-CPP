#include <algorithm>
#include "Engine\Types\MenuContainer.h"

using namespace std;

MenuContainer::MenuContainer()
{
	needRefresh = true;
	canInteract = true;
}


MenuContainer::~MenuContainer()
{
	while (!menuElements.empty())
	{
		delete menuElements.begin()->second;
		menuElements.erase(menuElements.begin()->first);
	}
}

bool MenuContainer::CanInteract()
{
	return canInteract;
}

void MenuContainer::Interact(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN)
	{
		map<char*, MenuElement*>::iterator it = menuElements.find(activeElement);
		switch (event->key.keysym.sym)
		{
		case SDLK_DOWN:
			//znajdz nastepny element lub pierwszy
			it->second->SetActive(false);
			if (++it == menuElements.end())
				it = menuElements.begin();
			it->second->SetActive(true);
			break;
		case SDLK_UP:
			//znajdz poprzedni element lub ostatni
			it->second->SetActive(false);
			if (--it == menuElements.end())
				--it;// = --menuElements.end();
			it->second->SetActive(true);
			break;
		case SDLK_RETURN:
			//znajdz poprzedni element lub ostatni
			//if (it->second->CanInteract())
				it->second->Interact(event);
			break;
		}
		activeElement = it->first;
		needRefresh = true;
	}
}

bool MenuContainer::AddElement(char* name, char* caption, void(*action)(SDL_Event*))
{
	MenuElement* me = nullptr;
	if(menuElements.begin() != menuElements.end())
	{
		map<char*, MenuElement*>::iterator pair = menuElements.find(name);
		if(pair != menuElements.end())
			return false;
	}
	menuElements[name] = new MenuElement(name, caption, action);
	int w = 0, h = 0;
	for(pair<char*, MenuElement*> pair : menuElements)
	{
		Viewport* elementViewport = pair.second->GetViewport();
		h += elementViewport->GetHeight();
		w += elementViewport->GetWidth();
	}
	delete viewport;
	viewport = new Viewport({ (640 - w) / 2,250, w, h });
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

void MenuContainer::SetActiveElement(char* elementName)
{
	if(activeElement != nullptr)
		menuElements[activeElement]->SetActive(false);
	activeElement = elementName;
	menuElements[activeElement]->SetActive(true);
}

bool MenuContainer::NeedRefresh()
{
	/*for (pair<char*, MenuElement*> pair : menuElements)
		if (pair.second->NeedRefresh())
			needRefresh = true;*/
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
	viewport->Clear();
	int y = 0, containerW = viewport->GetWidth();
	for(pair<char*, MenuElement*> pair : menuElements)
	{
		MenuElement* me = pair.second;
		if (me->NeedRefresh())
			me->Refresh();
		me->Move((containerW - me->GetViewport()->GetWidth()) / 2, y, true);
		y += me->GetViewport()->GetHeight();
		viewport->Draw(me->GetViewport());
	}
}

Viewport * MenuContainer::GetViewport()
{
	return viewport;
}
