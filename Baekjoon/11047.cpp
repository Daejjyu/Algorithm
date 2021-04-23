#include <iostream>

int arr[10];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	int ans = 0;
	while (K) {
		for (int i = N - 1; i >= 0; i--)
		{
			if (K / arr[i]) {
				ans += K / arr[i];
				K %= arr[i];
			}
		}
	}
	printf("%d", ans);
}