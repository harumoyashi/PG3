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

	printf("��ʓI�Ȓ����̌n:%d�~\n", 1072 * n);
	printf("�ċA�I�Ȓ����̌n:%d�~\n", CamatuMoney(100, n));


	if (1072 * n >= CamatuMoney(100, n))
	{
		printf("��ʓI�Ȓ����̌n�̕��������������Ȃ�\n");
	}
	else
	{
		printf("�ċA�I�Ȓ����̌n�̕��������������Ȃ�\n");
	}

	return (0);
}