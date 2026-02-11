#include "Window.hpp"

#include <SDL3/SDL.h>

namespace engine
{
	Window::~Window(void)
	{
		if (window)
		{
			SDL_DestroyWindow(window);
		}
	}

	bool Window::Initialize(const char* title, int width, int height)
	{
		window = SDL_CreateWindow(
			title,
			width,
			height,
			SDL_WINDOW_RESIZABLE
		);

		return window != nullptr;
	}

	SDL_Window* Window::GetNativeHandle(void) const
	{
		return window;
	}
}
