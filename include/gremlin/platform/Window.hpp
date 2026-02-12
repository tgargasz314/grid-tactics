#pragma once

struct SDL_Window;

namespace gremlin
{
	class Window
	{
	public:
		Window(void) = default;
		~Window(void);

		bool Initialize(const char* title, int width, int height);

		SDL_Window* GetNativeHandle(void) const;

	private:
		SDL_Window* window = nullptr;
	};
}
