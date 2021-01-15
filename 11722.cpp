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
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
}