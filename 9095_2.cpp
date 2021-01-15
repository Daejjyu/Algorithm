#include<iostream>

int T, N, dp[12] = { 0,1,2,4 };
int main()
{
	scanf("%d", &T);
	for (int i = 4; i <= 11; i++)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	while (T--)
	{
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
}