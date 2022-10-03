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

}