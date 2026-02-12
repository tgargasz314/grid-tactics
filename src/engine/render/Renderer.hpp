#pragma once

struct SDL_Renderer;

namespace engine
{
	class Window;

	class Renderer
	{
	public:
		Renderer(void) = default;
		~Renderer(void);

		bool Initialize(Window* window);

		void Clear(void);
		void Present(void);

		void DrawRect(int x, int y, int w, int height);

	private:
		SDL_Renderer* renderer = nullptr;
	};
}
