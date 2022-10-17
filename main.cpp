#include <stdio.h>
#include <Windows.h>
#include <time.h>

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

	int num = 0;

	printf("「偶数」なら0を「奇数」なら1を入力してください\n");

	scanf_s("%d", &num);
	printf("待機中\n");

	PFunc p;
	p = callback;
	setTimeout(p, 3);

	//偶数の場合
	if (num == 0)
	{
		printf("%d", random / 2 * 2);
	}
	//奇数の場合
	else if (num == 1)
	{
		printf("%d", random / 2 * 2 - 1);
	}
	//馬鹿用
	else
	{
		printf("その文字の入力は受け付けてないよ");
	}


	return (0);
}