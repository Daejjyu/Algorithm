#include <iostream>
#include <algorithm>
using namespace std;

int arr[300];
int dp[300];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[1] + arr[2], arr[0] + arr[2]);

	for (int i = 3; i < N; i++)
	{
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
	}

	printf("%d", dp[(N - 1)]);
}