#include <iostream>

int dp[31];

int main()
{
	int N;
	scanf("%d", &N);

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= N; i += 2)
	{
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j += 2)
		{
			dp[i] += 2 * dp[i - j];
		}
	}

	printf("%d", dp[N]);
}