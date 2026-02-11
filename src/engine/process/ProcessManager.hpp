#pragma once

#include <vector>
#include <memory>

class Process;

class ProcessManager
{
public:

	void update(float dt);
	void render(void);

	void push(std::unique_ptr<Process> process);
	void pop(void);
	void replace(std::unique_ptr<Process> process);

	bool empty() const { return stack.empty(); }

private:
	enum class CommandType { Push, Pop, Replace };

	struct Command
	{
		CommandType type;
		std::unique_ptr<Process> process; // Only used for Push/Replace
	};

	void applyCommands(void);

	std::vector<std::unique_ptr<Process>> stack;
	std::vector<Command> commandQueue;
};
