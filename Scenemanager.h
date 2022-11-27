#pragma once
#include "Scene.h"

class Scenemanager final
{
private:


private:
	Scenemanager();

public:
	Scenemanager* GetInstance();

	void Init();
	void Update();
	void Draw();

	void ChangeScene(int sceneNo);
};

