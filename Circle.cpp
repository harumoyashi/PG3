#include "Circle.h"
#include <stdio.h>

Circle::Circle(float r)
{
	radius = r;
}

float Circle::Size()
{
	return radius * radius * 3.14f;
}

void Circle::Draw()
{
	printf("円の面積：%f\n", Size());
}