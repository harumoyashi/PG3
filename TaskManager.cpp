#include "TaskManager.h"
#include "PICManager.h"

std::list<std::unique_ptr<Task>> TaskManager::tasks{};

void TaskManager::Create(const string& title, const string& content, const string& priority,
	const int& deadline, const int& id, const int& maneID, const string& state)
{
	if (PICManager::GetData(maneID) == nullptr)
	{
		printf("�S����ID�u%d�v�����݂��܂���\n", maneID);
		return;
	}

	if (TaskManager::GetData(id) != nullptr)
	{
		printf("����ID�̃^�X�N�����łɂ���̂Œǉ��ł��܂���\n");
		return;
	}

	std::unique_ptr<Task> task = std::make_unique<Task>();
	task->title.Set(title);
	task->content.Set(content);
	task->SetPriority(priority);
	task->deadline.Set(deadline);
	task->id.Set(id);
	task->SetPIC(maneID);
	task->SetSteat(state);

	tasks.emplace_back(std::move(task));
	printf("�V���Ƀ^�X�N�u%s�v��ǉ����܂���\n", title.c_str());
}

void TaskManager::Delete(const int& id)
{
	for (auto itr = tasks.begin(); itr != tasks.end();)
	{
		if (itr->get()->id.Get() == id)
		{
			itr = tasks.erase(itr);
		}
		// �v�f�폜�����Ȃ��ꍇ�ɁA�C�e���[�^��i�߂�
		else {
			++itr;
		}
	}
}

void TaskManager::Edit(const int& id)
{
	if (TaskManager::GetData(id) != nullptr)
	{
		int editScene;
		while (true)
		{
			//�V�[���؂�ւ�
			while (true)
			{
				printf("============================\n");
				printf("[�ҏW���ڂ̑I��]\n0.�ҏW����߂�\n1.�^�C�g����ҏW\n2.���e��ҏW\n3.�D��x��ҏW\n4.������ҏW\n5.�^�X�NID��ҏW\n6.�S����ID��ҏW\n7.�X�e�[�^�X��ҏW\n8.�^�X�N�̍폜\n");
				printf("============================\n");
				printf("�����I�����Ă�������\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%d", &editScene);
				scanf_s("%*[^\n]%*c");

				if (editScene == 0)
				{
					printf("�ҏW���I���܂�\n");
					return;
				}
				if (editScene >= 0 && editScene <= 8)
				{
					break;
				}
				else
				{
					printf("����ȑ���˂���\n");
				}
			}

			char title[50]{}; char content[100]{}; char priority[9]{}; int deadline{}; int taskID{}; int maneID{}; char state[9]{};

			while (editScene == 1)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�^�X�N�̃^�C�g������͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%s", title, 50);
				scanf_s("%*[^\n]%*c");

				string t = title;
				TaskManager::GetData(id)->title.Set(t);
				break;
			}

			while (editScene == 2)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�^�X�N�̓��e����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%s", content, 100);
				scanf_s("%*[^\n]%*c");

				string c = content;
				TaskManager::GetData(id)->content.Set(c);
				break;
			}

			while (editScene == 3)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�^�X�N�̗D��x��I�����Ă�������\n");
				printf("-----------------------------------------------------------------------\n");

				while (true)
				{
					printf("============================\n");
					printf("1.��\n2.��\n3.��\n4.�ۗ�\n");
					printf("============================\n");

					int num;
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");

					if (num == 1)
					{
						TaskManager::GetData(id)->SetPriority("��");
						break;
					}
					else if (num == 2)
					{
						TaskManager::GetData(id)->SetPriority("��");
						break;
					}
					else if (num == 3)
					{
						TaskManager::GetData(id)->SetPriority("��");
						break;
					}
					else if (num == 4)
					{
						TaskManager::GetData(id)->SetPriority("�ۗ�");
						break;
					}
					else
					{
						printf("����ȑ���˂���\n");
					}
				}

				break;
			}

			while (editScene == 4)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�^�X�N�̊�������͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &deadline);
				scanf_s("%*[^\n]%*c");

				if (deadline / 100 >= 1 && deadline / 100 <= 12)
				{
					if (deadline % 100 >= 1 && deadline % 100 <= 31)
					{
						TaskManager::GetData(id)->deadline.Set(deadline);
						break;
					}
				}
				printf("���͂̎d���ǂ߂�\n");
			}

			while (editScene == 5)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�^�X�N��ID����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &taskID);
				scanf_s("%*[^\n]%*c");

				if (TaskManager::GetData(id) != nullptr)
				{
					printf("����ID�̃^�X�N�����łɂ���̂ŕύX�ł��܂���\n");
					break;
				}

				TaskManager::GetData(id)->id.Set(taskID);
				break;
			}

			while (editScene == 6)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�S���҂�ID����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &maneID);
				scanf_s("%*[^\n]%*c");

				if (PICManager::GetData(maneID) == nullptr)
				{
					printf("�S����ID�u%d�v�����݂��܂���\n", maneID);
					break;
				}

				TaskManager::GetData(id)->SetPIC(maneID);
				break;
			}

			while (editScene == 7)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�X�e�[�^�X����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%s", state, 9);
				scanf_s("%*[^\n]%*c");

				TaskManager::GetData(id)->SetSteat(state);
				break;
			}

			while (editScene == 8)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("ID:%d\n", TaskManager::GetData(id)->id.Get());
				printf("�S���Җ�:%s\n", PICManager::GetData(TaskManager::GetData(id)->pic.GetID())->GetName().c_str());
				printf("�薼:%s\n", TaskManager::GetData(id)->title.Get().c_str());
				printf("���e:%s\n", TaskManager::GetData(id)->content.Get().c_str());

				if (TaskManager::GetData(id)->priority.Get() == (int)Priority::PriorityType::Top)
				{
					printf("�D��x:��\n");
				}
				else if (TaskManager::GetData(id)->priority.Get() == (int)Priority::PriorityType::Middle)
				{
					printf("�D��x:��\n");
				}
				else if (TaskManager::GetData(id)->priority.Get() == (int)Priority::PriorityType::Low)
				{
					printf("�D��x:��\n");
				}
				else if (TaskManager::GetData(id)->priority.Get() == (int)Priority::PriorityType::OnHold)
				{
					printf("�D��x:�ۗ�\n");
				}

				printf("����:%d��%d��\n", TaskManager::GetData(id)->deadline.GetMonth(), TaskManager::GetData(id)->deadline.GetDay());

				if (TaskManager::GetData(id)->state.Get() == (int)State::StateType::Completion)
				{
					printf("�X�e�[�^�X:����\n\n");
				}
				else if (TaskManager::GetData(id)->state.Get() == (int)State::StateType::Incomplete)
				{
					printf("�X�e�[�^�X:������\n\n");
				}
				printf("-----------------------------------------------------------------------\n");

				while (true)
				{
					printf("��L�̃^�X�N���폜���܂�����낵���ł����H\n");
					printf("0.�͂�\n1.������\n");
					int num;
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");

					if (num == 0)
					{
						Delete(id);
						printf("�폜���܂���\n");
						return;
					}
					else if (num == 1)
					{
						printf("�폜���������܂���\n");
						break;
					}
					else
					{
						printf("0��1�őI�������\n");
					}
				}
				break;
			}
		}
	}
	printf("�����ID�̃^�X�N�Ȃ���\n");
	return;
}

