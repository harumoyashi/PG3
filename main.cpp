#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <functional>

typedef void (*PFunc)(int);

void callback(int num)
{
	srand(time(nullptr));
	int random = rand() % 6 + 1;

	printf("��������̏o�ڂ�%d�ł���\n", random);

	//����
	if (random % 2 == num % 2)
	{
		printf("������I");
	}
	else
	{
		printf("�͂���...");
	}
}

//�R�[���o�b�N�֐�
void setTimeout(PFunc p, int sec, int num)
{
	printf("���ʂ�...\n");
	//�R�[���o�b�N�֐��Ăяo��
	Sleep(sec *= 1000);
	p(num);
}

int main()
{
	PFunc p;
	int num = 0;
	p = callback;


	printf("�u���v�Ȃ�u1�v���u���v�Ȃ�u2�v����͂��Ă�������\n");
	scanf_s("%d", &num);

	if (num == 1 || num == 2)
	{
		setTimeout(p, 3, num);
	}
	else
	{
		printf("���̓��͎͂󂯕t���ĂȂ���");
	}

	return (0);
}