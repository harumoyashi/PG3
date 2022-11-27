#include "GameClearScene.h"
#include <stdio.h>

GameClearScene::GameClearScene()
{

}

GameClearScene* GameClearScene::GetInstance()
{
	static GameClearScene instance;
	return &instance;
}

void GameClearScene::Init()
{
}

void GameClearScene::Update()
{
}

void GameClearScene::Draw()
{
	printf("GameClear");
}
