#include<iostream>

const int mod = 15746;
int N, dp[1000001] = { 0,1,2 };
int main()
{
	scanf("%d", &N);

	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
		dp[i] %= mod;
	}

	printf("%d", dp[N]);
}