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
	//新しく作成
	static void Create(const int& idNum, const string& name, const string& classID);
	//指定したID番号の要素を削除
	//id:ID番号
	static void Delete(const int& id);
	//指定したID番号の要素を編集
	//id:ID番号
	static void Edit(const int& id);
	//指定したID番号の要素を取得
	//id:ID番号
	static PIC* GetData(const int& id);
	//全ての要素を見れる
	static void ShowAll();
	//タスクの要素数取得
	static int GetSize() { return (int)pics.size(); }
};