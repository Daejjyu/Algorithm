#include <iostream>

int dp[12] = { -1,1,2,4 };

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 4; i <= 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (T--)
	{
		int N;
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
}