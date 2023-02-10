#pragma once
#include "Task.h"
#include <list>

class TaskManager
{
private:
	std::list<std::unique_ptr<Task>> tasks;

public:
	//新しく作成
	void Create();
	//指定した要素番号の要素を削除
	//elementNum:要素番号
	void Delete(int elementNum);
	void Init();
	void Update();
	void Draw();
};