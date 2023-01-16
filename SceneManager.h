#pragma once

enum SceneNum {
	Title,
	NewGame,
	GamePlay,
	GameClear
};

class SceneManager final
{
public:
	// コピーコンストラクタを無効化
	SceneManager(const SceneManager& obj) = delete;

	// 代入演算子を無効化
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	// シーン切り替え用の関数
	void ChangeScene(int sceneNum);

	int GetSceneNum() { return sceneNum; }

private:
	SceneManager();
	~SceneManager();

	int sceneNum;
};