#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <functional>

typedef void (*PFunc)(int);

void callback(int num)
{
	srand(time(nullptr));
	int random = rand();

	printf("ランダムで出た値は%dでした\n", random);

	//判定
	if (random % 2 == num % 2)
	{
		printf("当たり！");
	}
	else
	{
		printf("はずれ...");
	}
}

//コールバック関数
void setTimeout(PFunc p, int sec, int num)
{
	printf("結果は...\n");
	//コールバック関数呼び出す
	Sleep(sec *= 1000);
	p(num);
}

int main()
{
	PFunc p;
	int num = 0;
	p = callback;


	printf("「奇数」なら「1」を「偶数」なら「2」を入力してください\n");
	scanf_s("%d", &num);

	if (num == 1 || num == 2)
	{
		setTimeout(p, 3, num);
	}
	else
	{
		printf("その入力は受け付けてないよ");
	}

	return (0);
}