#include "Task.h"

void Task::SetSteat(const string& typeName)
{
	if (typeName == "Completion"|| typeName == "Š®—¹")
	{
		state.Set(State::StateType::Completion);
	}
	else if (typeName == "Incomplete" || typeName == "–¢Š®—¹")
	{
		state.Set(State::StateType::Incomplete);
	}
}
