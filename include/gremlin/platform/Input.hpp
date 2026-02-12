#pragma once

#include <SDL3/SDL_events.h>
#include <unordered_set>

namespace gremlin
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
