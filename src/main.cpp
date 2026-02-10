#include <SDL3/SDL.h>

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Grid Tactics", 800, 600, SDL_WINDOW_RESIZABLE);

	bool running = true;
	SDL_Event e;

	while(running)
	{
		if (e.type == SDL_EVENT_QUIT)
		{
			running = false;
		}

		SDL_Delay(16);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}