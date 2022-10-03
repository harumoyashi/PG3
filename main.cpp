#include <stdio.h>

int CamatuMoney(int n,int result = 0)
{
	if (n <= 1)
	{
		result += 100;
		return result;
	}
	
	return (CamatuMoney(n - 1) * 2 - 50);
}

int main()
{
	int n = 3;
	int result = 0;

	result += CamatuMoney(n);
	printf("%d", result);

	return (0);
}