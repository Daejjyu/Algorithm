#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001] = { -1,0,1 };

int main()
{
	int d;
	scanf("%d", &d);

	for (int i = 3; i <= d; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
	}

	printf("%d", dp[d]);
}