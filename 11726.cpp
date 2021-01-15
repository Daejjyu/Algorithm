#include <iostream>
int dp[1001] = { -1,1,2 };

int main()
{
	int d;
	scanf("%d", &d);

	for (int i = 3; i <= d; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	printf("%d", dp[d]);
}