#include <gremlin/core/Application.hpp>
#include <gremlin/core/IGame.hpp>
#include <gremlin/platform/Input.hpp>
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

		window = SDL_CreateWindow("Gremlin Engine", 800, 600, SDL_WINDOW_RESIZABLE);
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

		const double fixedTimeStep = 1.0 / 60.0;
		double accumulator = 0.0;

		uint64_t previous = SDL_GetPerformanceCounter();
		const uint64_t frequency = SDL_GetPerformanceFrequency();

		while (running)
		{
			// Time
			uint64_t current = SDL_GetPerformanceCounter();
			double deltaTime = static_cast<double>(current - previous) / frequency;
			previous = current;

			if (deltaTime > 0.1)
			{
				deltaTime = 0.1;
			}

			// Events
			ProcessEvents();

			if (Input::IsKeyDown(SDLK_ESCAPE))
			{
				running = false;
			}

			// Simulation
			accumulator += deltaTime;
			while (accumulator >= fixedTimeStep)
			{
				game->FixedUpdate(static_cast<float>(fixedTimeStep)); // Needs defined
				accumulator -= fixedTimeStep;
			}

			// Frame Update
			game->Update(static_cast<float>(deltaTime));

			// Render
			renderer->Clear();
			game->Render(*renderer);
			renderer->Present();
		}

		game->Shutdown();
	}

	void Application::ProcessEvents(void)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				running = false;
			}

			Input::ProcessEvent(event);
		}
	}
}
