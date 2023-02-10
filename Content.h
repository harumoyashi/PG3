#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Content
{
private:
	string content;

public:
	inline void Set(const string& content) { this->content = content; }
	inline string Get() { return content; }
};