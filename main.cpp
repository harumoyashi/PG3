#include <stdio.h>
#include <Windows.h>
#include <time.h>

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

	int num = 0;

	printf("�u�����v�Ȃ�0���u��v�Ȃ�1����͂��Ă�������\n");

	scanf_s("%d", &num);
	printf("�ҋ@��\n");

	PFunc p;
	p = callback;
	setTimeout(p, 3);

	//�����̏ꍇ
	if (num == 0)
	{
		printf("%d", random / 2 * 2);
	}
	//��̏ꍇ
	else if (num == 1)
	{
		printf("%d", random / 2 * 2 - 1);
	}
	//�n���p
	else
	{
		printf("���̕����̓��͎͂󂯕t���ĂȂ���");
	}


	return (0);
}