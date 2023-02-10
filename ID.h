#pragma once
class ID
{
private:
	int num;

public:
	inline void Set(const int& num) { this->num = num; }
	inline int Get() { return num; }
};