#include <stdio.h>

int CamatuMoney(int n)
{
	int result;
	if (n == n)
	{
		result = 100;
		return result;
	}
	else if (n <= 1)
	{
		result * 2 - 50;
	}

	return  (CamatuMoney(n - 1));
}

int main()
{
	int n = 5;
	int result;

	result = CamatuMoney(n);
	printf("%d", result);

	return (0);
}