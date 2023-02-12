#include "TaskManager.h"
#include "PICManager.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	enum SceneType
	{
		Title,
		TaskShowAll,
		TaskAdd,
		TaskEdit,
		PICShowAll,
		PICAdd,
		PICEdit,

		MaxScene
	};
	//������
	int sceneNum = Title;
	int eleSceneNum = 0;
	int addSceneNum = 0;

	printf("�����͏������̎��_�Ŏ��O�ɗv�f�����Ă���Ƃ���ł�\n");
	printf("-----------------------------------------------------------------------\n");
	PICManager::Create(0, "�A�C�J��_�n���q�R", "LE2A");

	TaskManager::Create(
		"�^�C�}�[�̃o�O",
		"�V�[���J�ڂ��Ă�Ԃ��^�C�}�[���i��ł��ăN���A�^�C���������",
		"��", 214, 0, 0);

	TaskManager::Create(
		"�{�X�̒���",
		"�{�X�̍U���̃N�[���^�C����1�b�Z������",
		"��", 213, 1, 0, "����");
	printf("-----------------------------------------------------------------------\n");

	//�X�V����
	while (true)
	{
		//�������
		if (sceneNum == Title)
		{
			printf("============================\n");
			printf("[�^�C�g�����]\n1.�^�X�N�̈ꗗ�\��\n2.�^�X�N�̒ǉ�\n3.�^�X�N�̕ҏW\n4.�S���҂̈ꗗ�\��\n5.�S���҂̒ǉ�\n6.�S���҂̕ҏW\n");
			printf("============================\n");
			printf("�����I�����Ă�������\n");
			printf("-----------------------------------------------------------------------\n");
			//�V�[���؂�ւ�
			while (true)
			{
				int num;
				scanf_s("%d", &num);
				scanf_s("%*[^\n]%*c");

				if (num >= Title + 1 && num <= MaxScene - 1)
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
		//�^�X�N�ꗗ
		else if (sceneNum == TaskShowAll)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[�^�X�N�̈ꗗ�\��]\n");

			TaskManager::ShowAll();
			printf("�^�X�N��:%d��\n\n", (int)TaskManager::tasks.size());
			printf("-----------------------------------------------------------------------\n");

			//�V�[���؂�ւ�
			printf("-----------------------------------------------------------------------\n");
			printf("0.������ʂɖ߂�\n");
			int num;
			scanf_s("%d", &num);
			scanf_s("%*[^\n]%*c");
			printf("-----------------------------------------------------------------------\n");
			while (sceneNum == TaskShowAll)
			{
				if (num == Title)
				{
					sceneNum = Title;
					break;
				}
				else
				{
					printf("0���Č����Ă񂾂�\n");
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");
				}
			}
		}
		//�^�X�N�ǉ�
		else if (sceneNum == TaskAdd)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[�^�X�N�̒ǉ�]\n");

			char title[50]{}; char content[100]{}; char priority[9]{}; int deadline{}; int id{}; int picID{};
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("�^�X�N�̃^�C�g������͂��Ă�������\n");

				scanf_s("%s", title, 50);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("�^�X�N�̓��e����͂��Ă�������\n");

				scanf_s("%s", content, 100);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("�^�X�N�̗D��x����͂��Ă�������\n");

				scanf_s("%s", priority, 9);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("�^�X�N�̊�������͂��Ă�������\n���͐擪�Ɂu0�v�������A3����4���œ��͂��Ă�������(��:1��1��->101)\n");

				scanf_s("%d", &deadline);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("�^�X�N��ID����͂��Ă�������\n");

				scanf_s("%d", &id);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("�^�X�N�̒S����ID����͂��Ă�������\n");

				scanf_s("%d", &picID);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			std::string t = title;
			std::string c = content;
			std::string p = priority;
			TaskManager::Create(t, c, p, deadline, id, picID);

			//�V�[���؂�ւ�
			printf("-----------------------------------------------------------------------\n");
			printf("0.������ʂɖ߂�\n");
			int num;
			scanf_s("%d", &num);
			scanf_s("%*[^\n]%*c");
			printf("-----------------------------------------------------------------------\n");
			while (sceneNum == TaskAdd)
			{
				if (num == Title)
				{
					sceneNum = Title;
					break;
				}
				else
				{
					printf("0���Č����Ă񂾂�\n");
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");
				}
			}
		}
		//�^�X�N�ҏW
		else if (sceneNum == TaskEdit)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[�^�X�N�̕ҏW]\n");
			printf("-----------------------------------------------------------------------\n");

			int id{};
			while (true)
			{
				printf("�ҏW�������^�X�N��ID����͂��Ă�������\n");

				scanf_s("%d", &id);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			TaskManager::Edit(id);

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
		//�S���҈ꗗ
		else if (sceneNum == PICShowAll)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[�S���҂̈ꗗ�\��]\n");

			PICManager::ShowAll();
			printf("-----------------------------------------------------------------------\n");
			printf("�o�^����Ă�S���Ґ�:%d�l\n\n", PICManager::GetSize());
			printf("-----------------------------------------------------------------------\n");

			//�V�[���؂�ւ�
			printf("-----------------------------------------------------------------------\n");
			printf("0.������ʂɖ߂�\n");
			int num;
			scanf_s("%d", &num);
			scanf_s("%*[^\n]%*c");
			printf("-----------------------------------------------------------------------\n");
			while (sceneNum == PICShowAll)
			{
				if (num == Title)
				{
					sceneNum = Title;
					break;
				}
				else
				{
					printf("0���Č����Ă񂾂�\n");
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");
				}
			}
		}
		//�S���Ғǉ�
		else if (sceneNum == PICAdd)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[�S���҂̒ǉ�]\n");
			printf("-----------------------------------------------------------------------\n");

			int id{}; char name[20]{}; char classID[9]{};

			while (true)
			{
				printf("�S���҂�ID����͂��Ă�������\n");

				scanf_s("%d", &id);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("�S���҂̖��O����͂��Ă�������\n");

				scanf_s("%s", name, 20);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			while (true)
			{
				printf("�S���҂̃N���X�L������͂��Ă�������\n");

				scanf_s("%s", classID, 9);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			string n = name;
			string c = classID;
			PICManager::Create(id, n, c);

			//�V�[���؂�ւ�
			printf("-----------------------------------------------------------------------\n");
			printf("0.������ʂɖ߂�\n");
			int num;
			scanf_s("%d", &num);
			scanf_s("%*[^\n]%*c");
			printf("-----------------------------------------------------------------------\n");
			while (sceneNum == PICAdd)
			{
				if (num == Title)
				{
					sceneNum = Title;
					break;
				}
				else
				{
					printf("0���Č����Ă񂾂�\n");
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");
				}
			}
		}
		//�S���ҕҏW
		else if (sceneNum == PICEdit)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("[�S���҂̕ҏW]\n");
			printf("-----------------------------------------------------------------------\n");

			int id{};
			while (true)
			{
				printf("�ҏW�������S���҂�ID����͂��Ă�������\n");

				scanf_s("%d", &id);
				scanf_s("%*[^\n]%*c");

				break;
			}
			printf("-----------------------------------------------------------------------\n");
			PICManager::Edit(id);

			//�V�[���؂�ւ�
			printf("-----------------------------------------------------------------------\n");
			printf("0.������ʂɖ߂�\n");
			int num;
			scanf_s("%d", &num);
			scanf_s("%*[^\n]%*c");
			printf("-----------------------------------------------------------------------\n");
			while (sceneNum == PICEdit)
			{
				if (num == Title)
				{
					sceneNum = Title;
					break;
				}
				else
				{
					printf("0���Č����Ă񂾂�\n");
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");
				}
			}
		}
	}

	return (0);
}