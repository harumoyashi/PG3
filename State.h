#pragma once
class State
{
public:
	enum class StateType
	{
		Completion,	//����
		Incomplete,	//������
	};

private:
	int state;

public:
	inline void Set(StateType type) { state = (int)type; }
	inline int Get() { return state; }
};