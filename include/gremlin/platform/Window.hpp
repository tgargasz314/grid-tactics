#pragma once

struct SDL_Window;

namespace gremlin
{
	class Window
	{
	public:
		Window(void) = default;
		~Window(void);

		bool Create(const char* title, int width, int height);
		void Destroy(void);

		SDL_Window* GetHandle(void) const;

	private:
		SDL_Window* sdlWindow = nullptr;
	};
}
