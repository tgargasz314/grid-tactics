#pragma once

#include <gremlin/core/IGame.hpp>

namespace gremlin
{
	class Renderer;
}

class Game : public gremlin::IGame
{
public:
	void Initialize(gremlin::Renderer* renderer) override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;

private:
	gremlin::Renderer* renderer = nullptr;
};
