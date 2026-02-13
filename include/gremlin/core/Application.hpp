#pragma once

#include <memory>

namespace gremlin
{
	class IGame;
	class Window;
	class Renderer;

	class Application
	{
	public:
		Application(std::unique_ptr<IGame> game);
		~Application(void);

		void Run(void);

		void ProcessEvents(void);

	private:
		void Shutdown(void);

		std::unique_ptr<IGame> game;
		std::unique_ptr<Window> window;
		std::unique_ptr<Renderer> renderer;

		bool running = true;
	};
}
