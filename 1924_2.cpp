#include <iostream>

char day[7][4] = { "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	int X, Y;
	scanf("%d %d", &X, &Y);
	int ans = 0;
	for (int i = 1; i < X; i++)
	{
		ans += month[i];
	}
	ans += Y;
	ans %= 7;
	printf("%s", day[ans]);
}