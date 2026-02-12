#include <gremlin/core/Application.hpp>
#include <gremlin/core/IGame.hpp>

namespace gremlin
{
	Application::Application(std::unique_ptr<IGame> game) : game(std::move(game)) {}

	Application::~Application(void) = default;

	void Application::Run(void)
	{
		game->Initialize();

		while (running)
		{
			float deltaTime = 0.016f;

			game->Update(deltaTime);
			game->Render();
		}
	}
}
