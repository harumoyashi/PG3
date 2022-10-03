#include <stdio.h>

int CamatuMoney(int money, int h)
{
	if (h <= 0)
	{
		return 0;
	}

	return money + CamatuMoney(money * 2 - 50, h - 1);
}

int main()
{
	int n = 8;
	int result = 0;

	printf("一般的な賃金体系:%d円\n", 1072 * n);
	printf("再帰的な賃金体系:%d円\n", CamatuMoney(100, n));


	if (1072 * n >= CamatuMoney(100, n))
	{
		printf("一般的な賃金体系の方が賃金が多くなる\n");
	}
	else
	{
		printf("再帰的な賃金体系の方が賃金が多くなる\n");
	}

	return (0);
}