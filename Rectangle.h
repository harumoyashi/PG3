#pragma once
#include "IShape.h"
class Rectangle :
    public IShape
{
private:
    Vec2 scale{};

public:
    Rectangle(Vec2 scale = { 1,1 });
    float Size()override;
    void Draw()override;
};