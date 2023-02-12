#pragma once
class Priority
{
public:
	enum class PriorityType
	{
		Top,		//çÇ
		Middle,		//íÜ
		Low,		//í·
		OnHold,		//ï€óØ
	};

private:
	int priority;

public:
	inline void Set(PriorityType type) { priority = (int)type; }
	inline int Get() { return priority; }
};
