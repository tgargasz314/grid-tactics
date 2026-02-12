#include <gremlin/core/Application.hpp>
#include <gremlin/core/IGame.hpp>
#include <gremlin/render/Renderer.hpp>

#include <SDL3/SDL.h>

#include <iostream>

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
		if (!SDL_Init(SDL_INIT_VIDEO))
		{
			std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
			return;
		}

		window = SDL_CreateWindow("Gremlin Engine", 800, 600, 0);
		if (!window)
		{
			std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
			return;
		}

		sdlRenderer = SDL_CreateRenderer(window, nullptr);
		if (!sdlRenderer)
		{
			std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
			return;
		}

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
		game->Initialize();

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
			game->Render(*renderer);

			renderer->Present();
		}

		game->Shutdown();
	}
}
