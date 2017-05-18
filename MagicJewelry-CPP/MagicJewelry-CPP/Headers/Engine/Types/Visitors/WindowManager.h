//#pragma once
//
//#include <map>
//#include "Engine\Window.h"
//
//class WindowManager
//{
//public:
//	static Window* CreateWindow(char* windowName, char* title, int width, int height) {
//		if (windows.find(windowName) == windows.end())
//			return nullptr;
//		Window* w = new Window(width, height, title);
//		windows[windowName] = w;
//		return w;
//	}
//	static Window* GetWindow(char* windowName) {
//		return windows[windowName];
//	}
//	/*template<class T>
//	void ChangeLevel() {
//		Level* level = new T(new Viewport({0,0,640,480}));
//		currentLevel = level;
//	}*/
//	//Window* GetCurrentLevel();
//private:
//	WindowManager();
//	//static WindowManager* windowManager;
//	static map<char*, Window*> windows;
//};
//
