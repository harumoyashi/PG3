#include "Task.h"
#include "PICManager.h"

void Task::SetSteat(const string& typeName)
{
	if (typeName == "Completion"|| typeName == "����")
	{
		state.Set(State::StateType::Completion);
	}
	else if (typeName == "Incomplete" || typeName == "������")
	{
		state.Set(State::StateType::Incomplete);
	}
}

void Task::SetPriority(const string& typeName)
{
	if (typeName == "Top" || typeName == "��")
	{
		priority.Set(Priority::PriorityType::Top);
	}
	else if (typeName == "Middle" || typeName == "��")
	{
		priority.Set(Priority::PriorityType::Middle);
	}
	else if (typeName == "Low" || typeName == "��")
	{
		priority.Set(Priority::PriorityType::Low);
	}
	else if (typeName == "OnHold" || typeName == "�ۗ�")
	{
		priority.Set(Priority::PriorityType::OnHold);
	}
}

void Task::SetPIC(const int& picID)
{
	pic = *PICManager::GetData(picID);
}
