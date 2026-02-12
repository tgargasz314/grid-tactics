#pragma once

#include <gremlin/core/IGame.hpp>

namespace gremlin
{
	class Renderer;
}

class Game : public gremlin::IGame
{
public:
	void Update(float deltaTime) override;
	void Render(gremlin::Renderer& renderer) override;
};
