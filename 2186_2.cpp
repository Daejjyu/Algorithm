#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 100;
int N, M, K;
string goal;
char map[MAX][MAX];
int dp[MAX][MAX][80];

int dR[4] = { 0,0,1,-1 };
int dC[4] = { 1,-1,0,0 };

int dfs(int r, int c, int idx)
{
	int &ret = dp[r][c][idx];
	if (ret != -1)
		return ret;
	if (idx == goal.size() - 1)
		return 1;
	ret = 0;

	for (int k = 1; k <= K; k++)
	{
		for (int i = 0; i < 4; i++)
		{
			int nextR = r + dR[i] * k;
			int nextC = c + dC[i] * k;
			if (nextR < 0 || nextC < 0 || N <= nextR || M <= nextC)
				continue;
			if (map[nextR][nextC] == goal[idx + 1])
				ret += dfs(nextR, nextC, idx + 1);
		}
	}

	return ret;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++)
	{
		char c;
		scanf("%c", &c);
		for (int j = 0; j < M; j++)
		{
			scanf("%c", &map[i][j]);
		}
	}

	cin >> goal;

	int ans = 0;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == goal[0])
				ans += dfs(i, j, 0);
		}
	}

	printf("%d", ans);
}