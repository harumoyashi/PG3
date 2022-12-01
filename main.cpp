#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
	char name[8];
	struct cell* next;
}CELL;

//�f�[�^�̑}��
void Insert(CELL* endCell, const char* buf);
//�v�f�ꗗ�\��
int Index(CELL* endCell);
//���X�g�̍Ō�����폜
void Delete(CELL* endCell);

int sceneNum = 0;

int main()
{
	char name[8];

	CELL head;
	head.next = nullptr;	//�������I�Ȃ��Ƃ����Ă����Ȃ��ƃS�~���������Ⴄ

	while (true)
	{
		if (sceneNum == 0)
		{
			printf("[�v�f�̑���]\n1.�v�f�̈ꗗ�\��\n2.�Ō���ɗv�f�̑}��\n3.�Ō���̗v�f�̍폜\n\n");
			printf("---------------------\n�����I�����Ă�������\n");

			//�V�[���؂�ւ�
			while (true)
			{
				int num;
				scanf_s("%d", &num);
				if (num >= 1 && num <= 3)
				{
					sceneNum = num;
					break;
				}
				else
				{
					printf("����ȑ���˂���\n");
				}
			}
		}
		else if (sceneNum == 1)
		{
			printf("[�v�f�̈ꗗ�\��]\n�v�f�ꗗ:\n");

			int eleNum = 0;
			eleNum = Index(&head);

			printf("�v�f��:%d\n\n", eleNum);

			//�V�[���؂�ւ�
			printf("---------------------\n0.������ʂɖ߂�\n");
			while (true)
			{
				int num;
				scanf_s("%d", &num);

				if (num == 0)
				{
					sceneNum = num;
					break;
				}
				else
				{
					printf("0���Č����Ă񂾂�\n");
				}
			}
		}
		else if (sceneNum == 2)
		{
			printf("[���X�g�v�f�̑}��]\n�ǉ�����v�f�̒l����͂��Ă�������\n");

			while (true)
			{
				scanf_s("%s", name, 8);

				Insert(&head, name);
				break;
			}

			//�V�[���؂�ւ�
			printf("---------------------\n0.������ʂɖ߂�\n");
			while (true)
			{
				int num;
				scanf_s("%d", &num);

				if (num == 0)
				{
					sceneNum = num;
					break;
				}
				else
				{
					printf("0���Č����Ă񂾂�\n");
				}
			}
		}
		else if (sceneNum == 3)
		{
			printf("[�v�f�̍폜]\n\n");
			Delete(&head);

			//�V�[���؂�ւ�
			printf("---------------------\n0.������ʂɖ߂�\n");
			while (true)
			{
				int num;
				scanf_s("%d", &num);

				if (num == 0)
				{
					sceneNum = num;
					break;
				}
				else
				{
					printf("0���Č����Ă񂾂�\n");
				}
			}
		}
	}

	return (0);
}

void Insert(CELL* endCell, const char* buf)
{
	//�V�K�ɃZ�����쐬//
	CELL* cell;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	cell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(cell->name, 8, buf);
	cell->next = nullptr;
	printf("%s���Ō���ɒǉ�����܂���\n", cell->name);

	//�ǉ�����O�̍Ō��������//
	//�ŐV�̃Z���̃A�h���X�̈�ڂ̏����͈������玝���Ă������X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
	}

	//�ǉ�����O�̍Ō���ɐV�K�Z���̃|�C���^����//
	endCell->next = cell;
}

int Index(CELL* endCell)
{
	int eleNum = 0;
	//next�ɉ����������Ă����o��//
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%s\n", endCell->name);

		eleNum++;
	}
	return eleNum;
}

void Delete(CELL* endCell)
{
	while (endCell->next->next != nullptr)
	{
		endCell = endCell->next;
	}
	endCell->next = nullptr;
	printf("�Ō���̗v�f���폜���܂���");
}
