#include "TaskManager.h"

void TaskManager::Create()
{
	std::unique_ptr<Task> task = make_unique<Task>();
	tasks.emplace_back(task);
}

void TaskManager::Delete(int elementNum)
{
	auto itr = tasks.begin();
	for (int i = 0; i < elementNum; i++)
	{
		itr++;
	}
	tasks.erase(itr);
}
