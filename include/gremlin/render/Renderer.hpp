#pragma once

struct SDL_Renderer;

namespace gremlin
{
	class Renderer
	{
	public:
		Renderer(SDL_Renderer* renderer);

		void Clear(void);
		void Present(void);
		void DrawFilledRect(int x, int y, int w, int height);

	private:
		SDL_Renderer* renderer;
	};
}
