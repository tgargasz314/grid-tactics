#include <gremlin/platform/Window.hpp>
#include <gremlin/render/Renderer.hpp>
#include <SDL3/SDL.h>

#include <iostream>

namespace gremlin
{
	Renderer::~Renderer(void)
	{
		Destroy();
	}

	bool Renderer::Create(Window& window)
	{
		sdlRenderer = SDL_CreateRenderer(window.GetHandle(), nullptr);
		if (!sdlRenderer)
		{
			std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
			return false;
		}

		return true;
	}

	void Renderer::Destroy(void)
	{
		if (sdlRenderer)
		{
			SDL_DestroyRenderer(sdlRenderer);
			sdlRenderer = nullptr;
		}
	}

	void Renderer::Clear(void)
	{
		SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
		SDL_RenderClear(sdlRenderer);
	}

	void Renderer::Present(void)
	{
		SDL_RenderPresent(sdlRenderer);
	}

	void Renderer::DrawFilledRect(int x, int y, int w, int h)
	{
		if (!sdlRenderer)
		{
			std::cerr << "Renderer is null, cannot draw filled rectangle." << std::endl;
			return;
		}

		SDL_FRect rect {
		static_cast<float>(x),
		static_cast<float>(y),
		static_cast<float>(w),
		static_cast<float>(h)
	};


		SDL_SetRenderDrawColor(sdlRenderer, 255, 110, 255, 255);
		SDL_RenderFillRect(sdlRenderer, &rect);
	}
}
