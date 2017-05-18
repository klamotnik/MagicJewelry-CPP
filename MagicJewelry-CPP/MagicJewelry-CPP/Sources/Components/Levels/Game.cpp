#include "Components\Levels\Game.h"


Game::Game(Viewport* viewport) : Level(viewport)
{
	AddActor(new Logo(310, 50, false));
	AddActor(new Board(0, 5));
	AddActor(new NextBrickGroup(325, 385));
	//Board ma wywo³aæ funkcjê na levelu (polecenie do Parenta), która przeka¿e bricki z nextbrickgroup do boarda
}
