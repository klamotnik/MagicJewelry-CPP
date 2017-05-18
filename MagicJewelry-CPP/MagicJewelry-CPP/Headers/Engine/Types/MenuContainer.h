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
	bool AddElement(char * name, char * caption, void(*action)(SDL_Event*) = nullptr);
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
