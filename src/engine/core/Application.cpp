#include "Application.hpp"

#include "../platform/Window.hpp"
#include "../platform/Input.hpp"
#include "../render/Renderer.hpp"

#include <SDL3/SDL.h>

namespace engine
{
	Application::Application(void) = default;
	Application::~Application(void) = default;

	bool Application::Initialize(void)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			return false;
		}

		window = std::make_unique<Window>();
		if (!window->Initialize("Grid Tactics", 1200, 720))
		{
			return false;
		}

		renderer = std::make_unique<Renderer>();
		if (!renderer->Initialize(window.get()))
		{
			return false;
		}

		input = std::make_unique<Input>();

		return true;
	}

	void Application::Run(void)
	{
		running = true;
		Uint64 previous = SDL_GetTicks();

		while (running)
		{
			Uint64 current = SDL_GetTicks();
			float deltaTime = (current - previous) / 1000.0f;
			previous = current;

			ProcessEvents();
			Update(deltaTime);
			Render();
		}
	}

	void Application::Shutdown(void)
	{
		renderer.reset();
		window.reset();
		SDL_Quit();
	}

	void Application::ProcessEvents(void)
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				running = false;
			}

			input->HandleEvent(event);
		}
	}

	void Application::Update(float deltaTime)
	{
		(void)deltaTime;
		input->Update();
	}

	void Application::Render(void)
	{
		renderer->Clear();

		// Temporary Test Draw
		renderer->DrawRect(100, 100, 64, 64);

		renderer->Present();
	}
}
