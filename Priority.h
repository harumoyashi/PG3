#pragma once
class Priority
{
public:
	enum class PriorityType
	{
		Top,		//��
		Middle,		//��
		Low,		//��
		OnHold,		//�ۗ�
	};

private:
	int priority;

public:
	inline void Set(PriorityType type) { priority = (int)type; }
	inline int Get() { return priority; }
};
