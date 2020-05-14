#include <iostream>

const int mod = 10007;
int dp[1001] = { -1,1,3 };

int main()
{
	int d;
	scanf("%d", &d);

	for (int i = 3; i <= d; i++)
	{
		dp[i] = (dp[i - 1] + 2 * dp[i - 2])%mod;
	}
	printf("%d", dp[d]);
}