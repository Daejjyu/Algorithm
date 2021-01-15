#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int const MAX = 101;

int map[MAX][MAX];
bool visited[MAX][MAX];
int XY[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int m, n, k, lap;
int sizeNArr[MAX*MAX / 3];

void DFS(int x, int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + XY[i][0];
		int nextY = y + XY[i][1];
		if (1 <= nextX && nextX <= n && 1 <= nextY && nextY <= m)
			if (!map[nextX][nextY] && !visited[nextX][nextY]) {
				DFS(nextX, nextY);
				sizeNArr[lap]++;
			}
	}
}

int main(void)
{
	scanf("%d %d %d", &m, &n, &k);
	// n->x m->y
	while (k--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = y1 + 1; i <= y2; i++)
		{
			for (int j = x1 + 1; j <= x2; j++)
			{
				map[j][i] = 1;
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!map[j][i] && !visited[j][i]) {
				DFS(j, i);
				lap++;
			}
		}
	}

	sort(sizeNArr, sizeNArr + lap);
	printf("%d\n", lap);
	for (int i = 0; i < lap; i++)
	{
		printf("%d ", sizeNArr[i] + 1);
	}
}