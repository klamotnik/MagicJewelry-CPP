#pragma once

#include <map>
#include "Engine\Types\MenuElement.h"

using namespace std;

class MenuContainer : public Actor
{
public:
	MenuContainer();
	~MenuContainer();
	virtual bool CanInteract() override;
	virtual void Interact(SDL_Event* event) override;
	bool AddElement(char* name, char* caption);
	template<class T>
	bool AddElement(char* name, char* caption) {
		MenuElement* me = nullptr;
		if (menuElements.begin() != menuElements.end())
		{
			map<char*, MenuElement*>::iterator pair = menuElements.find(name);
			if (pair != menuElements.end())
				return false;
		}
		menuElements[name] = new T(name, caption);
		int w = 0, h = 0;
		for (pair<char*, MenuElement*> pair : menuElements)
		{
			Viewport* elementViewport = pair.second->GetViewport();
			h += elementViewport->GetHeight();
			w += elementViewport->GetWidth();
		}
		delete viewport;
		viewport = new Viewport({ 0,200, w, h });
		needRefresh = true;
		return true;
	}
	bool RemoveElement(char* name);
	void ClearMenu();
	void SetActiveElement(char* elementName);
	virtual bool NeedRefresh() override;
	virtual void Refresh() override;
	virtual Viewport* GetViewport() override;
private:
	bool canInteract;
	bool needRefresh;
	char* activeElement;
	map<char*, MenuElement*> menuElements;
};
