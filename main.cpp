#include <stdio.h>

template<typename T>
//¬‚³‚¢‚Ù‚¤‚Ì’l‚ğ•Ô‚·
T Min(T a, T b)
{
	if (a <= b)
	{
		return static_cast<T>(a);
	}
	return static_cast<T>(b);
}

template<>
char Min(char a, char b)
{
	printf("”šˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ");
	return 0;
}

int main(void)
{
	printf("%d\n", Min<int>(1, 2));
	printf("%f\n", Min<float>(1.5f, 2.5f));
	printf("%lf\n", Min<double>(1.5, 2.5));
	printf("%c\n", Min<char>('a', 'b'));

	return (0);
}