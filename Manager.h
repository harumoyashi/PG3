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
	//新しく作成
	static void Create(const int& idNum, const string& name, const string& classID);
	//指定したID番号の要素を削除
	//id:ID番号
	static void Delete(const int& id);
	//指定したID番号の要素を編集
	//id:ID番号
	static void Edit(const int& id);

	static Manager* GetData(const int& id);
	static void ShowAll();
	static int GetSize() { return (int)managers.size(); }
};