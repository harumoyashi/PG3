#include "PICManager.h"

list<unique_ptr<PIC>> PICManager::pics{};

void PICManager::Create(const int& idNum, const string& name, const string& classID)
{
	unique_ptr<PIC> pic = make_unique<PIC>();
	pic->SetID(idNum);
	pic->SetName(name);
	pic->SetClassID(classID);

	pics.emplace_back(move(pic));
	printf("�ȉ��̏��ŒS���҂��ǉ�����܂���\nID:%d,�S���Җ�:%s,�N���X�L��:%s\n", idNum, name.c_str(), classID.c_str());
}

void PICManager::Delete(const int& id)
{
	for (auto itr = pics.begin(); itr != pics.end();)
	{
		if (itr->get()->GetID() == id)
		{
			itr = pics.erase(itr);
		}
		// �v�f�폜�����Ȃ��ꍇ�ɁA�C�e���[�^��i�߂�
		else {
			++itr;
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
				printf("[�ҏW���ڂ̑I��]\n0.�ҏW����߂�\n1.ID��ҏW\n2.�S���Җ���ҏW\n3.�N���X�L����ҏW\n4.�S���҂̍폜\n");
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
				if (editScene >= 0 && editScene <= 4)
				{
					break;
				}
				else
				{
					printf("����ȑ���˂���\n");
				}
			}

			int idNum{}; char name[20]{}; char classID[9]{};
			while (editScene == 1)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�S���҂�ID����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &idNum);
				scanf_s("%*[^\n]%*c");

				if (PICManager::GetData(idNum) != nullptr)
				{
					printf("�S����ID�u%d�v�͊��ɑ��݂��邽�ߕύX�ł��܂���\n", idNum);
					break;
				}

				PICManager::GetData(id)->SetID(idNum);
				break;
			}

			while (editScene == 2)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�S���҂̖��O����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%s", name, 20);
				scanf_s("%*[^\n]%*c");

				PICManager::GetData(id)->SetName(name);
				break;
			}

			while (editScene == 3)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�S���҂̃N���X�L������͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%s", classID, 9);
				scanf_s("%*[^\n]%*c");

				PICManager::GetData(id)->SetClassID(classID);
				break;
			}

			while (editScene == 4)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("ID:%d\n", PICManager::GetData(id)->GetID());
				printf("�S���Җ�:%s\n", PICManager::GetData(id)->GetName().c_str());
				printf("�N���XID:%s\n\n", PICManager::GetData(id)->GetClassID().c_str());
				printf("-----------------------------------------------------------------------\n");

				while (true)
				{
					printf("��L�̃^�X�N���폜���܂�����낵���ł����H\n");
					printf("0.�͂�\n1.������\n");
					int num;
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");

					if (num == 0)
					{
						Delete(id);
						printf("�폜���܂���\n");
						return;
					}
					else if (num == 1)
					{
						printf("�폜���������܂���\n");
						break;
					}
					else
					{
						printf("0��1�őI�������\n");
					}
				}
				break;
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
