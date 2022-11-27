#pragma once
#include "Scene.h"

class GameClearScene :public Scene
{
public:
	GameClearScene();
	GameClearScene* GetInstance() override;

private:
	void Init() override;
	void Update() override;
	void Draw() override;
};

