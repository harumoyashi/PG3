#include "TaskManager.h"

std::list<std::unique_ptr<Task>> TaskManager::tasks{};

void TaskManager::Create(const string& title, const string& content, const string& priority,
	const int& deadline, const int& id, const int& maneID, const string& state)
{
	if (ManagerMane::GetData(maneID) == nullptr)
	{
		printf("ID「%d」の担当者が存在しません\n", id);
		return;
	}

	if (TaskManager::GetData(id) != nullptr)
	{
		printf("同じIDのタスクがすでにあるので追加できません\n");
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
	printf("新たにタスクを追加しました\n");
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
				printf("タスクのタイトルを入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
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
				printf("タスクの内容を入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
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
				printf("タスクの優先度を入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
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
				printf("タスクの期限を入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
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
				printf("タスクのIDを入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
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
				printf("担当者のIDを入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
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
				printf("ステータスを入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%s", state, 9);
				scanf_s("%*[^\n]%*c");

				itr->get()->SetSteat(state);
				break;
			}

			return;
		}
	}
	printf("そんなIDのタスクないよ\n");
	return;
}

void TaskManager::ShowAll()
{
	for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
	{
		printf("-----------------------------------------------------------------------\n");
		printf("ID:%d\n", itr->get()->id.Get());
		printf("担当者名:%s\n", ManagerMane::GetData(itr->get()->manager.GetID())->GetName().c_str());
		printf("題名:%s\n", itr->get()->title.Get().c_str());
		printf("内容:%s\n", itr->get()->content.Get().c_str());

		if (itr->get()->priority.Get() == (int)Priority::PriorityType::Top)
		{
			printf("優先度:高\n");
		}
		else if (itr->get()->priority.Get() == (int)Priority::PriorityType::Middle)
		{
			printf("優先度:中\n");
		}
		else if (itr->get()->priority.Get() == (int)Priority::PriorityType::Low)
		{
			printf("優先度:低\n");
		}
		else if (itr->get()->priority.Get() == (int)Priority::PriorityType::OnHold)
		{
			printf("優先度:保留\n");
		}

		printf("期日:%d月%d日\n", itr->get()->deadline.GetMonth(), itr->get()->deadline.GetDay());

		if (itr->get()->state.Get() == (int)State::StateType::Completion)
		{
			printf("ステータス:完了\n\n");
		}
		else if (itr->get()->state.Get() == (int)State::StateType::Incomplete)
		{
			printf("ステータス:未完了\n\n");
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
