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

	printf("1970�N\n");
	for (std::list<const char*>::iterator i = list.begin(); i != list.end(); ++i)
	{
		printf("%s\n", *i);
	}

	printf("\n2019�N\n");
	for (std::list<const char*>::iterator i = list.begin(); i != list.end(); ++i)
	{
		//�c���܂ŗ�����
		if (*i == "Tabata")
		{
			i = list.insert(i, "Nishi-Nippori");	//�����闢��}������
			printf("%s\n", *i);	//�\���܂ł�����
			++i;				//�C�e���[�^�����ɐi�߂�(�c����\��)
		}
		printf("%s\n", *i);
	}

	printf("\n2022�N\n");
	for (std::list<const char*>::iterator i = list.begin(); i != list.end(); ++i)
	{
		//�c���܂ŗ�����
		if (*i == "Tamachi")
		{
			i = list.insert(i, "Takanawa-Gateway");	//���փQ�[�g�E�F�C��}������
			printf("%s\n", *i);	//�\���܂ł�����
			++i;				//�C�e���[�^�����ɐi�߂�(�c����\��)
		}
		printf("%s\n", *i);
	}

	return (0);
}

