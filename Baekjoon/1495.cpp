#include <iostream>

int dp[101][1001];
int arr[101];

int main()
{
	int N, S, M;
	scanf("%d %d %d", &N, &S, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", arr + i);
	}

	dp[0][S] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (dp[i - 1][j] == 1) {
				if (0 <= j + arr[i] && j + arr[i] <= M)
					dp[i][j + arr[i]] = 1;
				if (0 <= j - arr[i] && j - arr[i] <= M)
					dp[i][j - arr[i]] = 1;
			}
		}
	}
	int max = -1;
	for (int i = M; i >= 0; i--)
	{
		if (dp[N][i] == 1) {
			max = i;
			break;
		}
	}
	printf("%d", max);
}