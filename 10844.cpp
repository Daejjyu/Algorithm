#include <cstdio>

const int mod = 1000000000;

int dp[101][10];

int main()
{
	int d;
	scanf("%d", &d);

	dp[1][0] = 0;

	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= d; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][0] = dp[i - 1][1];
			else if (j == 9)
				dp[i][9] = dp[i - 1][8];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += dp[d][i];
	}

	printf("%d", ans);
}