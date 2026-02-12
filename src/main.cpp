#include "engine/core/Application.hpp"

int main(int argc, char** argv)
{
	engine::Application app;

	if (!app.Initialize())
	{
		return 1;
	}

	app.Run();
	app.Shutdown();

	return 0;
}
