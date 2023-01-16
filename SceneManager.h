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
	// �R�s�[�R���X�g���N�^�𖳌���
	SceneManager(const SceneManager& obj) = delete;

	// ������Z�q�𖳌���
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	// �V�[���؂�ւ��p�̊֐�
	void ChangeScene(int sceneNum);

	int GetSceneNum() { return sceneNum; }

private:
	SceneManager();
	~SceneManager();

	int sceneNum;
};