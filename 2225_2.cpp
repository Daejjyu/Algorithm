#include<iostream>

int N, K;
long long dp[201][201];
const int mod = 1e9;
int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++)
	{
		dp[1][i] = 1;
	}

	for (int j = 2; j <= K; j++)
	{
		for (int i = 0; i <= N; i++)
		{
			for (int k = 0; k <= i; k++)
			{
				dp[j][i] += dp[j - 1][i - k];
				dp[j][i] %= mod;
			}
		}
	}

	printf("%lld", dp[K][N] % mod);
}