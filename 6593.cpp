#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int const MAX = 31;

int map[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int XY[6][3] = { {0,1,0},{-1,0,0},{1,0,0}, {0, -1,0}, {0,0,1},{0,0,-1} };

int l, r, c, minute;
int startX, startY, startZ;
int endX, endY, endZ;

void BFS(int x, int y, int z)
{
	visited[x][y][z] = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(x, y), z));

	while (!q.empty()) {
		int currentSize = q.size();
		while (currentSize--) {
			int a = q.front().first.first;
			int b = q.front().first.second;
			int d = q.front().second;
			q.pop();

			for (int i = 0; i < 6; i++)
			{
				int nextX = a + XY[i][0];
				int nextY = b + XY[i][1];
				int nextZ = d + XY[i][2];
				if (1 <= nextX && nextX <= c && 1 <= nextY && nextY <= r && 1 <= nextZ && nextZ <= l)
					if (map[nextX][nextY][nextZ] && !visited[nextX][nextY][nextZ]) {
						if (map[nextX][nextY][nextZ] == 2) {
							visited[endX][endY][endZ] = 1;
							return;
						}
						q.push(make_pair(make_pair(nextX, nextY), nextZ));
						visited[nextX][nextY][nextZ] = 1;
					}
			}
		}
		minute++;
	}
}

int main(void)
{
	while (1) {
		scanf("%d %d %d", &l, &r, &c);
		if (!l && !r && !c)
			break;
		for (int i = 1; i <= l; i++)
		{
			for (int j = 1; j <= r; j++)
			{
				for (int k = 1; k <= c; k++)
				{
					char s;
					scanf("%c", &s);
					while (s == '\n')
						scanf("%c", &s);
					if (s == 'S') {
						startX = k;
						startY = j;
						startZ = i;
					} else if (s == '.') {
						map[k][j][i] = 1;
					} else if (s == '#') {
						map[k][j][i] = 0;
					} else if (s == 'E') {
						endX = k;
						endY = j;
						endZ = i;
						map[k][j][i] = 2;
					}
				}
			}
		}

		BFS(startX, startY, startZ);

		if (visited[endX][endY][endZ] != 0)
			printf("Escaped in %d minute(s).\n", minute + 1);
		else
			printf("Trapped!\n");

		memset(visited, 0, sizeof(visited));
		minute = 0;
	}
}