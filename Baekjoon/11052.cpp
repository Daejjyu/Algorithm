#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10001];
int dp[10001];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", arr + i);
		dp[i] = arr[i];
	}

	for (size_t i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}
	printf("%d", dp[N]);
}