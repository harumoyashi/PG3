#pragma once
#include "Task.h"
#include <list>

class TaskManager
{
public:
	static std::list<std::unique_ptr<Task>> tasks;

public:
	//新しく作成
	static void Create(const string& title, const string& content, const string& priority,
		const int& deadline, const int& id, const int& maneID, const string& state = "未完了");
	//指定した要素番号の要素を削除
	//elementNum:要素番号
	static void Delete(const int& id);
	//指定したID番号の要素を編集
	//id:ID番号
	static void Edit(const int& id);

	static void ShowAll();
	static Task* GetData(const int& id);
};