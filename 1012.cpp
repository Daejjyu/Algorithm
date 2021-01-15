#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 50;

int map[MAX][MAX];
bool visited[MAX][MAX];
int XY[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int t, m, n, k, cnt;

void DFS(int x, int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + XY[i][0];
		int nextY = y + XY[i][1];
		if (0 <= nextX && nextX <= m - 1 && 0 <= nextY && nextY <= n - 1)
			if (!visited[nextX][nextY] && map[nextX][nextY] == 1)
				DFS(nextX, nextY);
	}
}

int main(void)
{
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		//memset(map, 0, sizeof(map));

		scanf("%d %d %d", &m, &n, &k);
		while (k--) {
			int i, j;
			scanf("%d %d", &i, &j);
			map[i][j] = 1;
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				if (!visited[i][j] && map[i][j] == 1) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
}