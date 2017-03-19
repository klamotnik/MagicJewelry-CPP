#include "Engine\Game.h"

#undef main

int main()
{
	Game* G = new Game();
	G->Start();
	delete G;
	return 0;
}