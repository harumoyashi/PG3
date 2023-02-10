#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Title
{
private:
	string title;

public:
	inline void Set(const string& title) { this->title = title; }
	inline string Get() { return title; }
};