#include "Components\Levels\MainMenu.h"
#include "Components\Logo.h"

MainMenu::MainMenu(Viewport* viewport) : Level(viewport)
{
	AddActor(new Logo(100, 50, true));
	AddActor(new Logo(100, 250, true));
	menuContainer = new MenuContainer();
	AddActor(menuContainer);
	menuContainer->AddElement("end", "Koniec");
}
