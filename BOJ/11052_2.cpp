#include<iostream>
#include<algorithm>
using namespace std;

int N, arr[1001], dp[1001];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", arr + i);
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}

	printf("%d", dp[N]);
}