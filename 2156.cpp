#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];
int dp[10000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[1], arr[0] + arr[2]);
	dp[2] = max(dp[2], arr[1] + arr[2]);

	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	printf("%d", dp[n - 1]);
}