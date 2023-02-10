#pragma once
class State
{
public:
	enum class StateType
	{
		Completion,	//Š®—¹
		Incomplete,	//–¢Š®—¹
	};

private:
	int state;

public:
	inline void Set(StateType type) { state = (int)type; }
	inline int Get() { return state; }
};