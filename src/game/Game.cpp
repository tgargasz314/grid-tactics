#include "Game.hpp"
#include <gremlin/render/Renderer.hpp>

void Game::Update(float deltaTime)
{
	// nothing yet
}

void Game::Render(gremlin::Renderer& renderer)
{
	renderer.DrawFilledRect(300, 200, 200, 200);
}
