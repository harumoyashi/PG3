#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <functional>

typedef void (*PFunc)(int*);

void callback(int* waitFrame)
{
}

//�R�[���o�b�N�֐�
void setTimeout(PFunc p, int sec)
{
	sec *= 1000;
	//�R�[���o�b�N�֐��Ăяo��
	Sleep(sec);
	p(&sec);
}

int main()
{
	srand(time(nullptr));
	int random = rand();

	char string[5];

	printf("�u�����v���u��v����͂��Ă�������\n");

	scanf_s("%s", string, 5);
	printf("���ʂ�...\n");

	PFunc p;
	p = callback;
	setTimeout(p, 3);

	printf("�����_���ŏo���l��%d�ł���\n", random);

	//�����̏ꍇ
	if (strcmp(string, "����") == 0)
	{
		if (random % 2 == 0)
		{
			printf("������I");
		}
		else
		{
			printf("�͂���...");
		}
	}
	//��̏ꍇ
	else if (strcmp(string, "�") == 0)
	{
		if (random % 2 == 1)
		{
			printf("������I");
		}
		else
		{
			printf("�͂���...");
		}
	}
	//�n���p
	else
	{
		printf("���̕����̓��͎͂󂯕t���ĂȂ���");
	}

	return (0);
}