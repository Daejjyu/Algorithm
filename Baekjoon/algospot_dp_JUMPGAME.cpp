#include<cstdio>
#include<cstring>
using namespace std;

int arr[100][100];
int dp[100][100];
int N;

bool go(int r, int c)
{
	if (r == N - 1 && c == N - 1)
		return true;
	if (r >= N || c >= N)
		return false;

	int &ret = dp[r][c];
	if (ret != -1)
		return ret;

	return ret = go(r + arr[r][c], c) || go(r, c + arr[r][c]);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		if (go(0, 0))
			printf("YES\n");
		else
			printf("NO\n");
	}
}