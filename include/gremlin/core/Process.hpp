#pragma once
#include <memory>

class ProcessManager;

class Process
{
public:

	virtual ~Process() = default;

	// Lifecycle
	virtual void onEnter(ProcessManager&) {}
	virtual void onExit(ProcessManager&) {}
	virtual void onPause(ProcessManager&) {}
	virtual void onResume(ProcessManager&) {}

	virtual void handleInput(ProcessManager&) = 0;
	virtual void update(ProcessManager&, float dt) = 0;
	virtual void render(ProcessManager&) = 0;

	bool isFinished(void) const { return finished; }

protected:
	void finish(void) { finished = true; }

private:
	bool finished = false;
};
