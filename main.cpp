#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
	char name[8];
	struct cell* next;
}CELL;

//データの挿入
void Insert(CELL* endCell, const char* buf);
//要素一覧表示
int Index(CELL* endCell);
//リストの最後尾を削除
void Delete(CELL* endCell);

int sceneNum = 0;

int main()
{
	char name[8];

	CELL head;
	head.next = nullptr;	//初期化的なことをしてあげないとゴミが入っちゃう

	while (true)
	{
		if (sceneNum == 0)
		{
			printf("[要素の操作]\n1.要素の一覧表示\n2.最後尾に要素の挿入\n3.最後尾の要素の削除\n\n");
			printf("---------------------\n操作を選択してください\n");

			//シーン切り替え
			while (true)
			{
				int num;
				scanf_s("%d", &num);
				if (num >= 1 && num <= 3)
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
		else if (sceneNum == 1)
		{
			printf("[要素の一覧表示]\n要素一覧:\n");

			int eleNum = 0;
			eleNum = Index(&head);

			printf("要素数:%d\n\n", eleNum);

			//シーン切り替え
			printf("---------------------\n0.初期画面に戻る\n");
			while (true)
			{
				int num;
				scanf_s("%d", &num);

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
		else if (sceneNum == 2)
		{
			printf("[リスト要素の挿入]\n追加する要素の値を入力してください\n");

			while (true)
			{
				scanf_s("%s", name, 8);

				Insert(&head, name);
				break;
			}

			//シーン切り替え
			printf("---------------------\n0.初期画面に戻る\n");
			while (true)
			{
				int num;
				scanf_s("%d", &num);

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
		else if (sceneNum == 3)
		{
			printf("[要素の削除]\n\n");
			Delete(&head);

			//シーン切り替え
			printf("---------------------\n0.初期画面に戻る\n");
			while (true)
			{
				int num;
				scanf_s("%d", &num);

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

	return (0);
}

void Insert(CELL* endCell, const char* buf)
{
	//新規にセルを作成//
	CELL* cell;
	//新規作成するセル分のメモリを確保する
	cell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(cell->name, 8, buf);
	cell->next = nullptr;
	printf("%sが最後尾に追加されました\n", cell->name);

	//追加する前の最後尾を検索//
	//最新のセルのアドレスの一つ目の処理は引数から持ってきたリストのうち最初のセルのアドレスが該当する
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
	}

	//追加する前の最後尾に新規セルのポインタを代入//
	endCell->next = cell;
}

int Index(CELL* endCell)
{
	int eleNum = 0;
	//nextに何かが入ってる限り出力//
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%s\n", endCell->name);

		eleNum++;
	}
	return eleNum;
}

void Delete(CELL* endCell)
{
	while (endCell->next->next != nullptr)
	{
		endCell = endCell->next;
	}
	endCell->next = nullptr;
	printf("最後尾の要素を削除しました");
}
