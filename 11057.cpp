#include <iostream>

int dp[1001][10];
const int mod = 10007;

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mod;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += dp[N][i];
		ans %= mod;
	}

	printf("%d", ans);
}