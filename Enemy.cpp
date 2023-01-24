#include "Enemy.h"
#include "DxLib.h"
#include <random>

float Enemy::radius{};
bool Enemy::isAlive = true;

std::random_device device;
std::mt19937 engine(device());

Enemy::Enemy()
{
	pos = { 300,200 };
	radius = 10.0f;
}

void Enemy::Init()
{
	std::uniform_real_distribution<float> randX(8.0f, 592.0f);
	std::uniform_real_distribution<float> randY(48.0f, 292.0f);
	pos = { randX(engine),randY(engine)};
}

void Enemy::Update()
{
	if (phaseTimer < maxPhaseTime)
	{
		phaseTimer++;
	}
	else
	{
		phaseTimer = 0;
		state = rand() % 3;
	}
}

void Enemy::Draw()
{
	if (isAlive)
	{
		switch (state)
		{
		case Phase::Approach:
			DrawCircle(pos.x, pos.y, radius, 0xff2222);
			break;
		case Phase::Shot:
			DrawCircle(pos.x, pos.y, radius, 0x22ff22);
			break;
		case Phase::GoAway:
			DrawCircle(pos.x, pos.y, radius, 0x2222ff);
			break;
		default:
			break;
		}
	}
}

void Enemy::Approach(Vec2 playerPos)
{
	state = Phase::Approach;
}

void Enemy::Shot(Vec2 playerPos)
{
	state = Phase::Shot;
}

void Enemy::GoAway(Vec2 playerPos)
{
	state = Phase::GoAway;
}

void (Enemy::* Enemy::actionTable[])(Vec2 playerPos) =
{
	&Enemy::Approach,
	&Enemy::Shot,
	&Enemy::GoAway
};