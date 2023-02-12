#pragma once
class Deadline
{
private:
	int month;
	int day;

public:
	inline void Set(const int& deadline) { this->month = deadline / 100; this->day = deadline % 100; }
	inline int GetMonth() { return month; }
	inline int GetDay() { return day; }
};

