#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
	char name[8];
	struct cell* prev;
	struct cell* next;
}CELL;

//�f�[�^�̑}��
void Insert(CELL* currentCell, const char* buf);
void PushBack(CELL* currentCell, const char* buf);
//�v�f�ꗗ�\��
int Index(CELL* endCell);
//���X�g�̍Ō�����폜
void Delete(CELL* deleteCell, int iterator);
//�ҏW
void Edit(CELL* editCell);
//�C�ӂ̈ʒu�܂ŃA�h���X�����ǂ�
CELL* GetInsertCellAddress(CELL* endCell, int iterator);

int sceneNum = 0;
int eleSceneNum = 0;
int addSceneNum = 0;

int main()
{
	int iterator = 0;
	char name[8];
	CELL* insertCell{};

	int eleNum = 0;

	CELL head;
	head.prev = nullptr;	//�������I�Ȃ��Ƃ����Ă����Ȃ��ƃS�~���������Ⴄ
	head.next = nullptr;	//�������I�Ȃ��Ƃ����Ă����Ȃ��ƃS�~���������Ⴄ

	while (true)
	{
		//�������
		if (sceneNum == 0)
		{
			printf("[�v�f�̑���]\n1.�v�f�̈ꗗ�\��\n2.�v�f�̑}��\n3.�v�f�̕ҏW\n4.�Ō���̗v�f�̍폜\n\n");
			printf("---------------------\n�����I�����Ă�������\n");

			//�V�[���؂�ւ�
			while (true)
			{
				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");

				if (num >= 1 && num <= 4)
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
		//�v�f�ꗗ
		else if (sceneNum == 1)
		{
			printf("[�v�f�̕\��]\n1.�v�f�̈ꗗ�\��\n2.���Ԃ��w�肵�ėv�f��\��\n3.������ʂɖ߂�\n\n");
			printf("---------------------\n�����I�����Ă�������\n");

			//�V�[���؂�ւ�
			while (true)
			{
				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");
				if (num >= 1 && num <= 3)
				{
					eleSceneNum = num;
					break;
				}
				else
				{
					printf("����ȑ���˂���\n");
				}
			}

			if (eleSceneNum == 1)
			{
				printf("[�v�f�̈ꗗ�\��]\n�v�f�ꗗ:\n");

				eleNum = Index(&head);

				if (head.next == nullptr)
				{
					printf("���݂��܂���\n");
				}

				printf("�v�f��:%d\n\n", eleNum);

				printf("---------------------\n1.[�v�f�̕\��]�ɖ߂�\n2.������ʂɖ߂�\n");

				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");

				if (num == 1)
				{
					sceneNum = 1;
				}
				else if (num == 2)
				{
					sceneNum = 0;
				}
				else
				{
					printf("����ȑ���˂���\n");
				}
			}
			if (eleSceneNum == 2)
			{
				printf("[���Ԃ��w�肵�ėv�f��\��]\n�\���������v�f�̏��Ԃ��w�肵�Ă�������\n");

				scanf_s("%d", &iterator);
				scanf_s("%*[^\n]%*c");

				insertCell = GetInsertCellAddress(&head, iterator);
				if (insertCell->next != nullptr)
				{
					printf("%d�Ԗڂ̗v�f��%s�ł�\n", iterator, insertCell->name);
				}
				else
				{
					printf("���݂��܂���\n");
				}

				printf("---------------------\n1.[�v�f�̕\��]�ɖ߂�\n2.������ʂɖ߂�\n");

				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");

				if (num == 1)
				{
					sceneNum = 1;
				}
				else if (num == 2)
				{
					sceneNum = 0;
				}
				else
				{
					printf("����ȑ���˂���\n");
				}
			}
			if (eleSceneNum == 3)
			{
				sceneNum = 0;
			}

			//�V�[���؂�ւ�
			while (sceneNum != 1)
			{
				if (sceneNum == 0)
				{
					break;
				}
				else
				{
					printf("---------------------\n0.������ʂɖ߂�\n");
					int num;
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");

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
		//�}��
		else if (sceneNum == 2)
		{
			while (true)
			{
				printf("[���X�g�v�f�̑}��]\n0.�Ō���ɒǉ�����\n1.�v�f�ԍ����w�肵�Ēǉ�����\n");

				int num;

				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");

				if (num == 0)
				{
					printf("�ǉ�����v�f�̓��e����͂��Ă�������\n");
					scanf_s("%s", name, 8);
					PushBack(&head, name);
					addSceneNum = 1;
					break;
				}
				else if (num == 1)
				{
					addSceneNum = 0;
					break;
				}
				else
				{
					printf("����ȑ���˂���\n");
				}
			}

			while (addSceneNum == 0)
			{
				printf("�ǉ�����v�f������͂��Ă�������\n");

				scanf_s("%d", &iterator);
				scanf_s("%*[^\n]%*c");

				insertCell = GetInsertCellAddress(&head, iterator);

				break;
			}

			while (addSceneNum == 0)
			{
				printf("�ǉ�����v�f�̓��e����͂��Ă�������\n");

				scanf_s("%s", name, 8);

				Insert(insertCell, name);
				printf("%s��%d�Ԗڂɒǉ�����܂���\n", insertCell->next->name, iterator);
				break;
			}

			//�V�[���؂�ւ�
			printf("---------------------\n0.������ʂɖ߂�\n");
			while (true)
			{
				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");

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
		//�ҏW
		else if (sceneNum == 3)
		{
			printf("[�v�f�̕ҏW]\n�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");

			scanf_s("%d", &iterator);
			scanf_s("%*[^\n]%*c");

			insertCell = GetInsertCellAddress(&head, iterator);
			if (insertCell->next != nullptr)
			{
				Edit(insertCell);
				printf("%d�Ԗڂ̗v�f��%s�ɕύX����܂���\n", iterator, insertCell->next->name);
			}
			else
			{
				printf("%d�Ԗڂ̗v�f�͑��݂��܂���\n", iterator);
				sceneNum = 0;
			}

			//�V�[���؂�ւ�
			while (true)
			{
				if (sceneNum == 0)
				{
					printf("�ҏW������̂Ȃ����珉����ʖ߂��\n");
					break;
				}
				else
				{
					printf("---------------------\n0.������ʂɖ߂�\n");
					int num;
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");

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
		//�폜
		else if (sceneNum == 4)
		{
			//���������ĂȂ�������߂�
			printf("[�v�f�̍폜]\n�폜�������v�f�̔ԍ����w�肵�Ă�������\n");

			scanf_s("%d", &iterator);
			scanf_s("%*[^\n]%*c");


			Delete(&head, iterator);

			/*printf("%d�Ԗڂ̗v�f�͑��݂��܂���\n", iterator);
			sceneNum = 0;*/

			//�V�[���؂�ւ�
			while (true)
			{
				if (sceneNum == 0)
				{
					printf("�폜������̂Ȃ����珉����ʖ߂��\n");
					break;
				}
				else
				{
					printf("---------------------\n0.������ʂɖ߂�\n");
					int num;
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");

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
	}

	return (0);
}

void Insert(CELL* currentCell, const char* buf)
{
	//�V�K�ɃZ�����쐬//
	CELL* cell;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	cell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(cell->name, 8, buf);
	cell->prev = currentCell;
	cell->next = currentCell->next;

	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = cell;
	}

	//�ǉ�����O�̍Ō���ɐV�K�Z���̃|�C���^����//
	currentCell->next = cell;
	cell->prev = currentCell;
}

void PushBack(CELL* currentCell, const char* buf)
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
	while (currentCell->next != nullptr)
	{
		currentCell = currentCell->next;
	}

	//�ǉ�����O�̍Ō���ɐV�K�Z���̃|�C���^����//
	currentCell->next = cell;
	cell->prev = currentCell;
}

int Index(CELL* endCell)
{
	int eleNum = 0;
	//next�ɉ����������Ă����o��//
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%d:%s\n", eleNum, endCell->name);

		eleNum++;
	}
	return eleNum;
}

void Delete(CELL* deleteCell, int iterator)
{
	//�w�肳�ꂽ�v�f�܂Ői�߂�
	for (int i = 0; i <= iterator; i++)
	{
		deleteCell = deleteCell->next;
		if (deleteCell->next == nullptr)
		{
			printf("�Ō���̗v�f%s���폜���܂���\n", deleteCell->prev->next->name);
			deleteCell->prev->next = nullptr;
			break;
		}
	}

	//�Ō���߂��Ă���Ō���폜
	//�Ō���ȊO�Ȃ�w�肳�ꂽ�v�f���폜
	if (deleteCell->prev->next != nullptr)
	{
		printf("%d�Ԗڂ̗v�f��%s�폜���܂���\n", iterator, deleteCell->name);
		deleteCell->prev->next = deleteCell->next;
		deleteCell->next->prev = deleteCell->prev;
	}

}

void Edit(CELL* editCell)
{
	char name[8];
	scanf_s("%s", name, 8);

	//name[8] = 0;
	strcpy_s(editCell->next->name, 8, name);
}

CELL* GetInsertCellAddress(CELL* endCell, int iterator)
{
	for (int i = 0; i < iterator; i++)
	{
		if (endCell->next)
		{
			endCell = endCell->next;
		}
		else
		{
			break;
		}
	}
	return endCell;
}
