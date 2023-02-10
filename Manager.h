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
};

class ManagerMane
{
private:
	list<std::unique_ptr<Manager>> managers;

public:
	//新しく作成
	void Create();
	//指定した要素番号の要素を削除
	//elementNum:要素番号
	void Delete(const int& elementNum);

	void SetID(const int& elementNum, const int& idNum);
	void SetName(const int& elementNum, const string& name);
	void SetClassID(const int& elementNum, const string& classID);
};