void TaskManager::ShowAll()
{
	for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
	{
		printf("-----------------------------------------------------------------------\n");
		printf("ID:%d\n", itr->get()->id.Get());
		printf("�S���Җ�:%s\n", PICManager::GetData(itr->get()->pic.GetID())->GetName().c_str());
		printf("�薼:%s\n", itr->get()->title.Get().c_str());
		printf("���e:%s\n", itr->get()->content.Get().c_str());

		if (itr->get()->priority.Get() == (int)Priority::PriorityType::Top)
		{
			printf("�D��x:��\n");
		}
		else if (itr->get()->priority.Get() == (int)Priority::PriorityType::Middle)
		{
			printf("�D��x:��\n");
		}
		else if (itr->get()->priority.Get() == (int)Priority::PriorityType::Low)
		{
			printf("�D��x:��\n");
		}
		else if (itr->get()->priority.Get() == (int)Priority::PriorityType::OnHold)
		{
			printf("�D��x:�ۗ�\n");
		}

		printf("����:%d��%d��\n", itr->get()->deadline.GetMonth(), itr->get()->deadline.GetDay());

		if (itr->get()->state.Get() == (int)State::StateType::Completion)
		{
			printf("�X�e�[�^�X:����\n\n");
		}
		else if (itr->get()->state.Get() == (int)State::StateType::Incomplete)
		{
			printf("�X�e�[�^�X:������\n\n");
		}
	}
}

Task* TaskManager::GetData(const int& id)
{
	for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
	{
		if (itr->get()->id.Get() == id)
		{
			return itr->get();
		}
	}

	return nullptr;
}
