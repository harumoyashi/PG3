#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <functional>

typedef void (*PFunc)(int*);

void callback(int* waitFrame)
{
}

//コールバック関数
void setTimeout(PFunc p, int sec)
{
	sec *= 1000;
	//コールバック関数呼び出す
	Sleep(sec);
	p(&sec);
}

int main()
{
	srand(time(nullptr));
	int random = rand();

	char string[5];

	printf("「偶数」か「奇数」を入力してください\n");

	scanf_s("%s", string, 5);
	printf("結果は...\n");

	PFunc p;
	p = callback;
	setTimeout(p, 3);

	printf("ランダムで出た値は%dでした\n", random);

	//偶数の場合
	if (strcmp(string, "偶数") == 0)
	{
		if (random % 2 == 0)
		{
			printf("当たり！");
		}
		else
		{
			printf("はずれ...");
		}
	}
	//奇数の場合
	else if (strcmp(string, "奇数") == 0)
	{
		if (random % 2 == 1)
		{
			printf("当たり！");
		}
		else
		{
			printf("はずれ...");
		}
	}
	//馬鹿用
	else
	{
		printf("その文字の入力は受け付けてないよ");
	}

	return (0);
}