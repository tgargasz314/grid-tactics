#pragma once

#include <memory>

namespace gremlin
{
	class IGame;

	class Application
	{
	public:
		Application(std::unique_ptr<IGame> game);
		~Application(void);

		void Run(void);

	private:
		std::unique_ptr<IGame> game;
		bool running = true;
	};
}
