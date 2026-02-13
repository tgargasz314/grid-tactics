#pragma once

struct SDL_Renderer;

namespace gremlin
{
	class Renderer
	{
	public:
		Renderer(void) = default;
		~Renderer(void);

		bool Create(Window& window);
		void Destroy(void);

		void Clear(void);
		void Present(void);
		void DrawFilledRect(int x, int y, int w, int height);

	private:
		SDL_Renderer* sdlRenderer;
	};
}
