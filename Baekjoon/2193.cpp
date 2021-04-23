#include <iostream>

long long dp[91][2];

int main()
{
	dp[1][0] = 0;//0
	dp[1][1] = 1;//1
	dp[2][0] = 1;//10
	dp[2][1] = 0;//01
	dp[3][0] = 1;//100 > 1000,1001 > 10000,10001,10010
	dp[3][1] = 1;//101 > 1010 > 10101,10100

	int N;
	scanf("%d", &N);

	for (int i = 4; i <= N; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	printf("%lld", dp[N][0] + dp[N][1]);
}