#include <gremlin/core/ProcessManager.hpp>
#include <gremlin/core/Process.hpp>

void ProcessManager::update(float dt)
{
	if (stack.empty())
	{
		return;
	}

	Process* current = stack.back().get();

	current->handleInput(*this);
	current->update(*this, dt);

	if (current->isFinished())
	{
		pop();
	}

	applyCommands();
}

void ProcessManager::render()
{
	for (auto& process : stack)
	{
		process->render(*this);
	}
}

void ProcessManager::push(std::unique_ptr<Process> process)
{
	commandQueue.push_back({ CommandType::Push, std::move(process) });
}

void ProcessManager::pop()
{
	commandQueue.push_back({ CommandType::Pop, nullptr });
}

void ProcessManager::replace(std::unique_ptr<Process> process)
{
	commandQueue.push_back({ CommandType::Replace, std::move(process) });
}

void ProcessManager::applyCommands()
{
	for (auto& cmd : commandQueue)
	{
		switch(cmd.type)
		{
			case CommandType::Push:
			{
				if (!stack.empty())
				{
					stack.back()->onPause(*this);
				}

				stack.push_back(std::move(cmd.process));
				stack.back()->onEnter(*this);
				break;
			}

			case CommandType::Pop:
			{
				if (stack.empty())
				{
					break;
				}

				stack.back()->onExit(*this);
				stack.pop_back();

				if (!stack.empty())
				{
					stack.back()->onResume(*this);
				}

				break;
			}

			case CommandType::Replace:
			{
				if (!stack.empty())
				{
					stack.back()->onExit(*this);
					stack.pop_back();
				}

				stack.push_back(std::move(cmd.process));
				stack.back()->onEnter(*this);

				break;
			}
		}
	}

	commandQueue.clear();
}
