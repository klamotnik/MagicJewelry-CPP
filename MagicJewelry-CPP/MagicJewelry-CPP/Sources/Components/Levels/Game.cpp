#include "Components\Levels\Game.h"


Game::Game(Viewport* viewport) : Level(viewport)
{
	AddActor(new Logo(310, 50, false));
	AddActor(new Board(0, 5));
	AddActor(new NextBrickGroup(325, 385));
	//Board ma wywo�a� funkcj� na levelu (polecenie do Parenta), kt�ra przeka�e bricki z nextbrickgroup do boarda
}
