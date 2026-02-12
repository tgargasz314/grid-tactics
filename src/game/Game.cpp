#include "Game.hpp"
#include <gremlin/render/Renderer.hpp>

void Game::Initialize(gremlin::Renderer* renderer)
{
	renderer = renderer;
}

void Game::Update(float deltaTime)
{
	// nothing yet
}

void Game::Render()
{
	renderer->DrawFilledRect(300, 200, 200, 200);
}

void Game::Shutdown()
{
	// nothing yet
}
