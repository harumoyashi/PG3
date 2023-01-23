#pragma once

class Enemy
{
public:

private:
    static bool isAlive;

public:
    Enemy();

    void Init();
    void Update();

    inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
    inline bool GetIsAlive() { return isAlive; }
};