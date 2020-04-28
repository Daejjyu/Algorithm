#include <iostream>

const int MAX = 51;

int map[MAX][MAX];
int visited[MAX][MAX];

int w, h;

int XY[8][2] = { {1,0} ,{1,1} ,{1,-1} ,{0,1} ,{0,-1} ,{-1,0} ,{-1,1} ,{-1,-1} };

void DFS(int x, int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 8; i++)
	{
		int nextX = x + XY[i][0];
		int nextY = y + XY[i][1];
		if (1 <= nextX && nextX <= w && 1 <= nextY && nextY <= h) {
			if (map[nextX][nextY] != 0 && !visited[nextX][nextY])
				DFS(nextX, nextY);
		}
	}
}

int main(void)
{
	while (1) {
		int count = 0;
		scanf("%d %d", &w, &h);
		if (!w && !h)
			break;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				int d;
				scanf("%1d", &d);
				map[j][i] = d;
			}
		}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (map[j][i] != 0 && visited[j][i] == 0) {
					DFS(j, i);
					count++;
				}
			}
		}
		printf("%d\n", count);
		memset(visited, 0, sizeof(visited));
	}
}