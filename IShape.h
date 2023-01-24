#pragma once
#include "Vec2.h"

class IShape
{
private:
	Vec2 pos;

public:
	virtual float Size() = 0;
	virtual void Draw() = 0;
};