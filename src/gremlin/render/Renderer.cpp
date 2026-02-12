#include <gremlin/render/Renderer.hpp>
#include <gremlin/platform/Window.hpp>

#include <SDL3/SDL.h>

namespace gremlin
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
			nullptr
		);

		if (!renderer)
		{
			return false;
		}

		SDL_SetRenderVSync(renderer, 1);

		return true;
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
		SDL_FRect rect {
		static_cast<float>(x),
		static_cast<float>(y),
		static_cast<float>(w),
		static_cast<float>(h)
	};


		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &rect);
	}
}
