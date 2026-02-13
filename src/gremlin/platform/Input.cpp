#include <gremlin/platform/Input.hpp>

namespace gremlin
{
	std::unordered_set<SDL_Keycode> Input::keysDown;

	void Input::Initialize(void)
	{
		keysDown.clear();
	}

	void Input::Shutdown(void)
	{
		keysDown.clear();
	}

	void Input::ProcessEvent(const SDL_Event& event)
	{
		if (event.type == SDL_EVENT_KEY_DOWN)
		{
			keysDown.insert(event.key.key);
		}
		else if (event.type == SDL_EVENT_KEY_UP)
		{
			keysDown.erase(event.key.key);
		}
	}

	bool Input::IsKeyDown(SDL_Keycode key)
	{
		return keysDown.contains(key);
	}
}
