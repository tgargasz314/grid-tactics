#pragma once

#include <gremlin/core/IGame.hpp>

class Game : public gremlin::IGame
{
public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;
};
