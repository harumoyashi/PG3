#pragma once
#include "Task.h"
#include <list>

class TaskManager
{
public:
	static std::list<std::unique_ptr<Task>> tasks;

public:
	//�V�����쐬
	static void Create(const string& title, const string& content, const string& priority,
		const int& deadline, const int& id, const int& maneID, const string& state = "������");
	//�w�肵���v�f�ԍ��̗v�f���폜
	//elementNum:�v�f�ԍ�
	static void Delete(const int& elementNum);
	//�w�肵��ID�ԍ��̗v�f��ҏW
	//id:ID�ԍ�
	static void Edit(const int& id);

	static void ShowAll();
	static Task* GetData(const int& id);
};