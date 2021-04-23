#include <iostream>
#include <cstring>

int const MAX = 101;
int XY[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int rgb[MAX][MAX];
int visited[MAX][MAX];

int n, rbCnt, rgbCnt;

void DFS(int x, int y, int color, bool isRgb)
{
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + XY[i][0];
		int nextY = y + XY[i][1];
		if (1 <= nextX && nextX <= n && 1 <= nextY && nextY <= n)
			if (isRgb) {
				if (rgb[nextX][nextY] == color && !visited[nextX][nextY])
					DFS(nextX, nextY, color, isRgb);
			} else {
				if (color <= 2) {
					if (rgb[nextX][nextY] <= 2 && !visited[nextX][nextY])
						DFS(nextX, nextY, color, isRgb);
				} else {
					if (rgb[nextX][nextY] == color && !visited[nextX][nextY])
						DFS(nextX, nextY, color, isRgb);
				}
			}
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char c;
			scanf("%c", &c);
			while (c == '\n')
				scanf("%c", &c);
			if (c == 'R') {
				rgb[j][i] = 1;
			} else if (c == 'G') {
				rgb[j][i] = 2;
			} else if (c == 'B') {
				rgb[j][i] = 3;
			}
		}
	}

	for (int k = 1; k <= 3; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (rgb[j][i] == k && !visited[j][i]) {
					rgbCnt++;
					DFS(j, i, k, true);
				}
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int k = 1; k <= 3; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (rgb[j][i] == k && !visited[j][i]) {
					rbCnt++;
					DFS(j, i, k, false);
				}
			}
		}
	}
	printf("%d %d", rgbCnt, rbCnt);
}