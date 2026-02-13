#include <gremlin/platform/Window.hpp>
#include <SDL3/SDL.h>
#include <iostream>

namespace gremlin
{
	Window::~Window(void)
	{
		Destroy();
	}

	bool Window::Create(const char* title, int width, int height)
	{
		sdlWindow = SDL_CreateWindow(
			title,
			width,
			height,
			SDL_WINDOW_RESIZABLE
		);

		if (!sdlWindow)
		{
			std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
			return false;
		}

		return true;
	}

	void Window::Destroy(void)
	{
		if (sdlWindow)
		{
			SDL_DestroyWindow(sdlWindow);
			sdlWindow = nullptr;
		}
	}

	SDL_Window* Window::GetHandle(void) const
	{
		return sdlWindow;
	}
}
