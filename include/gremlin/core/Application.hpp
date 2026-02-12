#pragma once

#include <memory>

struct SDL_Window;
struct SDL_Renderer;

namespace gremlin
{
	class IGame;
	class Renderer;

	class Application
	{
	public:
		Application(std::unique_ptr<IGame> game);
		~Application(void);

		void Run(void);

	private:
		void InitializeSDL(void);
		void ShutdownSDL(void);

		std::unique_ptr<IGame> game;
		std::unique_ptr<Renderer> renderer;

		SDL_Window* window = nullptr;
		SDL_Renderer* sdlRenderer = nullptr;

		bool running = true;
	};
}
