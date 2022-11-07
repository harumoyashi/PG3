#include <stdio.h>
#include <Windows.h>
#include <vector>
#include <list>

int main()
{
	std::list<const char*>list
	{
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		//"Nishi-Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"Shin-Okubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		//"Takanawa-Gateway",
		"Tamachi",
		"Hamamatsucho",
		"Shimbashi",
		"Yurakucho",
	};

	printf("1970年\n");
	for (std::list<const char*>::iterator i = list.begin(); i != list.end(); ++i)
	{
		printf("%s\n", *i);
	}

	printf("\n2019年\n");
	for (std::list<const char*>::iterator i = list.begin(); i != list.end(); ++i)
	{
		//田畑まで来たら
		if (*i == "Tabata")
		{
			i = list.insert(i, "Nishi-Nippori");	//西日暮里を挿入して
			printf("%s\n", *i);	//表示までしたら
			++i;				//イテレータを次に進める(田畑を表示)
		}
		printf("%s\n", *i);
	}

	printf("\n2022年\n");
	for (std::list<const char*>::iterator i = list.begin(); i != list.end(); ++i)
	{
		//田町まで来たら
		if (*i == "Tamachi")
		{
			i = list.insert(i, "Takanawa-Gateway");	//高輪ゲートウェイを挿入して
			printf("%s\n", *i);	//表示までしたら
			++i;				//イテレータを次に進める(田町を表示)
		}
		printf("%s\n", *i);
	}

	return (0);
}

