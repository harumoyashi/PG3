#include <stdio.h>

template<typename T>
//小さいほうの値を返す
T Min(T a, T b)
{
	if (a <= b)return static_cast<T>(a);
	return static_cast<T>(b);
}

template<>
char Min(char a, char b)
{
	return printf("数字以外は代入できません");
}

int main(void)
{
	printf("%d\n", Min<int>(1, 2));
	printf("%f\n", Min<float>(1.5f, 2.5f));
	printf("%lf\n", Min<double>(1.5l, 2.5l));
	printf("%c\n", Min<char>(1, 2));
}