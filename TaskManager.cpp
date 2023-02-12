#include "TaskManager.h"

std::list<std::unique_ptr<Task>> TaskManager::tasks{};

void TaskManager::Create(const string& title, const string& content, const string& priority,
	const int& deadline, const int& id, const int& maneID, const string& state)
{
	if (ManagerMane::GetData(maneID) == nullptr)
	{
		printf("ID�u%d�v�̒S���҂����݂��܂���\n", id);
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
	task->SetManager(maneID);
	task->SetSteat(state);

	tasks.emplace_back(std::move(task));
	printf("�V���Ƀ^�X�N��ǉ����܂���\n");
}

void TaskManager::Delete(const int& elementNum)
{
	for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
	{
		tasks.erase(itr);
	}
}

void TaskManager::Edit(const int& id)
{
	if (TaskManager::GetData(id) != nullptr)
	{
		for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
		{
			char title[50]{}; char content[100]{}; char priority[9]{}; int deadline{}; int id{}; int maneID{}; char state[9]{};

			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�^�X�N�̃^�C�g������͂��Ă�������\n");
				printf("�ύX���Ȃ��ꍇ�́u0�v����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%s", title, 50);
				scanf_s("%*[^\n]%*c");

				if (title != 0)
				{
					string t = title;
					itr->get()->title.Set(t);
				}
				break;
			}

			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�^�X�N�̓��e����͂��Ă�������\n");
				printf("�ύX���Ȃ��ꍇ�́u0�v����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%s", content, 100);
				scanf_s("%*[^\n]%*c");

				if (content != 0)
				{
					string c = content;
					itr->get()->content.Set(c);
				}
				break;
			}

			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�^�X�N�̗D��x����͂��Ă�������\n");
				printf("�ύX���Ȃ��ꍇ�́u0�v����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%s", priority, 9);
				scanf_s("%*[^\n]%*c");

				if (priority != 0)
				{
					string p = priority;
					itr->get()->SetPriority(p);
				}
				break;
			}

			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�^�X�N�̊�������͂��Ă�������\n");
				printf("�ύX���Ȃ��ꍇ�́u0�v����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &deadline);
				scanf_s("%*[^\n]%*c");

				if (deadline != 0)
				{
					itr->get()->deadline.Set(deadline);
				}
				break;
			}

			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�^�X�N��ID����͂��Ă�������\n");
				printf("�ύX���Ȃ��ꍇ�́u0�v����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &id);
				scanf_s("%*[^\n]%*c");

				if (id != 0)
				{
					itr->get()->id.Set(id);
				}
				break;
			}

			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�S���҂�ID����͂��Ă�������\n");
				printf("�ύX���Ȃ��ꍇ�́u0�v����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &maneID);
				scanf_s("%*[^\n]%*c");

				if (maneID != 0)
				{
					itr->get()->SetManager(maneID);
				}
				break;
			}

			while (true)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("�X�e�[�^�X����͂��Ă�������\n");
				printf("�ύX���Ȃ��ꍇ�́u0�v����͂��Ă�������\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%s", state, 9);
				scanf_s("%*[^\n]%*c");

				itr->get()->SetSteat(state);
				break;
			}

			return;
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
		printf("�S���Җ�:%s\n", ManagerMane::GetData(itr->get()->manager.GetID())->GetName().c_str());
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
