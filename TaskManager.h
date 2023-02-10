#pragma once
#include "Task.h"
#include <list>

class TaskManager
{
private:
	std::list<std::unique_ptr<Task>> tasks;

public:
	//�V�����쐬
	void Create();
	//�w�肵���v�f�ԍ��̗v�f���폜
	//elementNum:�v�f�ԍ�
	void Delete(int elementNum);
	void Init();
	void Update();
	void Draw();
};