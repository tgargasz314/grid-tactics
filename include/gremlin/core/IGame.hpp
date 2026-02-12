#pragma once

namespace gremlin
{
	class IGame
	{
	public:
		virtual ~IGame() = default;

		virtual void Initialize() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Render() = 0;
		virtual void Shutdown() = 0;
	};
}
