#include<iostream>
#include<algorithm>
using namespace std;

int N, dp[100001];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i <= N; i++)
	{
		dp[i] = i;
	}
	for (int i = 1; i*i <= N; i++)
	{
		dp[i*i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j*j < i; j++)
		{
			dp[i] = min(dp[i], dp[j*j] + dp[i - j * j]);
		}
	}
	printf("%d", dp[N]);
}