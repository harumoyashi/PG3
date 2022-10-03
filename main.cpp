#include <stdio.h>

int CamatuMoney(int n,int result = 100)
{
	if (n < 1)
	{
		return result;
	}
	result * 2 - 50;

	return CamatuMoney(n - 1);
}

int main()
{
	int n = 3;
	int result = 0;

	result += CamatuMoney(n);
	printf("%d", result);

	return (0);
}