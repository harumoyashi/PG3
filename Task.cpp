#include "Task.h"

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
