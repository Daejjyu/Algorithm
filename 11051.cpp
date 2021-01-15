#include <iostream>

int dp[1000][1000];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	dp[0][0] = 1;
	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
		dp[i][1] = i;
		dp[i][i - 1] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	printf("%d", dp[N][K]);
}