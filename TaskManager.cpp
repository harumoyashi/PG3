#include "TaskManager.h"
#include "PICManager.h"

std::list<std::unique_ptr<Task>> TaskManager::tasks{};

void TaskManager::Create(const string& title, const string& content, const string& priority,
	const int& deadline, const int& id, const int& maneID, const string& state)
{
	if (PICManager::GetData(maneID) == nullptr)
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
	task->SetPIC(maneID);
	task->SetSteat(state);

	tasks.emplace_back(std::move(task));
	printf("新たにタスク「%s」を追加しました\n", title.c_str());
}

void TaskManager::Delete(const int& id)
{
	for (auto itr = tasks.begin(); itr != tasks.end();)
	{
		if (itr->get()->id.Get() == id)
		{
			itr = tasks.erase(itr);
		}
		// 要素削除をしない場合に、イテレータを進める
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
			//シーン切り替え
			while (true)
			{
				printf("============================\n");
				printf("[編集項目の選択]\n0.編集をやめる\n1.タイトルを編集\n2.内容を編集\n3.優先度を編集\n4.期限を編集\n5.タスクIDを編集\n6.担当者IDを編集\n7.ステータスを編集\n8.タスクの削除\n");
				printf("============================\n");
				printf("操作を選択してください\n");
				printf("-----------------------------------------------------------------------\n");

				scanf_s("%d", &editScene);
				scanf_s("%*[^\n]%*c");

				if (editScene == 0)
				{
					printf("編集を終わります\n");
					return;
				}
				if (editScene >= 0 && editScene <= 8)
				{
					break;
				}
				else
				{
					printf("そんな操作ねえよ\n");
				}
			}

			char title[50]{}; char content[100]{}; char priority[9]{}; int deadline{}; int taskID{}; int maneID{}; char state[9]{};

			while (editScene == 1)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("タスクのタイトルを入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%s", title, 50);
				scanf_s("%*[^\n]%*c");

				if (title != "0")
				{
					string t = title;
					TaskManager::GetData(id)->title.Set(t);
				}
				break;
			}

			while (editScene == 2)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("タスクの内容を入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%s", content, 100);
				scanf_s("%*[^\n]%*c");

				if (content[0] != '0')
				{
					string c = content;
					TaskManager::GetData(id)->content.Set(c);
				}
				break;
			}

			while (editScene == 3)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("タスクの優先度を選択してください\n");
				printf("-----------------------------------------------------------------------\n");

				while (true)
				{
					printf("============================\n");
					printf("1.高\n2.中\n3.低\n4.保留\n");
					printf("============================\n");

					int num;
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");

					if (num == 1)
					{
						TaskManager::GetData(id)->SetPriority("高");
						break;
					}
					else if (num == 2)
					{
						TaskManager::GetData(id)->SetPriority("中");
						break;
					}
					else if (num == 3)
					{
						TaskManager::GetData(id)->SetPriority("低");
						break;
					}
					else if (num == 4)
					{
						TaskManager::GetData(id)->SetPriority("保留");
						break;
					}
					else
					{
						printf("そんな操作ねえよ\n");
					}
				}

				break;
			}

			while (editScene == 4)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("タスクの期限を入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &deadline);
				scanf_s("%*[^\n]%*c");

				if (deadline != 0)
				{
					TaskManager::GetData(id)->deadline.Set(deadline);
				}
				break;
			}

			while (editScene == 5)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("タスクのIDを入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &taskID);
				scanf_s("%*[^\n]%*c");

				if (taskID != 0)
				{
					TaskManager::GetData(id)->id.Set(taskID);
				}
				break;
			}

			while (editScene == 6)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("担当者のIDを入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
				printf("-----------------------------------------------------------------------\n");
				scanf_s("%d", &maneID);
				scanf_s("%*[^\n]%*c");

				if (maneID != 0)
				{
					TaskManager::GetData(id)->SetPIC(maneID);
				}
				break;
			}

			while (editScene == 7)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("ステータスを入力してください\n");
				printf("変更しない場合は「0」を入力してください\n");
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
				printf("担当者名:%s\n", PICManager::GetData(TaskManager::GetData(id)->pic.GetID())->GetName().c_str());
				printf("題名:%s\n", TaskManager::GetData(id)->title.Get().c_str());
				printf("内容:%s\n", TaskManager::GetData(id)->content.Get().c_str());

				if (TaskManager::GetData(id)->priority.Get() == (int)Priority::PriorityType::Top)
				{
					printf("優先度:高\n");
				}
				else if (TaskManager::GetData(id)->priority.Get() == (int)Priority::PriorityType::Middle)
				{
					printf("優先度:中\n");
				}
				else if (TaskManager::GetData(id)->priority.Get() == (int)Priority::PriorityType::Low)
				{
					printf("優先度:低\n");
				}
				else if (TaskManager::GetData(id)->priority.Get() == (int)Priority::PriorityType::OnHold)
				{
					printf("優先度:保留\n");
				}

				printf("期日:%d月%d日\n", TaskManager::GetData(id)->deadline.GetMonth(), TaskManager::GetData(id)->deadline.GetDay());

				if (TaskManager::GetData(id)->state.Get() == (int)State::StateType::Completion)
				{
					printf("ステータス:完了\n\n");
				}
				else if (TaskManager::GetData(id)->state.Get() == (int)State::StateType::Incomplete)
				{
					printf("ステータス:未完了\n\n");
				}
				printf("-----------------------------------------------------------------------\n");

				while (true)
				{
					printf("上記のタスクを削除しますがよろしいですか？\n");
					printf("0.はい\n1.いいえ\n");
					int num;
					scanf_s("%d", &num);
					scanf_s("%*[^\n]%*c");

					if (num == 0)
					{
						Delete(id);
						printf("削除しました\n");
						return;
					}
					else if (num == 1)
					{
						printf("削除を取り消しました\n");
						break;
					}
					else
					{
						printf("0か1で選択しろや\n");
					}
				}
				break;
			}
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
		printf("担当者名:%s\n", PICManager::GetData(itr->get()->pic.GetID())->GetName().c_str());
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
