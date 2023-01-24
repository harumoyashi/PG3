#include "Rectangle.h"
#include <stdio.h>

Rectangle::Rectangle(Vec2 scale)
{
    this->scale = scale;
}

float Rectangle::Size()
{
    return  scale.x * scale.y;
}

void Rectangle::Draw()
{
    printf("矩形の面積：%f\n", Size());
}