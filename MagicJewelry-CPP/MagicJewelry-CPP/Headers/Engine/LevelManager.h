#pragma once

#include <map>
#include "Engine\Types\Level.h"

class LevelManager
{
public:
	static LevelManager* GetInstance();
	template<class T>
	void ChangeLevel() {
		Level* level = new T(new Viewport({0,0,640,480}));
		currentLevel = level;
	}
	Level* GetCurrentLevel();
private:
	LevelManager();
	static LevelManager* levelManager;
	map<char*, Level*> levels;
	Level* currentLevel;
};

