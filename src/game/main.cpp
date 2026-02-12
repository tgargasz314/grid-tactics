#include <memory>
#include <gremlin/Gremlin.hpp>
#include "Game.hpp"

int main()
{
	auto game = std::make_unique<Game>();
	gremlin::Application app(std::move(game));
	app.Run();

	return 0;
}
