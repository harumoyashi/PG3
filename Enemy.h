#pragma once
#include "Vec2.h"

enum State {
    Approach,   //Ú‹ß
    Shot,       //ŽËŒ‚
    GoAway      //—£’E
};

class Enemy
{
public:


private:
    static Vec2 pos;
    static float radius;

    static bool isAlive;

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