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
	//�V�����쐬
	void Create();
	//�w�肵���v�f�ԍ��̗v�f���폜
	//elementNum:�v�f�ԍ�
	void Delete(const int& elementNum);

	void SetID(const int& elementNum, const int& idNum);
	void SetName(const int& elementNum, const string& name);
	void SetClassID(const int& elementNum, const string& classID);
};