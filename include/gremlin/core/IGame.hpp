#pragma once

namespace gremlin
{
	class Renderer;

	class IGame
	{
	public:
		virtual ~IGame() = default;

		virtual void Initialize(void) {}
		virtual void Update(float deltaTime) = 0;
		virtual void Render(Renderer& renderer) = 0;
		virtual void Shutdown(void) {}
	};
}
