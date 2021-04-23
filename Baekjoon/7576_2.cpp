#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
const int MAX = 1000;
int map[MAX][MAX];

int cnt;

int nR[4] = { 0,0,1,-1 };
int nC[4] = { -1,1,0,0 };
int R, C;

void bfs()
{
	while (!q.empty()) {
		int num = q.size();
		while (num--) {
			int curR = q.front() / 1001;
			int curC = q.front() % 1001;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nextR = curR + nR[i];
				int nextC = curC + nC[i];
				if (nextR < 0 || nextC < 0 || R <= nextR || C <= nextC)
					continue;
				if (!map[nextR][nextC]) {
					map[nextR][nextC] = 1;
					q.push(1001 * nextR + nextC);
				}
			}
		}
		cnt++;
	}
}

int main()
{
	scanf("%d %d", &C, &R);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				q.push(1001 * i + j);
		}
	}

	bfs();

	bool possible = true;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 0)
				possible = false;
		}
	}
	if (possible)
		printf("%d", cnt - 1);
	else
		printf("-1");
}