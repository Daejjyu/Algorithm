#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N, arr[1000], dp[1000], ans;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		dp[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		ans = max(dp[i], ans);
	}

	printf("%d", ans);
}