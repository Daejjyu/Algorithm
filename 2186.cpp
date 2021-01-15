#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int M, N, K;
string str;
char map[100][100];
int nR[4] = { 0,0,1,-1 };
int nC[4] = { 1,-1,0,0 };

int dp[100][100][80];

int dfs(int r, int c, int idx)
{
	if (dp[r][c][idx] != -1)
		return  dp[r][c][idx];
	if (idx >= str.size())
		return 1;
	dp[r][c][idx] = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int k = 1; k <= K; k++)
		{
			int nextR = r + nR[i] * K;
			int nextC = c + nC[i] * K;

			if (nextR < 0 || nextC < 0 || N <= nextR || M <= nextC)
				continue;
			if (map[nextR][nextC] == str[idx])
				ret += dfs(nextR, nextC, idx + 1);
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	cin >> str;

	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == str[0])
				ans += dfs(i, j, 1);
		}
	}

	cout << ans;
}