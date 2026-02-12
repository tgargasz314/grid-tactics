#include <gremlin/core/Application.hpp>
#include <gremlin/core/IGame.hpp>
#include <gremlin/render/Renderer.hpp>

#include <SDL3/SDL.h>

namespace gremlin
{
	Application::Application(std::unique_ptr<IGame> game) : game(std::move(game))
	{
		InitializeSDL();
	}

	Application::~Application(void)
	{
		ShutdownSDL();
	}

	void Application::InitializeSDL(void)
	{
		SDL_Init(SDL_INIT_VIDEO);

		window = SDL_CreateWindow("Gremlin Engine", 800, 600, 0);
		sdlRenderer = SDL_CreateRenderer(window, nullptr);
		renderer = std::make_unique<Renderer>(sdlRenderer);
	}

	void Application::ShutdownSDL(void)
	{
		renderer.reset();
		SDL_DestroyRenderer(sdlRenderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Application::Run(void)
	{
		game->Initialize(renderer.get());

		while (running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_EVENT_QUIT)
				{
					running = false;
				}
			}

			renderer->Clear();

			float deltaTime = 0.016f;

			game->Update(deltaTime);
			game->Render();

			renderer->Present();
		}

		game->Shutdown();
	}
}
