#include <iostream>

int dp[1000001];
const int mod = 15746;

int main()
{
	int N;
	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
		dp[i] %= mod;
	}

	printf("%d", dp[N]);
}