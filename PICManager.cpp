#include "PICManager.h"

list<unique_ptr<PIC>> PICManager::pics{};

void PICManager::Create(const int& idNum, const string& name, const string& classID)
{
	unique_ptr<PIC> pic = make_unique<PIC>();
	pic->SetID(idNum);
	pic->SetName(name);
	pic->SetClassID(classID);

	pics.emplace_back(move(pic));
	printf("�ȉ��̏�񂪒ǉ�����܂���\nID:%d,�S���Җ�:%s,�N���X�L��:%s\n", idNum, name.c_str(), classID.c_str());
}

void PICManager::Delete(const int& id)
{
	for (auto itr = pics.begin(); itr != pics.end(); itr++)
	{
		if (itr->get()->GetID() == id)
		{
			pics.erase(itr);
			printf("%d���폜���܂���\n", id);
		}
	}
}

void PICManager::Edit(const int& id)
{
	if (PICManager::GetData(id) != nullptr)
	{
		int editScene;
		while (true)
		{
			while (true)
			{
				printf("============================\n");
				printf("[�ҏW���ڂ̑I��]\n0.�ҏW����߂�\n1.ID��ҏW\n2.�S���Җ���ҏW\n3.�N���X�L����ҏW\n");
				printf("============================\n");
				printf("�����I�����Ă�������\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%d", &editScene);
				scanf_s("%*[^\n]%*c");

				if (editScene == 0)
				{
					printf("�ҏW���I���܂�\n");
					return;
				}
				if (editScene >= 0 && editScene <= 7)
				{
					break;
				}
				else
				{
					printf("����ȑ���˂���\n");
				}
			}

			for (auto itr = pics.begin(); itr != pics.end(); itr++)
			{
				int idNum{}; char name[20]{}; char classID[9]{};
				while (editScene == 1)
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

				while (editScene == 2)
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

				while (editScene == 3)
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
			}
		}
	}
	printf("�����ID�̂���Ȃ���\n");
	return;
}

PIC* PICManager::GetData(const int& id)
{
	for (auto itr = pics.begin(); itr != pics.end(); itr++)
	{
		if (itr->get()->GetID() == id)
		{
			return itr->get();
		}
	}

	return nullptr;
}

void PICManager::ShowAll()
{
	for (auto itr = pics.begin(); itr != pics.end(); itr++)
	{
		printf("-----------------------------------------------------------------------\n");
		printf("ID:%d\n", itr->get()->GetID());
		printf("�S���Җ�:%s\n", itr->get()->GetName().c_str());
		printf("�N���XID:%s\n\n", itr->get()->GetClassID().c_str());
	}
}
