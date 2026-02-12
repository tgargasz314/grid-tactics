#pragma once

#include <memory>

namespace engine
{
	class Window;
	class Renderer;
	class Input;

	class Application
	{
	public:
		Application(void);
		~Application(void);

		bool Initialize(void);
		void Run(void);
		void Shutdown(void);

	private:
		void ProcessEvents(void);
		void Update(float deltaTime);
		void Render(void);

		bool running = false;

		std::unique_ptr<Window> window;
		std::unique_ptr<Renderer> renderer;
		std::unique_ptr<Input> input;
	};
}
