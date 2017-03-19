#pragma once

#include <map>
#include "Engine\Types\MenuElement.h"

using namespace std;

class MenuContainer : public Actor
{
public:
	MenuContainer();
	~MenuContainer();
	bool AddElement(char* name, char* caption);
	bool RemoveElement(char* name);
	void ClearMenu();
	virtual bool NeedRefresh() override;
	virtual void Refresh() override;
	virtual Viewport* GetViewport() override;
private:
	bool needRefresh;
	bool activeElement;
	map<char*, MenuElement*> menuElements;
};
