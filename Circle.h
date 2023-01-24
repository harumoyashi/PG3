#pragma once
#include "IShape.h"
class Circle :
	public IShape
{
private:
	float radius{};

public:
	Circle(float r = 1.0f);
	float Size()override;
	void Draw()override;

};