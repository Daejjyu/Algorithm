#include <iostream>
#include <cstring>

int const MAX = 101;

int arr[MAX][MAX];
int visited[MAX][MAX];
int XY[4][2] = { {1,0} ,{-1,0} ,{0,1} ,{0,-1} };

int n, cnt, max;

void DFS(int height, int x, int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + XY[i][0];
		int nextY = y + XY[i][1];
		if (1 <= nextX && nextX <= n && 1 <= nextY && nextY <= n)
			if (arr[nextX][nextY] > height && !visited[nextX][nextY])
				DFS(height, nextX, nextY);
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[j][i]);
		}
	}

	for (int k = 0; k <= MAX; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[j][i] > k && !visited[j][i]) {
					cnt++;
					DFS(k, j, i);
				}
			}
		}

		if (max < cnt) {
			max = cnt;
		}
		cnt = 0;
		memset(visited, 0, sizeof(visited));
	}
	if (ans == 0)
		printf("1");
	else
		printf("%d", max);
}