#pragma once
#include "ID.h"
#include "Manager.h"
#include "Title.h"
#include "Content.h"
#include "Priority.h"
#include "Deadline.h"
#include "State.h"

class Task
{
public:
	ID id;
	Manager manager;
	Title title;
	Content content;
	Priority priority;
	Deadline deadline;
	State state;

public:
	void SetSteat(const string& typeName);
	void SetPriority(const string& typeName);
	void SetManager(const int& maneID);
};