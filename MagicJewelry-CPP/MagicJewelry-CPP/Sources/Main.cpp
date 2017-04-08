#include "Engine\Engine.h"

#undef main

int main()
{
	Engine* engine = new Engine();
	engine->Start();
	delete engine;
	return 0;
}