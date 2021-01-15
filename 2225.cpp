#include <iostream>

int dp[201][201];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= N; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 1000000000;
			}
		}
	}
	printf("%d", dp[K][N]);
}