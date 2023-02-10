#include "Manager.h"

void ManagerMane::Create()
{
	std::unique_ptr<Manager> task = make_unique<Manager>();
	
	managers.emplace_back(task);
}

void ManagerMane::Delete(const int& elementNum)
{
	auto itr = managers.begin();
	for (int i = 0; i < elementNum; i++)
	{
		itr++;
	}
	managers.erase(itr);
}

void ManagerMane::SetID(const int& elementNum, const int& idNum)
{
	auto itr = managers.begin();
	for (int i = 0; i < elementNum; i++)
	{
		itr++;
	}
	itr->get()->SetID(idNum);
}

void ManagerMane::SetName(const int& elementNum, const string& name)
{
	auto itr = managers.begin();
	for (int i = 0; i < elementNum; i++)
	{
		itr++;
	}
	itr->get()->SetName(name);
}

void ManagerMane::SetClassID(const int& elementNum, const string& classID)
{
	auto itr = managers.begin();
	for (int i = 0; i < elementNum; i++)
	{
		itr++;
	}
	itr->get()->SetClassID(classID);
}
