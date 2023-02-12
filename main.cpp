#include "TaskManager.h"
#include "PICManager.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	enum SceneType
	{
		Title,
		TaskShowAll,
		TaskAdd,
		TaskEdit,
		PICShowAll,
		PICAdd,
		PICEdit,

		MaxScene
	};
	//初期化
	int sceneNum = Title;
	int eleSceneNum = 0;
	int addSceneNum = 0;

	printf("ここは初期化の時点で事前に要素を入れているところです\n");
	printf("-----------------------------------------------------------------------\n");
	PICManager::Create(0, "アイカワ_ハルヒコ", "LE2A");

	TaskManager::Create(
		"タイマーのバグ",
		"シーン遷移してる間もタイマーが進んでいてクリアタイムがずれる",
		"高", 214, 0, 0);

	TaskManager::Create(
		"ボスの調整",
		"ボスの攻撃のクールタイムを1秒短くする",
		"中", 213, 1, 0, "完了");
	printf("-----------------------------------------------------------------------\n");

	//更新処理
	while (true)
	{
		//初期画面
		if (sceneNum == Title)
		{
			printf("============================\n");
			printf("[タイトル画面]\n1.タスクの一覧表示\n2.タスクの追加\n3.タスクの編集\n4.担当者の一覧表示\n5.担当者の追加\n6.担当者の編集\n");
			printf("============================\n");
			printf("操作を選択してください\n");
			printf("-----------------------------------------------------------------------\n");
			//シーン切り替え
			while (true)
			{
				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");

				if (num >= Title + 1 && num <= MaxScene - 1)
				{
					sceneNum = num;
					break;
				}
				else
				{
					printf("そんな操作ねえよ\n");
				}
			}
		}
		//タスク一覧
		else if (sceneNum == TaskShowAll)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[タスクの一覧表示]\n");

			TaskManager::ShowAll();
			printf("タスク数:%d個\n\n", (int)TaskManager::tasks.size());
			printf("-----------------------------------------------------------------------\n");

			//シーン切り替え
			printf("-----------------------------------------------------------------------\n");
			printf("0.初期画面に戻る\n");
			int num;
			scanf_s("%d", &num);
			scanf_s("%*[^\n]%*c");
			printf("-----------------------------------------------------------------------\n");
			while (sceneNum == TaskShowAll)
			{
				if (num == Title)
				{
					sceneNum = Title;
					break;
				}
				else
				{
					printf("0って言ってんだろ\n");
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");
				}
			}
		}
		//タスク追加
		else if (sceneNum == TaskAdd)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[タスクの追加]\n");

			char title[50]{}; char content[100]{}; string priority{}; int deadline{}; int id{}; int picID{};
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("タスクのタイトルを入力してください\n");

				scanf_s("%s", title, 50);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("タスクの内容を入力してください\n");

				scanf_s("%s", content, 100);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("タスクの優先度を選択してください\n");
				printf("-----------------------------------------------------------------------\n");

				while (true)
				{
					printf("============================\n");
					printf("1.高\n2.中\n3.低\n4.保留\n");
					printf("============================\n");

					int num;
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");

					if (num == 1)
					{
						priority = "高";
						break;
					}
					else if (num == 2)
					{
						priority = "中";
						break;
					}
					else if (num == 3)
					{
						priority = "低";
						break;
					}
					else if (num == 4)
					{
						priority = "保留";
						break;
					}
					else
					{
						printf("そんな操作ねえよ\n");
					}
				}

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("タスクの期限を入力してください\n月は先頭に「0」をつけず、3桁か4桁で入力してください(例:1月1日->101)\n");

				scanf_s("%d", &deadline);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("タスクのIDを入力してください\n");

				scanf_s("%d", &id);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("タスクの担当者IDを入力してください\n");

				scanf_s("%d", &picID);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			std::string t = title;
			std::string c = content;
			std::string p = priority;
			TaskManager::Create(t, c, p, deadline, id, picID);

			//シーン切り替え
			printf("-----------------------------------------------------------------------\n");
			printf("0.初期画面に戻る\n");
			int num;
			scanf_s("%d", &num);
			scanf_s("%*[^\n]%*c");
			printf("-----------------------------------------------------------------------\n");
			while (sceneNum == TaskAdd)
			{
				if (num == Title)
				{
					sceneNum = Title;
					break;
				}
				else
				{
					printf("0って言ってんだろ\n");
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");
				}
			}
		}
		//タスク編集
		else if (sceneNum == TaskEdit)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[タスクの編集]\n");
			printf("-----------------------------------------------------------------------\n");

			int id{};
			while (true)
			{
				printf("編集したいタスクのIDを入力してください\n");

				scanf_s("%d", &id);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			TaskManager::Edit(id);

			//シーン切り替え
			while (true)
			{
				if (sceneNum == 0)
				{
					printf("編集するものないから初期画面戻るよ\n");
					break;
				}
				else
				{
					printf("---------------------\n0.初期画面に戻る\n");
					int num;
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");

					if (num == 0)
					{
						sceneNum = num;
						break;
					}
					else
					{
						printf("0って言ってんだろ\n");
					}
				}
			}
		}
		//担当者一覧
		else if (sceneNum == PICShowAll)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[担当者の一覧表示]\n");

			PICManager::ShowAll();
			printf("-----------------------------------------------------------------------\n");
			printf("登録されてる担当者数:%d人\n\n", PICManager::GetSize());
			printf("-----------------------------------------------------------------------\n");

			//シーン切り替え
			printf("-----------------------------------------------------------------------\n");
			printf("0.初期画面に戻る\n");
			int num;
			scanf_s("%d", &num);
			scanf_s("%*[^\n]%*c");
			printf("-----------------------------------------------------------------------\n");
			while (sceneNum == PICShowAll)
			{
				if (num == Title)
				{
					sceneNum = Title;
					break;
				}
				else
				{
					printf("0って言ってんだろ\n");
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");
				}
			}
		}
		//担当者追加
		else if (sceneNum == PICAdd)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[担当者の追加]\n");
			printf("-----------------------------------------------------------------------\n");

			int id{}; char name[20]{}; char classID[9]{};

			while (true)
			{
				printf("担当者のIDを入力してください\n");

				scanf_s("%d", &id);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("担当者の名前を入力してください\n");

				scanf_s("%s", name, 20);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("担当者のクラス記号を入力してください\n");

				scanf_s("%s", classID, 9);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			string n = name;
			string c = classID;
			PICManager::Create(id, n, c);

			//シーン切り替え
			printf("-----------------------------------------------------------------------\n");
			printf("0.初期画面に戻る\n");
			int num;
			scanf_s("%d", &num);
			scanf_s("%*[^\n]%*c");
			printf("-----------------------------------------------------------------------\n");
			while (sceneNum == PICAdd)
			{
				if (num == Title)
				{
					sceneNum = Title;
					break;
				}
				else
				{
					printf("0って言ってんだろ\n");
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");
				}
			}
		}
		//担当者編集
		else if (sceneNum == PICEdit)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[担当者の編集]\n");
			printf("-----------------------------------------------------------------------\n");

			int id{};
			while (true)
			{
				printf("編集したい担当者のIDを入力してください\n");

				scanf_s("%d", &id);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			PICManager::Edit(id);

			//シーン切り替え
			printf("-----------------------------------------------------------------------\n");
			printf("0.初期画面に戻る\n");
			int num;
			scanf_s("%d", &num);
			scanf_s("%*[^\n]%*c");
			printf("-----------------------------------------------------------------------\n");
			while (sceneNum == PICEdit)
			{
				if (num == Title)
				{
					sceneNum = Title;
					break;
				}
				else
				{
					printf("0って言ってんだろ\n");
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");
				}
			}
		}
	}

	return (0);
}