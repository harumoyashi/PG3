#pragma once
#pragma once
#include "PIC.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
using namespace std;

class PICManager
{
private:
	static list<unique_ptr<PIC>> pics;

public:
	//�V�����쐬
	static void Create(const int& idNum, const string& name, const string& classID);
	//�w�肵��ID�ԍ��̗v�f���폜
	//id:ID�ԍ�
	static void Delete(const int& id);
	//�w�肵��ID�ԍ��̗v�f��ҏW
	//id:ID�ԍ�
	static void Edit(const int& id);
	//�w�肵��ID�ԍ��̗v�f���擾
	//id:ID�ԍ�
	static PIC* GetData(const int& id);
	//�S�Ă̗v�f�������
	static void ShowAll();
	//�^�X�N�̗v�f���擾
	static int GetSize() { return (int)pics.size(); }
};