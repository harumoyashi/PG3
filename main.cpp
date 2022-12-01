#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
	char name[8];
	struct cell* prev;
	struct cell* next;
}CELL;

//データの挿入
void Insert(CELL* currentCell, const char* buf);
//要素一覧表示
int Index(CELL* endCell);
//リストの最後尾を削除
void Delete(CELL* deleteCell);
//編集
void Edit(CELL* editCell);
//任意の位置までアドレスをたどる
CELL* GetInsertCellAddress(CELL* endCell, int iterator);

int sceneNum = 0;
int eleSceneNum = 0;

int main()
{
	int iterator = 0;
	char name[8];
	CELL* insertCell;

	int eleNum = 0;

	CELL head;
	head.prev = nullptr;	//初期化的なことをしてあげないとゴミが入っちゃう
	head.next = nullptr;	//初期化的なことをしてあげないとゴミが入っちゃう

	while (true)
	{
		//初期画面
		if (sceneNum == 0)
		{
			printf("[要素の操作]\n1.要素の一覧表示\n2.最後尾に要素の挿入\n3.要素の編集\n4.最後尾の要素の削除\n\n");
			printf("---------------------\n操作を選択してください\n");

			//シーン切り替え
			while (true)
			{
				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");

				if (num >= 1 && num <= 4)
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
		//要素一覧
		else if (sceneNum == 1)
		{
			printf("[要素の表示]\n1.要素の一覧表示\n2.順番を指定して要素を表示\n3.初期画面に戻る\n\n");
			printf("---------------------\n操作を選択してください\n");

			//シーン切り替え
			while (true)
			{
				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");
				if (num >= 1 && num <= 3)
				{
					eleSceneNum = num;
					break;
				}
				else
				{
					printf("そんな操作ねえよ\n");
				}
			}

			if (eleSceneNum == 1)
			{
				printf("[要素の一覧表示]\n要素一覧:\n");

				eleNum = Index(&head);

				if (head.next == nullptr)
				{
					printf("存在しません\n");
				}

				printf("要素数:%d\n\n", eleNum);

				printf("---------------------\n1.[要素の表示]に戻る\n2.初期画面に戻る\n");

				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");

				if (num == 1)
				{
					sceneNum = 1;
				}
				else if (num == 2)
				{
					sceneNum = 0;
				}
				else
				{
					printf("そんな操作ねえよ\n");
				}
			}
			if (eleSceneNum == 2)
			{
				printf("[順番を指定して要素を表示]\n表示したい要素の順番を指定してください\n");

				scanf_s("%d", &iterator);
				scanf_s("%*[^\n]%*c");

				insertCell = GetInsertCellAddress(&head, iterator);
				if (insertCell->next != nullptr)
				{
					printf("%d番目の要素は%sです\n", iterator, insertCell->name);
				}
				else
				{
					printf("存在しません\n");
				}

				printf("---------------------\n1.[要素の表示]に戻る\n2.初期画面に戻る\n");

				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");

				if (num == 1)
				{
					sceneNum = 1;
				}
				else if (num == 2)
				{
					sceneNum = 0;
				}
				else
				{
					printf("そんな操作ねえよ\n");
				}
			}
			if (eleSceneNum == 3)
			{
				sceneNum = 0;
			}

			//シーン切り替え
			while (sceneNum != 1)
			{
				if (sceneNum == 0)
				{
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
		//挿入
		else if (sceneNum == 2)
		{
			printf("[リスト要素の挿入]\n追加する要素数を入力してください\n");

			while (true)
			{
				scanf_s("%d", &iterator);
				scanf_s("%*[^\n]%*c");

				insertCell = GetInsertCellAddress(&head, iterator);

				break;
			}

			while (true)
			{
				printf("[リスト要素の挿入]\n追加する要素の内容を入力してください\n");

				scanf_s("%s", name, 8);

				Insert(insertCell, name);
				printf("%sが%d番目に追加されました\n", insertCell->next->name, iterator);
				break;
			}

			//シーン切り替え
			printf("---------------------\n0.初期画面に戻る\n");
			while (true)
			{
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
		//編集
		else if (sceneNum == 3)
		{
			printf("[要素の編集]\n編集したい要素の番号を指定してください\n");

			scanf_s("%d", &iterator);
			scanf_s("%*[^\n]%*c");

			insertCell = GetInsertCellAddress(&head, iterator);
			if (insertCell->next != nullptr)
			{
				Edit(insertCell);
				printf("%d番目の要素が%sに変更されました\n", iterator, insertCell->next->name);
			}
			else
			{
				printf("%d番目の要素は存在しません\n", iterator);
				sceneNum = 0;
			}

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
		//削除
		else if (sceneNum == 4)
		{
			//何も入ってなかったら戻す

			printf("[要素の削除]\n削除したい要素の番号を指定してください\n");

			scanf_s("%d", &iterator);
			scanf_s("%*[^\n]%*c");

			insertCell = GetInsertCellAddress(&head, iterator);
			if (insertCell->next != nullptr)
			{
				Delete(insertCell);
				printf("%d番目の要素を%s削除しました\n", iterator, insertCell->name);
			}
			else
			{
				printf("%d番目の要素は存在しません\n", iterator);
				sceneNum = 0;
			}

			//シーン切り替え
			while (true)
			{
				if (sceneNum == 0)
				{
					printf("削除するものないから初期画面戻るよ\n");
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
	}

	return (0);
}

void Insert(CELL* currentCell, const char* buf)
{
	//新規にセルを作成//
	CELL* cell;
	//新規作成するセル分のメモリを確保する
	cell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(cell->name, 8, buf);
	cell->prev = currentCell;
	cell->next = currentCell->next;

	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = cell;
	}

	//追加する前の最後尾に新規セルのポインタを代入//
	currentCell->next = cell;
}

int Index(CELL* endCell)
{
	int eleNum = 0;
	//nextに何かが入ってる限り出力//
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%d:%s\n", eleNum, endCell->name);

		eleNum++;
	}
	return eleNum;
}

void Delete(CELL* endCell)
{
	//最後尾削除
	while (endCell->next->next != nullptr)
	{
		endCell = endCell->next;
	}
	endCell->next = nullptr;
}

void Edit(CELL* editCell)
{
	char name[8];
	scanf_s("%s", name, 8);

	strcpy_s(editCell->next->name, 8, name);
}

CELL* GetInsertCellAddress(CELL* endCell, int iterator)
{
	for (int i = 0; i < iterator; i++)
	{
		if (endCell->next)
		{
			endCell = endCell->next;
		}
		else
		{
			break;
		}
	}
	return endCell;
}
