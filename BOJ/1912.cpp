#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int dp[100000];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		dp[i] = arr[i];
	}

	int ans = -1001;
	for (int i = 0; i < N; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], dp[i]);
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
}