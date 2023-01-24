#include "Vec2.h"
#include <cmath>    // sqrt

Vec2::Vec2() :x(0), y(0) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

float Vec2::Length() const
{
	return sqrtf(x * x + y * y);
}

Vec2& Vec2::Normalize()
{
	float len = Length();
	if (len != 0)
	{
		return *this /= len;
	}
	return *this;
}

float Vec2::Dot(const Vec2& v) const
{
	return x * v.x + y * v.y;
}

float Vec2::Cross(const Vec2& v) const
{
	return x * v.y - y * v.x;
}

Vec2 Vec2::operator+() const
{
	return *this;
}

Vec2 Vec2::operator-() const
{
	return Vec2(-x, -y);
}

Vec2& Vec2::operator+=(const Vec2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

Vec2& Vec2::operator*=(float s)
{
	x *= s;
	y *= s;
	return *this;
}

Vec2& Vec2::operator/=(float s)
{
	x /= s;
	y /= s;
	return *this;
}

// Vec2 ƒNƒ‰ƒX‚É‘®‚³‚È‚¢ŠÖ”ŒR
// “ñ€‰‰Zq
const Vec2 operator+(const Vec2& v1, const Vec2& v2)
{
	Vec2 temp(v1);
	return temp += v2;
}

const Vec2 operator-(const Vec2& v1, const Vec2& v2)
{
	Vec2 temp(v1);
	return temp -= v2;
}

const Vec2 operator*(const Vec2& v, float s)
{
	Vec2 temp(v);
	return temp *= s;
}

const Vec2 operator*(float s, const Vec2& v)
{
	return v * s;
}

const Vec2 operator/(const Vec2& v, float s)
{
	Vec2 temp(v);
	return temp /= s;
}