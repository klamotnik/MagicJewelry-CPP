#include "Engine\Window.h"

Window::Window(int Width, int Height, string Title)
{
	if (Width > 0 && Height > 0) 
	{
		title = Title;
		window = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
		windowSurface = SDL_GetWindowSurface(window);
	}
}

Window::~Window()
{
	SDL_FreeSurface(windowSurface);
	SDL_DestroyWindow(window);
}

SDL_Surface* Window::GetWindowSurface()
{
	return windowSurface;
}

SDL_Window* Window::GetWindow()
{
	return window;
}

void Window::DrawOnScreen(Viewport* viewportToDraw)
{
	SDL_UpperBlit(viewportToDraw->GetSurface(), nullptr, windowSurface, viewportToDraw->GetProperties());
	SDL_UpdateWindowSurface(window);
}
