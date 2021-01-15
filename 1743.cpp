#include <iostream>

int const MAX = 101;

int map[MAX][MAX];
bool visited[MAX][MAX];
int XY[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

int n, m, k;

int max, cnt;

void DFS(int x, int y)
{
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + XY[i][0];
		int nextY = y + XY[i][1];
		if (1 <= nextX && nextX <= m && 1 <= nextY && nextY <= n)
			if (!visited[nextX][nextY] && map[nextX][nextY]) {
				cnt++;
				DFS(nextX, nextY);
			}
	}
}

int main(void)
{
	scanf("%d %d %d", &n, &m, &k);
	while (k--) {
		int i, j;
		scanf("%d %d", &i, &j);
		map[j][i] = 1;
	}
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= m; i++)
		{
			if (!visited[i][j] && map[i][j]) {
				cnt = 1;
				DFS(i, j);
				if (max < cnt) {
					max = cnt;
				}
			}
		}
	}
	printf("%d", max);
}