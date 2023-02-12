#include "PICManager.h"

list<unique_ptr<PIC>> PICManager::pics{};

void PICManager::Create(const int& idNum, const string& name, const string& classID)
{
	unique_ptr<PIC> pic = make_unique<PIC>();
	pic->SetID(idNum);
	pic->SetName(name);
	pic->SetClassID(classID);

	pics.emplace_back(move(pic));
	printf("以下の情報が追加されました\nID:%d,担当者名:%s,クラス記号:%s\n", idNum, name.c_str(), classID.c_str());
}

void PICManager::Delete(const int& id)
{
	for (auto itr = pics.begin(); itr != pics.end(); itr++)
	{
		if (itr->get()->GetID() == id)
		{
			pics.erase(itr);
			printf("%dを削除しました\n", id);
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
				printf("[編集項目の選択]\n0.編集をやめる\n1.IDを編集\n2.担当者名を編集\n3.クラス記号を編集\n");
				printf("============================\n");
				printf("操作を選択してください\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%d", &editScene);
				scanf_s("%*[^\n]%*c");

				if (editScene == 0)
				{
					printf("編集を終わります\n");
					return;
				}
				if (editScene >= 0 && editScene <= 7)
				{
					break;
				}
				else
				{
					printf("そんな操作ねえよ\n");
				}
			}

			for (auto itr = pics.begin(); itr != pics.end(); itr++)
			{
				int idNum{}; char name[20]{}; char classID[9]{};
				while (editScene == 1)
				{
					printf("-----------------------------------------------------------------------\n");
					printf("担当者のIDを入力してください\n");
					printf("変更しない場合は「0」を入力してください\n");
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
					printf("担当者の名前を入力してください\n");
					printf("変更しない場合は「0」を入力してください\n");
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
					printf("担当者のクラス記号を入力してください\n");
					printf("変更しない場合は「0」を入力してください\n");
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
	printf("そんなIDのやついないよ\n");
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
		printf("担当者名:%s\n", itr->get()->GetName().c_str());
		printf("クラスID:%s\n\n", itr->get()->GetClassID().c_str());
	}
}
