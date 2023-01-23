#include "Enemy.h"
#include "DxLib.h"

Vec2 Enemy::pos{};
float Enemy::radius{};
bool Enemy::isAlive = true;

Enemy::Enemy()
{
	pos = { 300,200 };
	radius = 10.0f;
}

void Enemy::Init()
{
	pos = { 300,200 };
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	if (isAlive)
	{
		DrawCircle(pos.x, pos.y, radius, 0xff2222);
	}
}

void Enemy::Approach(Vec2 playerPos)
{
}

void Enemy::Shot(Vec2 playerPos)
{
}

void Enemy::GoAway(Vec2 playerPos)
{
}

void (Enemy::* Enemy::actionTable[])(Vec2 playerPos) =
{
	&Enemy::Approach,
	&Enemy::Shot,
	&Enemy::GoAway
};