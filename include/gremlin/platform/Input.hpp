#pragma once

#include <SDL3/SDL_events.h>
#include <unordered_set>

namespace gremlin
{
	class Input
	{
	public:
		static void Initialize(void);
		static void Shutdown(void);

		static void ProcessEvent(const SDL_Event& event);

		static bool IsKeyDown(SDL_Keycode key);

	private:
		static std::unordered_set<SDL_Keycode> keysDown;
	};
}
