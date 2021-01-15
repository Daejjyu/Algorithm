#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int map[100][100];
int visited[100][100];
int N;
int maxN, ans = 1;
int minN = 1e8;

int nR[4] = { 0,0,1,-1 };
int nC[4] = { 1,-1,0,0 };

void dfs(int height, int r, int c)
{
	visited[r][c] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + nR[i];
		int nextC = c + nC[i];
		if (nextR < 0 || nextC < 0 || N <= nextR || N <= nextC)
			continue;
		if (!visited[nextR][nextC] && map[nextR][nextC] > height)
			dfs(height, nextR, nextC);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			minN = min(minN, map[i][j]);
			maxN = max(maxN, map[i][j]);
		}
	}

	int cnt = 0;
	for (int k = minN; k < maxN; k++)
	{
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && map[i][j] > k) {
					dfs(k, i, j);
					cnt++;
				}
			}
		}
		if (cnt > ans)
			ans = cnt;
	}
	printf("%d", ans);
}