#pragma once
#include "Vec2.h"

enum Phase {
    Approach,   //�ڋ�
    Shot,       //�ˌ�
    GoAway      //���E
};

class Enemy
{
public:


private:
    Vec2 pos;
    static float radius;

    static bool isAlive;

    int state = Phase::Approach;

    const int maxPhaseTime = 60;
    int phaseTimer = 0;

public:
    Enemy();

    void Init();
    void Update();
    void Draw();

    inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
    inline bool GetIsAlive() { return isAlive; }

private:
    static void (Enemy::* actionTable[])(Vec2 playerPos);

    void Approach(Vec2 playerPos);
    void Shot(Vec2 playerPos);
    void GoAway(Vec2 playerPos);

};