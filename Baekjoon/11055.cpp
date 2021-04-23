#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];
int dp[1000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		dp[i] = arr[i];
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[j] + arr[i], dp[i]);
		}
		ans = max(dp[i], ans);
	}
	printf("%d", ans);
}