#pragma once

#include <gremlin/Gremlin.hpp>

namespace gremlin
{
	class Renderer;
}

class Game : public gremlin::IGame
{
public:
	void Update(float deltaTime) override;
	void FixedUpdate(float fixedTimeStep) override;
	void Render(gremlin::Renderer& renderer) override;
};
