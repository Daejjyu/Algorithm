#include <iostream>

long long dp[101] = { -1, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

int main()
{
	for (int i = 11; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		printf("%lld\n", dp[N]);
	}
}