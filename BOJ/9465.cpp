#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000][2];
int dp[100000][2];

int main()
{
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i][0]);
		}
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i][1]);
		}

		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[1][0] = arr[0][1] + arr[1][0];
		dp[1][1] = arr[0][0] + arr[1][1];

		for (int i = 0; i < N; i++)
		{
			dp[i][0] = max(dp[i - 1][1] + arr[i][0], dp[i - 2][1] + arr[i][0]);

			dp[i][1] = max(dp[i - 1][0] + arr[i][1], dp[i - 2][0] + arr[i][1]);
		}
		int ans = 0;
		ans = max(dp[N - 1][0], dp[N - 1][1]);
		printf("%d\n", ans);
	}
}