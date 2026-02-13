#include <gremlin/render/Renderer.hpp>
#include <SDL3/SDL.h>

#include <iostream>

namespace gremlin
{
	Renderer::Renderer(SDL_Renderer* renderer) : renderer(renderer) {}

	void Renderer::Clear(void)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	}

	void Renderer::Present(void)
	{
		SDL_RenderPresent(renderer);
	}

	void Renderer::DrawFilledRect(int x, int y, int w, int h)
	{
		if (!renderer)
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


		SDL_SetRenderDrawColor(renderer, 255, 110, 255, 255);
		SDL_RenderFillRect(renderer, &rect);
	}
}
