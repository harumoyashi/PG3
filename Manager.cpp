#include "Manager.h"

list<unique_ptr<Manager>> ManagerMane::managers{};

void ManagerMane::Create(const int& idNum, const string& name, const string& classID)
{
	unique_ptr<Manager> manager = make_unique<Manager>();
	manager->SetID(idNum);
	manager->SetName(name);
	manager->SetClassID(classID);

	managers.emplace_back(move(manager));
	printf("�ȉ��̏�񂪒ǉ�����܂���\nID:%d,�S���Җ�:%s,�N���X�L��:%s\n", idNum, name.c_str(), classID.c_str());
}

void ManagerMane::Delete(const int& id)
{
	for (auto itr = managers.begin(); itr != managers.end(); itr++)
	{
		if (itr->get()->GetID() == id)
		{
			managers.erase(itr);
			printf("%d���폜���܂���\n", id);
		}
	}
}

void ManagerMane::Edit(const int& id)
{
	if (ManagerMane::GetData(id) != nullptr)
	{
		for (auto itr = managers.begin(); itr != managers.end(); itr++)
		{
			int idNum{}; char name[20]{}; char classID[9]{};
			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�S���҂�ID����͂��Ă�������\n");
				printf("�ύX���Ȃ��ꍇ�́u0�v����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &idNum);
				scanf_s("%*[^\n]%*c");

				if (idNum != 0)
				{
					itr->get()->SetID(idNum);
				}
				break;
			}

			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�S���҂̖��O����͂��Ă�������\n");
				printf("�ύX���Ȃ��ꍇ�́u0�v����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%s", name, 20);
				scanf_s("%*[^\n]%*c");

				if (name != 0)
				{
					itr->get()->SetName(name);
				}
				break;
			}

			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�S���҂̃N���X�L������͂��Ă�������\n");
				printf("�ύX���Ȃ��ꍇ�́u0�v����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%s", classID, 9);
				scanf_s("%*[^\n]%*c");

				if (classID != 0)
				{
					itr->get()->SetClassID(classID);
				}
				break;
			}
			return;
		}
	}
	printf("�����ID�̂���Ȃ���\n");
	return;
}

Manager* ManagerMane::GetData(const int& id)
{
	for (auto itr = managers.begin(); itr != managers.end(); itr++)
	{
		if (itr->get()->GetID() == id)
		{
			return itr->get();
		}
	}

	return nullptr;
}

void ManagerMane::ShowAll()
{
	for (auto itr = managers.begin(); itr != managers.end(); itr++)
	{
		printf("-----------------------------------------------------------------------\n");
		printf("ID:%d\n", itr->get()->GetID());
		printf("�S���Җ�:%s\n", itr->get()->GetName().c_str());
		printf("�N���XID:%s\n\n", itr->get()->GetClassID().c_str());
	}
}
