#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];
int dp[10001];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++)
	{
		int d;
		scanf("%d", arr + i);
		if (arr[i] <= K)
			dp[arr[i]] = 1;
	}

	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[j] <= i && dp[i - arr[j]] != -1) {
				if (dp[i] == -1)
					dp[i] = dp[i - arr[j]] + 1;
				else
					dp[i] = min(dp[i - arr[j]] + 1, dp[i]);
			}
		}
	}
	printf("%d", dp[K]);
}