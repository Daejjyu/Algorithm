#include<iostream>
#include<algorithm>
using namespace std;

int N, K, arr[100], dp[10001];
int main()
{
	for (int i = 0; i < 10001; i++)
	{
		dp[i] = 1e9;
	}

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		for (int j = 1; arr[i] * j < 10001; j++)
		{
			dp[arr[i] * j] = min(j, dp[arr[i] * j]);
		}
	}

	for (int k = 1; k <= K; k++)
	{
		for (int i = 1; i < k; i++)
		{
			dp[k] = min(dp[k], dp[k - i] + dp[i]);
		}
	}

	printf("%d", dp[K] == 1e9 ? -1 : dp[K]);
}