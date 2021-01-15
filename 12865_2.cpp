#include<iostream>

int N, K, W[100], V[100], dp[100001];
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", W + i, V + i);
		for (int j = K - W[i]; j >= 0; j--)
		{
			if (dp[j + W[i]] < dp[j] + V[i])
				dp[j + W[i]] = dp[j] + V[i];
		}
	}

	printf("%d", dp[K]);
}