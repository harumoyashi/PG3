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

	printf("ˆê”Ê“I‚È’À‹à‘ÌŒn:%d‰~\n", 1072 * n);
	printf("Ä‹A“I‚È’À‹à‘ÌŒn:%d‰~\n", CamatuMoney(100, n));


	if (1072 * n >= CamatuMoney(100, n))
	{
		printf("ˆê”Ê“I‚È’À‹à‘ÌŒn‚Ì•û‚ª’À‹à‚ª‘½‚­‚È‚é\n");
	}
	else
	{
		printf("Ä‹A“I‚È’À‹à‘ÌŒn‚Ì•û‚ª’À‹à‚ª‘½‚­‚È‚é\n");
	}

	return (0);
}