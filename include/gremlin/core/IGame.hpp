#pragma once

namespace gremlin
{
	class Renderer;

	class IGame
	{
	public:
		virtual ~IGame() = default;

		virtual void Initialize(Renderer* renderer) = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Render() = 0;
		virtual void Shutdown() = 0;
	};
}
