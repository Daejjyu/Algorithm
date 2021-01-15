#include <iostream>
#include <vector>
using namespace std;

int map[1000][1000];
int visited[1000][1000];

int dR[4] = { 1,-1,0,0 };
int dC[4] = { 0,0,1,-1 };
int N, M;
int cnt;

void dfs(int r, int c, int idx)
{
	visited[r][c] = idx;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + dR[i];
		int nextC = c + dC[i];
		if (nextR < 0 || nextC < 0 || N <= nextR || M <= nextC)
			continue;
		if (map[nextR][nextC] == 0 && !visited[nextR][nextC])
			dfs(nextR, nextC, idx);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	vector<int> num;
	int idx = 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0 && !visited[i][j]) {
				dfs(i, j, idx);
				idx++;
				num.push_back(cnt);
				cnt = 0;
			}
		}
	}

	vector<int> numArr;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			numArr.clear();
			if (map[i][j] == 1) {
				for (int k = 0; k < 4; k++)
				{
					int nextR = i + dR[k];
					int nextC = j + dC[k];
					if (nextR < 0 || nextC < 0 || N <= nextR || M <= nextC)
						continue;
					if (map[nextR][nextC] >= 1)
						continue;
					bool possible = true;
					for (int p = 0; p < numArr.size(); p++)
					{
						if (numArr[p] == visited[nextR][nextC]) {
							possible = false;
							break;
						}
					}
					if (possible)
					{
						numArr.push_back(visited[nextR][nextC]);
						map[i][j] += num[visited[nextR][nextC] - 2];
					}
				}
			}
			printf("%d", map[i][j] % 10);
		}
		printf("\n");
	}
}