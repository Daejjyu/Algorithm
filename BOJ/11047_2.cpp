#include<iostream>

int N, K, arr[10];
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (K >= arr[N - 1 - i]) {
			ans += K / arr[N - 1 - i];
			K %= arr[N - 1 - i];
		}

		if (K == 0)
			break;
	}
	printf("%d", ans);
}