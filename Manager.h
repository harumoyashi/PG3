#pragma once
#include "ID.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
using namespace std;

class Manager
{
private:
	ID id;
	string name;
	string classID;

public:
	void SetID(const int& num) { id.Set(num); }
	void SetName(const string& name) { this->name = name; }
	void SetClassID(const string& classID) { this->classID = classID; }

	int GetID() { return id.Get(); }
	string GetName() { return name; }
	string GetClassID() { return classID; }
};

class ManagerMane
{
private:
	static list<unique_ptr<Manager>> managers;

public:
	//�V�����쐬
	static void Create(const int& idNum, const string& name, const string& classID);
	//�w�肵��ID�ԍ��̗v�f���폜
	//id:ID�ԍ�
	static void Delete(const int& id);
	//�w�肵��ID�ԍ��̗v�f��ҏW
	//id:ID�ԍ�
	static void Edit(const int& id);

	static Manager* GetData(const int& id);
	static void ShowAll();
	static int GetSize() { return (int)managers.size(); }
};