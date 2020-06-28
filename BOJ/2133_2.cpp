#include <iostream>

int N;
long long dp[31] = { 1,0,3 };
int main()
{
	scanf("%d", &N);
	for (int i = 4; i <= N; i += 2)
	{
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j++)
		{
			dp[i] += 2 * dp[i - j];
		}
	}
	printf("%lld", dp[N]);
}