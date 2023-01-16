#include "SceneManager.h"

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNum)
{
	this->sceneNum = sceneNum;

	//ƒ‹[ƒv‚³‚¹‚é
	if (this->sceneNum > SceneNum::GameClear)
	{
		this->sceneNum = SceneNum::Title;
	}
}

SceneManager::SceneManager()
{
	sceneNum = SceneNum::Title;
}