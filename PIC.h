#pragma once
#include "ID.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
using namespace std;

class PIC
{
private:
	ID id;
	string name;
	string classID;

public:
	void SetID(const int& num) { id.Set(num); }
	void SetName(const string& name) { this->name = name; }
	void SetClassID(const string& classID) { this->classID = classID; }

	int GetID() { return id.Get(); }
	string GetName() { return name; }
	string GetClassID() { return classID; }
};