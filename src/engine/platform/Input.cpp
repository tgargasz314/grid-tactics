#include "Input.hpp"

#include <SDL3/SDL.h>

namespace engine
{
	void Input::HandleEvent(const SDL_Event& event)
	{
		if (event.type == SDL_EVENT_KEY_DOWN)
		{
			keysDown.insert(event.key.scancode);
		}
		else if (event.type == SDL_EVENT_KEY_UP)
		{
			keysDown.erase(event.key.scancode);
		}
	}

	void Input::Update(void)
	{
		// Later: clear per-frame states
	}

	bool Input::IsKeyDown(int scancode) const
	{
		return keysDown.contains(scancode);
	}
}
