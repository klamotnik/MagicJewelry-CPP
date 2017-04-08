#include "..\..\Headers\Engine\LevelManager.h"
#include "Components\Levels\MainMenu.h"

LevelManager* LevelManager::levelManager = nullptr;

LevelManager* LevelManager::GetInstance()
{
	if(!levelManager)
	{
		levelManager = new LevelManager();
		levelManager->ChangeLevel<MainMenu>();
	}
	return levelManager;
}

//void LevelManager::ChangeLevel(char* levelName)
//{
//	map<char*, Level*>::iterator pair = levels.find(levelName);
//	if (pair != levels.end())
//	{
//		Level* level = levels[levelName];
//		levels.erase(levelName);
//		delete level;
//	}
//	currentLevel = levels[levelName] = new MainMenu(new Viewport({ 0, 0, 640, 480 }));
//}

Level* LevelManager::GetCurrentLevel()
{
	return currentLevel;
}

LevelManager::LevelManager()
{
}
