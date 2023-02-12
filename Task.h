#pragma once
#include "ID.h"
#include "PIC.h"
#include "Title.h"
#include "Content.h"
#include "Priority.h"
#include "Deadline.h"
#include "State.h"

class Task
{
public:
	ID id;
	PIC pic;
	Title title;
	Content content;
	Priority priority;
	Deadline deadline;
	State state;

public:
	void SetSteat(const string& typeName);
	void SetPriority(const string& typeName);
	void SetPIC(const int& maneID);
};