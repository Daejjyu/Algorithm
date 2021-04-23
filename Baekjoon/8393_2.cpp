#include <iostream>

int main()
{
	int N;
	scanf("%d", &N);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += i + 1;
	}
	printf("%d", ans);
}