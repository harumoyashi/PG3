#include "Task.h"

void Task::SetSteat(const string& typeName)
{
	if (typeName == "Completion"|| typeName == "äÆóπ")
	{
		state.Set(State::StateType::Completion);
	}
	else if (typeName == "Incomplete" || typeName == "ñ¢äÆóπ")
	{
		state.Set(State::StateType::Incomplete);
	}
}

void Task::SetPriority(const string& typeName)
{
	if (typeName == "Top" || typeName == "çÇ")
	{
		priority.Set(Priority::PriorityType::Top);
	}
	else if (typeName == "Middle" || typeName == "íÜ")
	{
		priority.Set(Priority::PriorityType::Middle);
	}
	else if (typeName == "Low" || typeName == "í·")
	{
		priority.Set(Priority::PriorityType::Low);
	}
	else if (typeName == "OnHold" || typeName == "ï€óØ")
	{
		priority.Set(Priority::PriorityType::OnHold);
	}
}

void Task::SetManager(const int& maneID)
{
	manager = *ManagerMane::GetData(maneID);
}
