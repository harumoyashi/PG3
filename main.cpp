#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <functional>

typedef void (*PFunc)(int);

void Lottery(int num)
{
	srand(time(nullptr));
	int random = rand() % 6 + 1;

	printf("��������̏o�ڂ�%d�ł���\n", random);

	//����
	random % 2 == num % 2 ? printf("������I") : printf("�͂���...");
}

int main()
{
	PFunc p;
	p = Lottery;
	int num = 0;

	printf("�u���v�Ȃ�u1�v���u���v�Ȃ�u2�v����͂��Ă�������\n");
	scanf_s("%d", &num);

	std::function<void(PFunc, int)>setTimeout = [=](PFunc p, int sec)
	{
		printf("���ʂ�...\n");
		//�R�[���o�b�N�֐��Ăяo��
		Sleep(sec *= 1000);
		p(num);
	};

	if (num == 1 || num == 2)
	{
		setTimeout(p, 3);
	}
	else
	{
		printf("���̓��͎͂󂯕t���ĂȂ���");
	}

	return (0);
}