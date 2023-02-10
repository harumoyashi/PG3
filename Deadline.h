#pragma once
class Deadline
{
private:
	int month;
	int day;

public:
	inline void Set(const int& month, const int& day) { this->month = month; this->day = day; }
	inline int GetMonth() { return month; }
	inline int GetDay() { return day; }
};

