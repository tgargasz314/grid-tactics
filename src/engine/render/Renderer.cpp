#include "Renderer.hpp"
#include "../platform/Window.hpp"

#include <SDL3/SDL.h>

namespace engine
{
	Renderer::~Renderer(void)
	{
		if (renderer)
		{
			SDL_DestroyRenderer(renderer);
		}
	}

	bool Renderer::Initialize(Window* window)
	{
		renderer = SDL_CreateRenderer(
			window->GetNativeHandle(),
			nullptr,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
		);

		return renderer != nullptr;
	}

	void Renderer::Clear(void)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	}

	void Renderer::Present(void)
	{
		SDL_RenderPresent(renderer);
	}

	void Renderer::DrawRect(int x, int y, int w, int h)
	{
		SDL_FRect rect { x, y, w, h };

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &rect);
	}
}
