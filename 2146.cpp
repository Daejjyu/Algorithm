#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int const MAX = 101;

int arr[MAX][MAX];
int XY[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int visited[MAX][MAX];

int n = 0, minDist = 1e6;

int islandNum = 2;

void DFS(int x, int y)
{
	arr[x][y] = islandNum;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + XY[i][0];
		int nextY = y + XY[i][1];
		if (1 <= nextX && nextX <= n && 1 <= nextY && nextY <= n)
			if (arr[nextX][nextY] == 1)
				DFS(nextX, nextY);
	}
}

void BFS(int island)
{
	int dist = 0;
	queue<pair<int, int>> q;
	while (!q.empty())
	{
		int currentSize = q.size();
		while (currentSize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nextX = x + XY[i][0];
				int nextY = y + XY[i][1];
				if (1 <= nextX && nextX <= n && 1 <= nextY && nextY <= n)
					if (!visited[nextX][nextY]) {
						if (arr[nextX][nextY] == 0) {
							visited[nextX][nextY] = 1;
							q.push(make_pair(nextX, nextY));
						} else if (arr[nextX][nextY] != island)
						{
							if (dist < minDist)
								minDist = dist;
							return;
						}
					}
			}
		}
		dist++;
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
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[j][i] == 1) {
				DFS(j, i);
				islandNum++;
			}
		}
	}

	for (int i = 2; i < islandNum; i++)
	{
		memset(visited, 0, sizeof(visited));
		for (int k = 1; k <= n; k++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[j][k] == i) {
					q.push(make_pair(j, k));
				}
			}
		}
		BFS(i);
	}

	printf("%d\n", minDist);
}