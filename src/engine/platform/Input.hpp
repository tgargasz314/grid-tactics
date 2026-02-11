#pragma once

#include <unordered_set>

struct SDL_Event;

namespace engine
{
	class Input
	{
	public:
		void HandleEvent(const SDL_Event& event);
		void Update(void);

		bool IsKeyDown(int scancode) const;

	private:
		std::unordered_set<int> keysDown;
	};
}
